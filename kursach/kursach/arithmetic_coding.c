#include "Header.h"


// ���������� �������� ��������
#define ALPHABET_SIZE 256

// ����� �������� � ������
#define SYMBOLS_COUNT (ALPHABET_SIZE + 1)

// ����� ������� ��� ���������������
#define MAX_FREQUENCY_THRESHOLD 16383

// ���������� ����� � ��������
#define REGISTER_BITS_COUNT 16

// ����������� ��������� �������� � ��������
#define MAX_REGISTER_VALUE (((long) 1 << REGISTER_BITS_COUNT) - 1)

// 1 ��������, �������� ���������, 3 ��������
#define FIRST_QUARTER (MAX_REGISTER_VALUE / 4 + 1)
#define HALF_RANGE (2 * FIRST_QUARTER)
#define THIRD_QUARTER (3 * FIRST_QUARTER)

// ����������� ������ ����� �����
#define EOF_SYMBOL (ALPHABET_SIZE + 1)

// �������������� �����
FILE* input, * output;

// �������� ������ � ����
long lower_bound, upper_bound;
long current_value;

// ��������� �������
int cumulative_freq[SYMBOLS_COUNT + 1];
int symbol_freq[SYMBOLS_COUNT + 1];

// ������� �������������
unsigned char symbol_to_char[SYMBOLS_COUNT];
int char_to_symbol[ALPHABET_SIZE];

// ��������� ��������� �������� � �������
long bits_pending_to_follow;
int bit_buffer;
int bits_remaining;
int extra_bits;





// �������������� �����������
void perform_encoding(char* input_file, char* output_file)
{
    int ch, symbol;

    input = fopen(input_file, "r+b");
    output = fopen(output_file, "w+b");
    if (input == NULL || output == NULL)
        return;
    initialize_compression_model();
    initialize_bit_output();
    start_encoding();
    for (;;)
    {
        ch = getc(input);
        if (ch == EOF)
            break;
        symbol = char_to_symbol[ch];
        encode_symbol(symbol);
        update_compression_model(symbol);
    }
    encode_symbol(EOF_SYMBOL);
    finalize_encoding();
    finalize_bit_output();
    fclose(input);
    fclose(output);
}


// �������������� �������������
void perform_decoding(char* input_file, char* output_file)
{
    int ch, symbol;

    input = fopen(input_file, "r+b");
    output = fopen(output_file, "w+b");
    if (input == NULL || output == NULL)
        return;
    initialize_compression_model();
    initialize_bit_input();
    start_decoding();
    for (;;)
    {
        symbol = decode_symbol();
        if (symbol == EOF_SYMBOL)
            break;
        ch = symbol_to_char[symbol];
        putc(ch, output);
        update_compression_model(symbol);
    }
    fclose(input);
    fclose(output);
}


// ����������� �������
void encode_symbol(int symbol)
{
    long range;

    // ���������� �������� �������� ������
    range = (long)(upper_bound - lower_bound) + 1;

    // ���������� ������ �����������
    upper_bound = lower_bound + (range * cumulative_freq[symbol - 1]) / cumulative_freq[0] - 1;
    lower_bound = lower_bound + (range * cumulative_freq[symbol]) / cumulative_freq[0];

    // ����������� ������� ��������
    for (;;)
    {
        // ���� ������� ������� ������ �������� ���������
        if (upper_bound < HALF_RANGE)
            output_bit_with_follow(0);
        // ���� ������ ������� ������ ��� ����� �������� ���������
        else if (lower_bound >= HALF_RANGE)
        {
            output_bit_with_follow(1);
            lower_bound -= HALF_RANGE;
            upper_bound -= HALF_RANGE;
        }
        // ���� ������ ������� ������ ��� ����� ������ ��������, � ������� ������� ������ ������� ��������
        else if (lower_bound >= FIRST_QUARTER && upper_bound < THIRD_QUARTER)
        {
            bits_pending_to_follow += 1;
            lower_bound -= FIRST_QUARTER;
            upper_bound -= FIRST_QUARTER;
        }
        // ���� �� ����������� ���������� �������, ������� �� �����
        else
            break;

        // ����� ������ ����� � ���������� ������ ����
        lower_bound = 2 * lower_bound;
        upper_bound = 2 * upper_bound + 1;
    }
}


