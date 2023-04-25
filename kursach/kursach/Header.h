#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


struct  stab {

    char mark[12];

    int KPD; //(КПД стабилизатора напряжения)
    int Rin; //(Внутреннее сопротивление стабилизатора напряжения)
    int Kst; //(Коэффициент стабилизации)
    int Ksp; //(Коэффициент сглаживания пульсаций)

    struct stab* next;
};

struct stab* vvod(struct  stab*, struct stab*, int*);
void vyvod(struct  stab*);
newdata(struct  stab*, int);
deldata(struct  stab*, int);
correct(struct  stab* head, int n);
finddata(struct  stab* head, int n);
procdata(struct  stab* head);
fvvod(struct  stab* head);
struct  stab* fvivod(struct  stab* head, int*);


//---Арифметическое кодирование---
#define MAX_SYMBOLS 256
#define FILE_NAME "input.txt"
#define ENCODED_FILE_NAME "encoded.txt"
#define DECODED_FILE_NAME "decoded.txt"

typedef struct {
    int low_count[MAX_SYMBOLS];
    int high_count[MAX_SYMBOLS];
    int total_count;
} FrequencyTable;

void build_frequency_table(FILE* input_file, FrequencyTable* freq_table);
void encode(FILE* input_file, FILE* encoded_file, FrequencyTable* freq_table);
void decode(FILE* encoded_file, FILE* decoded_file, FrequencyTable* freq_table);
void run_program();
//--------------------------------




//------Сортировка слиянием-------
void mergeSortNum(struct stab** headRef, int* kolvo, int dir);
struct stab* merge(struct stab* a, struct stab* b, int* kolvo, int dir);
void split(struct stab* source, struct stab** frontRef, struct stab** backRef);
void mergeSortNumWrapper(struct stab** headRef, int* kolvo, int dir);
int compareByKPDReverse(struct stab* i1, struct stab* i2);
int compareByKPD(struct stab* i1, struct stab* i2);
//--------------------------------








