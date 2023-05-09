#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define FILE_NAME "input.txt"

struct  stab {

    char mark[12];

    int KPD; //(КПД стабилизатора напряжения)
    int Rin; //(Внутреннее сопротивление стабилизатора напряжения)
    int Kst; //(Коэффициент стабилизации)
    int Ksp; //(Коэффициент сглаживания пульсаций)

    struct stab* next;
};

struct stab* vvod(struct stab* head, struct stab** tail, int* count1);
void vyvod(struct  stab*);
void newdata(struct  stab*, int);
void deldata(struct  stab*, int);
void correct(struct  stab* head, int n);
void finddata(struct  stab* head, int n);
void procdata(struct  stab* head);
void fvvod(struct  stab* head);
struct  stab* fvivod(struct  stab* head, int*);


//------Сортировка слиянием-------
void mergeSortNum(struct stab** headRef, int* kolvo, int dir);
struct stab* merge(struct stab* a, struct stab* b, int* kolvo, int dir);
void split(struct stab* source, struct stab** frontRef, struct stab** backRef);
void mergeSortNumWrapper(struct stab** headRef, int* kolvo, int dir);
int compareByKPDReverse(struct stab* i1, struct stab* i2);
int compareByKPD(struct stab* i1, struct stab* i2);

void mergeSortStr(struct stab** headRef, int* kolvo, int dir);
struct stab* merge2(struct stab* a, struct stab* b, int* kolvo, int dir);
void split2(struct stab* source, struct stab** frontRef, struct stab** backRef);
void mergeSortMarkWrapper(struct stab** headRef, int* kolvo, int dir);
int compareByMarkReverse(struct stab* i1, struct stab* i2);
int compareByMark(struct stab* i1, struct stab* i2);
//--------------------------------


//----------Арифметическое кодироование-------------
void start_model(void);
void update_model(int symbol);
void start_inputing_bits(void);
int input_bit(void);
void start_outputing_bits(void);
void output_bit(int bit);
void done_outputing_bits(void);
void output_bit_plus_follow(int bit);
void start_encoding(void);
void done_encoding(void);
void start_decoding(void);
void encode_symbol(int symbol);
int decode_symbol(void);
void encode(char* infile, char* outfile);
void decode(char* infile, char* outfile);
//---------------------------------------------------