// ������������� �������
int decode_symbol()
{
    long range;
    int cum, symbol;

    // ���������� �������� �������� ������
    range = (long)(upper_bound - lower_bound) + 1;

    // ���������� ������������� ��������
    cum = (int)((((long)(current_value - lower_bound) + 1) * cumulative_freq[0] - 1) / range);

    // ����� ���������������� ������� � ������� ������
    for (symbol = 1; cumulative_freq[symbol] > cum; symbol++);

    // ���������� ������ �������������
    upper_bound = lower_bound + (range * cumulative_freq[symbol - 1]) / cumulative_freq[0] - 1;
    lower_bound = lower_bound + (range * cumulative_freq[symbol]) / cumulative_freq[0];

    // ������������� ������� ��������
    for (;;)
    {
        // ���� ������� ������� ������ �������� ���������, �� ������ ������
        if (upper_bound < HALF_RANGE)
        {
        }
        // ���� ������ ������� ������ ��� ����� �������� ���������
        else if (lower_bound >= HALF_RANGE)
        {
            // ���������� �������� ������ � �������� ��������
            current_value -= HALF_RANGE;
            lower_bound -= HALF_RANGE;
            upper_bound -= HALF_RANGE;
        }
        // ���� ������ ������� ������ ��� ����� ������ ��������, � ������� ������� ������ ������� ��������
        else if (lower_bound >= FIRST_QUARTER && upper_bound < THIRD_QUARTER)
        {
            // ���������� �������� ������ � �������� ��������
            current_value -= FIRST_QUARTER;
            lower_bound -= FIRST_QUARTER;
            upper_bound -= FIRST_QUARTER;
        }
        // ���� �� ����������� ���������� �������, ������� �� �����
        else
            break;

        // ����� ������ ����� � ���������� ������ ����
        lower_bound = 2 * lower_bound;
        upper_bound = 2 * upper_bound + 1;
        current_value = 2 * current_value + read_bit();
    }

    return symbol;
}



// ������������� ���������� �����
void initialize_bit_input()
{
    bits_remaining = 0;
    extra_bits = 0;
}

// ������������� ���������� ������
void initialize_bit_output()
{
    bit_buffer = 0;
    bits_remaining = 8;
}

// ������������� ���������� ������ ������
void initialize_compression_model()
{
    int i;

    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        char_to_symbol[i] = i + 1;
        symbol_to_char[i + 1] = i;
    }
    for (i = 0; i <= SYMBOLS_COUNT; i++)
    {
        symbol_freq[i] = 1;
        cumulative_freq[i] = SYMBOLS_COUNT - i;
    }
    symbol_freq[0] = 0;
}

// ������������� ����������� ����� ������� ������
void start_encoding()
{
    lower_bound = 0l;
    upper_bound = MAX_REGISTER_VALUE;
    bits_pending_to_follow = 0l;
}

// ������������� ������������� � �������� ��������� �������� ���������
void start_decoding()
{
    int i;

    current_value = 0l;
    for (i = 1; i <= REGISTER_BITS_COUNT; i++)
        current_value = 2 * current_value + read_bit();
    lower_bound = 0l;
    upper_bound = MAX_REGISTER_VALUE;
}

// ���� ���� ������ ����������
int read_bit()
{
    int t;

    if (bits_remaining == 0)
    {
        bit_buffer = getc(input);
        if (bit_buffer == EOF)
        {
            extra_bits += 1;
            if (extra_bits > REGISTER_BITS_COUNT - 2)
            {
                printf("������ � ������ �����\n");
                exit(-1);
            }
        }
        bits_remaining = 8;
    }
    t = bit_buffer & 1;
    bit_buffer >>= 1;
    bits_remaining -= 1;
    return t;
}

// ����� ���� ������ ����������
void write_bit(int bit)
{
    bit_buffer >>= 1;
    if (bit)
        bit_buffer |= 0x80;
    bits_remaining -= 1;
    if (bits_remaining == 0)
    {
        putc(bit_buffer, output);
        bits_remaining = 8;
    }
}

// ���������� ������ ������ ����� ��������
void update_compression_model(int symbol)
{
    int i;
    int ch_i, ch_symbol;
    int cum;

    // �������� �� ������������ �������� �������
    if (cumulative_freq[0] == MAX_FREQUENCY_THRESHOLD)
    {
        cum = 0;
        // ��������������� ������ ��� ������������
        for (i = SYMBOLS_COUNT; i >= 0; i--)
        {
            symbol_freq[i] = (symbol_freq[i] + 1) / 2;
            cumulative_freq[i] = cum;
            cum += symbol_freq[i];
        }
    }

    for (i = symbol; symbol_freq[i] == symbol_freq[i - 1]; i--);
    if (i < symbol)
    {
        ch_i = symbol_to_char[i];
        ch_symbol = symbol_to_char[symbol];
        symbol_to_char[i] = ch_symbol;
        symbol_to_char[symbol] = ch_i;
        char_to_symbol[ch_i] = symbol;
        char_to_symbol[ch_symbol] = i;
    }

    // ���������� �������� � �������� ������
    symbol_freq[i] += 1;
    while (i > 0)
    {
        i -= 1;
        cumulative_freq[i] += 1;
    }
}

// ���������� ������ �������� ������
void finalize_bit_output()
{
    putc(bit_buffer >> bits_remaining, output);
}

// ����� ���������� ���� � ���� ���������� �����
void output_bit_with_follow(int bit)
{
    write_bit(bit);
    while (bits_pending_to_follow > 0)
    {
        write_bit(!bit);
        bits_pending_to_follow--;
    }
}

// ���������� �����������
void finalize_encoding()
{
    bits_pending_to_follow++;
    if (lower_bound < FIRST_QUARTER)
        output_bit_with_follow(0);
    else
        output_bit_with_follow(1);
}


