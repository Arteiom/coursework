#include "Header.h"


// Количество символов алфавита
#define ALPHABET_SIZE 256

// Всего символов в модели
#define SYMBOLS_COUNT (ALPHABET_SIZE + 1)

// Порог частоты для масштабирования
#define MAX_FREQUENCY_THRESHOLD 16383

// Количество битов в регистре
#define REGISTER_BITS_COUNT 16

// Максимально возможное значение в регистре
#define MAX_REGISTER_VALUE (((long) 1 << REGISTER_BITS_COUNT) - 1)

// 1 четверть, половина диапазона, 3 четверть
#define FIRST_QUARTER (MAX_REGISTER_VALUE / 4 + 1)
#define HALF_RANGE (2 * FIRST_QUARTER)
#define THIRD_QUARTER (3 * FIRST_QUARTER)

// Специальный символ Конец Файла
#define EOF_SYMBOL (ALPHABET_SIZE + 1)

// Обрабатываемые файлы
FILE* input, * output;

// Регистры границ и кода
long lower_bound, upper_bound;
long current_value;

// Частотные таблицы
int cumulative_freq[SYMBOLS_COUNT + 1];
int symbol_freq[SYMBOLS_COUNT + 1];

// Таблицы перекодировки
unsigned char symbol_to_char[SYMBOLS_COUNT];
int char_to_symbol[ALPHABET_SIZE];

// Поддержка побитлвых операций с файлами
long bits_pending_to_follow;
int bit_buffer;
int bits_remaining;
int extra_bits;





// арифметическое кодирование
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


// арифметическое декодирование
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


// Кодирование символа
void encode_symbol(int symbol)
{
    long range;

    // Вычисление текущего масштаба частот
    range = (long)(upper_bound - lower_bound) + 1;

    // Обновление границ кодирования
    upper_bound = lower_bound + (range * cumulative_freq[symbol - 1]) / cumulative_freq[0] - 1;
    lower_bound = lower_bound + (range * cumulative_freq[symbol]) / cumulative_freq[0];

    // Кодирование символа побитово
    for (;;)
    {
        // Если верхняя граница меньше половины диапазона
        if (upper_bound < HALF_RANGE)
            output_bit_with_follow(0);
        // Если нижняя граница больше или равна половине диапазона
        else if (lower_bound >= HALF_RANGE)
        {
            output_bit_with_follow(1);
            lower_bound -= HALF_RANGE;
            upper_bound -= HALF_RANGE;
        }
        // Если нижняя граница больше или равна первой четверти, а верхняя граница меньше третьей четверти
        else if (lower_bound >= FIRST_QUARTER && upper_bound < THIRD_QUARTER)
        {
            bits_pending_to_follow += 1;
            lower_bound -= FIRST_QUARTER;
            upper_bound -= FIRST_QUARTER;
        }
        // Если не выполняются предыдущие условия, выходим из цикла
        else
            break;

        // Сдвиг границ влево и добавление нового бита
        lower_bound = 2 * lower_bound;
        upper_bound = 2 * upper_bound + 1;
    }
}


// Декодирование символа
int decode_symbol()
{
    long range;
    int cum, symbol;

    // Вычисление текущего масштаба частот
    range = (long)(upper_bound - lower_bound) + 1;

    // Вычисление кумулятивного значения
    cum = (int)((((long)(current_value - lower_bound) + 1) * cumulative_freq[0] - 1) / range);

    // Поиск соответствующего символа в таблице частот
    for (symbol = 1; cumulative_freq[symbol] > cum; symbol++);

    // Обновление границ декодирования
    upper_bound = lower_bound + (range * cumulative_freq[symbol - 1]) / cumulative_freq[0] - 1;
    lower_bound = lower_bound + (range * cumulative_freq[symbol]) / cumulative_freq[0];

    // Декодирование символа побитово
    for (;;)
    {
        // Если верхняя граница меньше половины диапазона, не делаем ничего
        if (upper_bound < HALF_RANGE)
        {
        }
        // Если нижняя граница больше или равна половине диапазона
        else if (lower_bound >= HALF_RANGE)
        {
            // Обновление значений границ и текущего значения
            current_value -= HALF_RANGE;
            lower_bound -= HALF_RANGE;
            upper_bound -= HALF_RANGE;
        }
        // Если нижняя граница больше или равна первой четверти, а верхняя граница меньше третьей четверти
        else if (lower_bound >= FIRST_QUARTER && upper_bound < THIRD_QUARTER)
        {
            // Обновление значений границ и текущего значения
            current_value -= FIRST_QUARTER;
            lower_bound -= FIRST_QUARTER;
            upper_bound -= FIRST_QUARTER;
        }
        // Если не выполняются предыдущие условия, выходим из цикла
        else
            break;

        // Сдвиг границ влево и добавление нового бита
        lower_bound = 2 * lower_bound;
        upper_bound = 2 * upper_bound + 1;
        current_value = 2 * current_value + read_bit();
    }

    return symbol;
}



// Инициализация побитового ввода
void initialize_bit_input()
{
    bits_remaining = 0;
    extra_bits = 0;
}

// Инициализация побитового вывода
void initialize_bit_output()
{
    bit_buffer = 0;
    bits_remaining = 8;
}

// Инициализация адаптивной модели сжатия
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

// Инициализация кодирования перед началом сжатия
void start_encoding()
{
    lower_bound = 0l;
    upper_bound = MAX_REGISTER_VALUE;
    bits_pending_to_follow = 0l;
}

// Инициализация декодирования и загрузка начальных значений регистров
void start_decoding()
{
    int i;

    current_value = 0l;
    for (i = 1; i <= REGISTER_BITS_COUNT; i++)
        current_value = 2 * current_value + read_bit();
    lower_bound = 0l;
    upper_bound = MAX_REGISTER_VALUE;
}

// Ввод бита сжатой информации
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
                printf("Ошибка в сжатом файле\n");
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

// Вывод бита сжатой информации
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

// Обновление модели сжатия новым символом
void update_compression_model(int symbol)
{
    int i;
    int ch_i, ch_symbol;
    int cum;

    // проверка на переполнение счетчика частоты
    if (cumulative_freq[0] == MAX_FREQUENCY_THRESHOLD)
    {
        cum = 0;
        // масштабирование частот при переполнении
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

    // обновление значений в таблицах частот
    symbol_freq[i] += 1;
    while (i > 0)
    {
        i -= 1;
        cumulative_freq[i] += 1;
    }
}

// Завершение вывода битового буфера
void finalize_bit_output()
{
    putc(bit_buffer >> bits_remaining, output);
}

// Вывод указанного бита и всех отложенных битов
void output_bit_with_follow(int bit)
{
    write_bit(bit);
    while (bits_pending_to_follow > 0)
    {
        write_bit(!bit);
        bits_pending_to_follow--;
    }
}

// Завершение кодирования
void finalize_encoding()
{
    bits_pending_to_follow++;
    if (lower_bound < FIRST_QUARTER)
        output_bit_with_follow(0);
    else
        output_bit_with_follow(1);
}


