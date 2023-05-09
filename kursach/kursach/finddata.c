#include "Header.h"
void finddata(struct  stab* head, int n) {
    struct  stab* current = NULL;
    int i = 0, findd = 0;

    // ���������� ��� ��������� ����� � ��������� ����
    int numb = 0;
    char str[12];

    current = head;
    switch (n) {
    case 1:
        printf("�������, ��� ���������� �����: ");
        scanf("%s", str);

        while (current != NULL) {
            if ((strcoll(current->mark, str)) == 0) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) { 
            printf("%s � ������ ������������� ���������� �� �������\n", str);
        }
        break;
    case 2:
        printf("�������, ��� ���������� �����: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->KPD == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d � ��� ������������� ���������� �� �������\n", numb);
        }
        break;
    case 3:
        printf("�������, ��� ���������� �����: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->Rin == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d � ���������� ������������� ������������� ���������� �� �������\n", numb);
        }
        break;
    case 4:
        printf("�������, ��� ���������� �����: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->Kst == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d � ������������ ������������ ������������� ���������� �� �������\n", numb);
        }
        break;
    case 5:
        printf("�������, ��� ���������� �����: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->Ksp == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d � ������������ ����������� ��������� ������������� ���������� �� �������\n", numb);
        }
        break;
    default:
        printf("����� ���� ������ �����������. ���������� ��� ���!!!!\n");
        break;
    }
    while (getchar() != '\n')
        continue;
}