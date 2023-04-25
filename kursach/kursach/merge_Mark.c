







































































//#include "Header.h"
//
//int compareByMark(struct stab* i1, struct stab* i2) {
//    return strcmp(i2->mark, i1->mark);
//}
//
//
//
//void mergeSort(struct stab** headRef, int* kolvo, int dir, int (*compareByMark)(struct stab*, struct stab*)) {
//    struct stab* head = *headRef;
//    struct stab* a;
//    struct stab* b;
//
//    if ((head == NULL) || (head->next == NULL)) {
//        return;
//    }
//
//    split2(head, &a, &b);
//
//    mergeSort(&a, kolvo, dir, compareByMark);
//    mergeSort(&b, kolvo, dir, compareByMark);
//
//    *headRef = merge2(a, b, kolvo, dir, compareByMark);
//}
//
//struct stab* merge2(struct stab* a, struct stab* b, int* kolvo, int dir, int (*compareFunc)(struct stab*, struct stab*)) {
//    struct stab* result = NULL;
//
//    if (a == NULL) {
//        return b;
//    }
//    else if (b == NULL) {
//        return a;
//    }
//
//    if (dir == 1) {
//        if (compareFunc(a, b) >= 0) {
//            result = a;
//            result->next = merge2(a->next, b, kolvo, dir, compareFunc);
//        }
//        else {
//            result = b;
//            result->next = merge2(a, b->next, kolvo, dir, compareFunc);
//        }
//    }
//    else {
//        if (compareFunc(a, b) <= 0) {
//            result = a;
//            result->next = merge2(a->next, b, kolvo, dir, compareFunc);
//        }
//        else {
//            result = b;
//            result->next = merge2(a, b->next, kolvo, dir, compareFunc);
//        }
//    }
//    return result;
//}
//
//void split2(struct stab* source, struct stab** frontRef, struct stab** backRef) {
//    struct stab* fast;
//    struct stab* slow;
//    slow = source;
//    fast = source->next;
//
//    while (fast != NULL) {
//        fast = fast->next;
//        if (fast != NULL) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//    }
//
//    *frontRef = source;
//    *backRef = slow->next;
//    slow->next = NULL;
//}
//
//
//void mergeSortMarkWrapper(struct stab** headRef, int* kolvo, int dir) {
//    printf("���������� �� ���������� ���� mark\n");
//    if (*headRef == NULL) {
//        printf("������ �� �������\n");
//        return;
//    }
//    if (*kolvo == 1) {
//        printf("���������� �� ���������\n");
//        return;
//    }
//    printf("�������� ����������� ����������:\n1-�� ��������\n2-�� �����������\n");
//    int c = 0;
//    while (scanf("%d", &c) != 1 || (c != 1 && c != 2)) {
//        printf("������� ������� ���������\n");
//        while (getchar() != '\n') {
//            continue;
//        }
//    }
//    mergeSort(headRef, kolvo, dir, compareByMark);
//}
