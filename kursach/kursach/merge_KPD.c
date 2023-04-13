#include "Header.h"

int compareByKPDReverse(struct stab* i1, struct stab* i2) {
    if (i1->KPD > i2->KPD) {
        return -1;
    }
    else if (i1->KPD < i2->KPD) {
        return 1;
    }
    else {
        return 0;
    }
}


int compareByKPD(struct stab* i1, struct stab* i2) {
    if (i1->KPD < i2->KPD) {
        return -1;
    }
    else if (i1->KPD > i2->KPD) {
        return 1;
    }
    else {
        return 0;
    }
}


void mergeSortNum(struct stab** headRef, int* kolvo, int dir) {
    struct stab* head = *headRef;
    struct stab* a;
    struct stab* b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    split(head, &a, &b);

    mergeSortNum(&a, kolvo, dir);
    mergeSortNum(&b, kolvo, dir);

    *headRef = merge(a, b, kolvo, dir);
}

struct stab* merge(struct stab* a, struct stab* b, int* kolvo, int dir) {
    struct stab* result = NULL;

    if (a == NULL) {
        return b;
    }
    else if (b == NULL) {
        return a;
    }

    if (dir == 1) {
        if (compareByKPDReverse(a, b) <= 0) {
            result = a;
            result->next = merge(a->next, b, kolvo, dir);
        }
        else {
            result = b;
            result->next = merge(a, b->next, kolvo, dir);
        }
    }
    else {
        if (compareByKPD(a, b) <= 0) {
            result = a;
            result->next = merge(a->next, b, kolvo, dir);
        }
        else {
            result = b;
            result->next = merge(a, b->next, kolvo, dir);
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

void mergeSortNumWrapper(struct stab** headRef, int* kolvo, int dir) {
    printf("Сортировка по числовому полю\n");
    if (*headRef == NULL) {
        printf("Данные не введены\n");
        return;
    }
    if (*kolvo == 1) {
        printf("Сортировка не требуется\n");
        return;
    }
    printf("Выберете направление сортировки:\n1-по убыванию\n2-по возрастанию\n");
    int c = 0;
    while (scanf("%d", &c) != 1 || (c != 1 && c != 2)) {
        printf("Введено неверно повторите\n");
        while (getchar() != '\n') {
            continue;
        }
    }
    mergeSortNum(headRef, kolvo, c);
}
