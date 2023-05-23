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
void fvvod(struct  stab* head);
struct  stab* fvivod(struct  stab* head, int*);


//----------Арифметическое кодироование-------------
void initialize_compression_model();
void update_compression_model(int symbol);
void initialize_bit_input();
int read_bit();
void initialize_bit_output();
void write_bit(int bit);
void finalize_bit_output();
void output_bit_with_follow(int bit);
void start_encoding();
void finalize_encoding();
void start_decoding();
void encode_symbol(int symbol);
int decode_symbol();
void perform_encoding(char* infile, char* outfile);
void perform_decoding(char* infile, char* outfile);
//---------------------------------------------------


//------Сортировка слиянием-------
void mergeSortNum(struct stab** headRef, int* kolvo, int field, int dir);
struct stab* merge(struct stab* a, struct stab* b, int* kolvo, int field, int dir);
void split(struct stab* source, struct stab** frontRef, struct stab** backRef);
void mergeSortNumWrapper(struct stab** headRef, int* kolvo);
int compareByField(struct stab* i1, struct stab* i2, int field, int dir);



void mergeSortStr(struct stab** headRef, int* kolvo, int dir);
struct stab* merge2(struct stab* a, struct stab* b, int* kolvo, int dir);
void split2(struct stab* source, struct stab** frontRef, struct stab** backRef);
void mergeSortMarkWrapper(struct stab** headRef, int* kolvo, int dir);
int compareByMarkReverse(struct stab* i1, struct stab* i2);
int compareByMark(struct stab* i1, struct stab* i2);
//--------------------------------


