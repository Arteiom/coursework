#include "Header.h"



void build_frequency_table(FILE* input_file, FrequencyTable* freq_table) {
    int i, c;
    while ((c = fgetc(input_file)) != EOF) {
        freq_table->low_count[c]++;
        freq_table->total_count++;
    }
    for (i = 1; i < MAX_SYMBOLS; i++) {
        freq_table->low_count[i] += freq_table->low_count[i - 1];
        freq_table->high_count[i] = freq_table->low_count[i];
    }
}

void encode(FILE* input_file, FILE* encoded_file, FrequencyTable* freq_table) {
    int c, low = 0, high = 0x7fffffff, range = 0x7fffffff;
    while ((c = fgetc(input_file)) != EOF) {
        int range_div_total = range / freq_table->total_count;
        high = low + freq_table->high_count[c] * range_div_total - 1;
        low = low + freq_table->low_count[c] * range_div_total;
        while ((high ^ low) < 0x80000000) {
            fputc(high >> 24, encoded_file);
            high = (high << 8) | 0xff;
            low = low << 8;
        }
    }
    fputc(low >> 24, encoded_file);
}

void decode(FILE* encoded_file, FILE* decoded_file, FrequencyTable* freq_table) {
    int c, value = 0, low = 0, high = 0x7fffffff, range = 0x7fffffff;
    int i, j;
    for (i = 0; i < 4; i++) {
        value = (value << 8) | fgetc(encoded_file);
    }
    while (1) {
        if (ferror(encoded_file) || ferror(decoded_file)) {
            fprintf(stderr, "ошибка файла \n");
            exit(EXIT_FAILURE);
        }

        int range_div_total = range / freq_table->total_count;
        int symbol = 0;
        for (i = 0, j = freq_table->low_count[symbol] * range_div_total; j <= value; i++, j = freq_table->low_count[symbol] * range_div_total) {
            symbol++;
        }

        if (symbol == EOF) {
            break;
        }

        fputc(symbol, decoded_file);

        high = low + freq_table->high_count[symbol] * range_div_total - 1;
        low = low + freq_table->low_count[symbol] * range_div_total;

        while ((high ^ low) < 0x80000000) {
            value = (value << 8);
            int c = fgetc(encoded_file);
            if (c == EOF) {
                break;
            }
            value |= c;
            high = (high << 8) | 0xff;
            low = low << 8;
        }

        if (feof(encoded_file)) {
            break;
        }
    }

}
void run_program() {
    FILE* input_file, * encoded_file, * decoded_file;
    FrequencyTable freq_table = { {0}, {0}, 0 };

    input_file = fopen(FILE_NAME, "rb");
    if (!input_file) {
        fprintf(stderr, "не удалось открыть входной файл %s\n", FILE_NAME);
        exit(1);
    }

    build_frequency_table(input_file, &freq_table);
    input_file = fopen(FILE_NAME, "rb");
    if (!input_file) {
        fprintf(stderr, "не удалось открыть входной файл %s\n", FILE_NAME);
        exit(1);
    }
    encoded_file = fopen(ENCODED_FILE_NAME, "wb");
    if (!encoded_file) {
        fprintf(stderr, "не удалось открыть закодированный файл %s\n", ENCODED_FILE_NAME);
        exit(1);
    }

    encode(input_file, encoded_file, &freq_table);



    fclose(input_file);
    fclose(encoded_file);

    encoded_file = fopen(ENCODED_FILE_NAME, "rb");
    if (!encoded_file) {
        fprintf(stderr, "не удалось открыть закодированный файл %s\n", ENCODED_FILE_NAME);
        exit(1);
    }

    decoded_file = fopen(DECODED_FILE_NAME, "wb");
    if (!decoded_file) {
        fprintf(stderr, "не удалось открыть декодированный файл %s\n", DECODED_FILE_NAME);
        exit(1);
    }

    decode(encoded_file, decoded_file, &freq_table);

    fclose(encoded_file);
    fclose(decoded_file);

    printf("Кодирование и декодирование успешно завершены\n");
}