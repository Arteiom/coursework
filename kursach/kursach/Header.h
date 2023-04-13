#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
struct  stab {
    char mark[12]; 

    int KPD; //(КПД стабилизатора напряжения)
    char KPDbin[13];
    int Rin; //(Внутреннее сопротивление стабилизатора напряжения)
    char Rinbin[13];
    int Kst; //(Коэффициент стабилизации)
    char Kstbin[13];
    int Ksp; //(Коэффициент сглаживания пульсаций)
    char Kspbin[13];
    struct stab* next;
    struct stab* back;
};
struct stab * vvod(struct  stab *, struct stab *, int *);
void vyvod(struct  stab *);
newdata(struct  stab *, int);
deldata(struct  stab *, int);


//Сортировка слиянием
void mergeSortNum(struct stab** headRef, int* kolvo, int dir);
struct stab* merge(struct stab* a, struct stab* b, int* kolvo, int dir);
void split(struct stab* source, struct stab** frontRef, struct stab** backRef);
void mergeSortNumWrapper(struct stab** headRef, int* kolvo, int dir);
int compareByKPDReverse(struct stab* i1, struct stab* i2);
int compareByKPD(struct stab* i1, struct stab* i2);



correct(struct  stab* head, int n);
finddata(struct  stab* head, int n);
procdata(struct  stab* head);

fvvod(struct  stab* head);
struct  stab* fvivod(struct  stab* head, int*);


void swap(struct stab*, struct stab*);