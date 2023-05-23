#include "Header.h"

int compareByField(struct stab* i1, struct stab* i2, int field, int dir) {
    switch (field) {
    case 1: 
        if (dir == 1) {
            return i1->KPD > i2->KPD ? -1 : (i1->KPD < i2->KPD ? 1 : 0);
        }
        else {
            return i1->KPD < i2->KPD ? -1 : (i1->KPD > i2->KPD ? 1 : 0);
        }
    case 2:  
        if (dir == 1) {
            return i1->Rin > i2->Rin ? -1 : (i1->Rin < i2->Rin ? 1 : 0);
        }
        else {
            return i1->Rin < i2->Rin ? -1 : (i1->Rin > i2->Rin ? 1 : 0);
        }
        break;
    case 3:  
        if (dir == 1) {
            return i1->Kst > i2->Kst ? -1 : (i1->Kst < i2->Kst ? 1 : 0);
        }
        else {
            return i1->Kst < i2->Kst ? -1 : (i1->Kst > i2->Kst ? 1 : 0);
        }
        break;
    case 4:  
        if (dir == 1) {
            return i1->Ksp > i2->Ksp ? -1 : (i1->Ksp < i2->Ksp ? 1 : 0);
        }
        else {
            return i1->Ksp < i2->Ksp ? -1 : (i1->Ksp > i2->Ksp ? 1 : 0);
        }
        break;
    default:
        break;
    }
}



void mergeSortNumWrapper(struct stab** headRef, int* kolvo) {
    printf("Сортировка по числовому полю\n");
    if (*headRef == NULL) {
        printf("Данные не введены\n");
        return;
    }
    if (*kolvo == 1) {
        printf("Сортировка не требуется\n");
        return;
    }

    printf("Выберете поле для сортировки:\n");
    printf("1. KPD\n");
    printf("2. Rin\n");
    printf("3. Kst\n");
    printf("4. Ksp\n");

    int field = 0;
    while (scanf("%d", &field) != 1 || field < 1 || field > 4) {
        printf("Значение введено неверно, повторите ввод\n");
        while (getchar() != '\n') {
            continue;
        }
    }

    printf("Выберете направление сортировки:\n");
    printf("1. По убыванию\n");
    printf("2. По возрастанию\n");

    int dir = 0;
    while (scanf("%d", &dir) != 1 || (dir != 1 && dir != 2)) {
        printf("Значение введено неверно, повторите ввод\n");
        while (getchar() != '\n') {
            continue;
        }
    }

    mergeSortNum(headRef, kolvo, field, dir);
    while (getchar() != '\n') {
        continue;
    }
}

void mergeSortNum(struct stab** headRef, int* kolvo, int field, int dir) {
    struct stab* head = *headRef;
    struct stab* a;
    struct stab* b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    split(head, &a, &b);

    mergeSortNum(&a, kolvo, field, dir);
    mergeSortNum(&b, kolvo, field, dir);

    *headRef = merge(a, b, kolvo, field, dir);
}

struct stab* merge(struct stab* a, struct stab* b, int* kolvo, int field, int dir) {
    struct stab* result = NULL;

    if (a == NULL) {
        return b;
    }
    else if (b == NULL) {
        return a;
    }

    if (dir == 1) {
        if (compareByField(a, b, field, dir) <= 0) {
            result = a;
            result->next = merge(a->next, b, kolvo, field, dir);
        }
        else {
            result = b;
            result->next = merge(a, b->next, kolvo, field, dir);
        }
    }
    else {
        if (compareByField(a, b, field, dir) <= 0) {
            result = a;
            result->next = merge(a->next, b, kolvo, field, dir);
        }
        else {
            result = b;
            result->next = merge(a, b->next, kolvo, field, dir);
        }
    }
    return result;
}

void split(struct stab* source, struct stab** frontRef, struct stab** backRef) {
    struct stab* fast;
    struct stab* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}