#include "Header.h"
void correct(struct  stab* head, int n) {
    struct  stab* current = NULL;
    int counter = 0, choice, res = 0;
    current = head;
    char ans = 0;


    // ���� ������ � �������� ������� n
    while (counter < (n - 1)) {
        current = current->next;
        counter++;
    }
    printf("��������� ������ ��� �������������\n");
    printf("----------------------------------------------------------------------------------------------------\n|    �����     | ��� ����. ��������. | ����. ����. ��. ���. |   ����. ����.  | ����. ��. �����. |\n----------------------------------------------------------------------------------------------------\n");
    printf("| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);

    while (1) {
        printf("1. ��������� �����.\n2. ��������� ��� ������������� ����������.\n3. ��������� ����������� ������������� ������������� ����������\n4. ��������� ������������ ������������ ������������� ����������\n5. ��������� ������������ ����������� ��������� ������������� ����������\n0. ������������� ��������.\n�������� ������ ������������ ��������:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("������� ����� �������� �����: ");
            res = scanf("%11s", current->mark); 
            while (res != 1 || current->mark <= 0) {
                printf("�������� ����� ������� �� �����, ��������� ����: "); 
                while (getchar() != '\n')  continue; 
                res = scanf("%11s", current->mark); 		
            }
            while (getchar() != '\n')  continue;

            break;
        case 2:
            printf("������� ����� �������� ��� ������������� ����������: ");
            res = scanf("%d", &current->KPD);
            while (res != 1 || current->KPD < 0) {
                printf("�������� ��� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->KPD);
            }
            break;
        case 3:
            printf("������� ����� �������� ����������� ������������� ������������� ���������� : ");
            res = scanf("%d", &current->Rin);
            while (res != 1 || current->Rin < 0) {
                printf("�������� ����������� ������������� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->Rin);
            }
            break;
        case 4:
            printf("������� ����� �������� ������������ ������������ ������������� ����������: ");
            res = scanf("%d", &current->Kst);
            while (res != 1 || current->Kst < 0) {
                printf("�������� ����������� ������������� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->Kst);
            }
            break;
        case 5:
            printf("������� ����� �������� ������������ ����������� ��������� ������������� ����������: ");
            res = scanf("%d", &current->Ksp);
            while (res != 1 || current->Ksp < 0) {
                printf("�������� ����������� ������������� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->Ksp);
            }        
            break;
        case 0: printf("������������� ��������\n");
            while (getchar() != '\n') continue;          
            return;
            break;
        default:
            printf("����� ���� ������ �����������. ���������� ��� ���!!!!\n");
            break;
        }
    }
    while (getchar() != '\n')
        continue;
}