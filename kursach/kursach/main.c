#include "Header.h"


int main(void) {

    struct  stab* head = NULL, * tail = NULL;
    int i = 0, k = 0, n, Result = 0, count = 0;
    unsigned char ans = 0;

    int dir = 1;

    system("chcp 1251>nul");
    while (1) {
        printf("�. �������� ����������� � ������ (���� ������).\n�. ����� ����������� �� �����.\n�. ���������� ������ ����� ������ � ��������� ������� \n�. �������� ������ � ��������� �������\n�. ������������� ������ � ��������� �������\n�. ����� ������ �� ������ ���������� ������������� ����\n�. ���������� �������� �� ���������� ���� Mark\n�. ���������� �������� �� ������ ���������� ������������� ��������� ����\n�. ��������� �������� � ����� ����������\n�. ���������� ����������� � ����.\n�. �������� ����������� �� �����.\n0. ����� �� ���������.\n�������� ����� ������������ ��������:");

        scanf("%c", &ans);
        while (getchar() != '\n')  continue;
        while (ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '�' && ans != '0') {
            printf("��������� ����: ");
            scanf("%c", &ans);
            while (getchar() != '\n')  continue;
        }

        switch (ans) {
        case '�':
            head = vvod(head, &tail, &count);
            break;

        case '�':
            vyvod(head);
            break;
        case '�':
            printf("������� ����� ������ ����� ������� ���������� �������� ����� �������: ");
            Result = scanf("%d", &n);
            while (Result != 1 || n < 0 || n > count) {
                printf("�������� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                Result = scanf("%d", &n);               
            }
            newdata(head, n);
            break;
        case '�':
            printf("������� ����� ������ ������� ���������� �������: ");
            Result = scanf("%d", &n);
            while (Result != 1 || n < 0 || n > count) {
                printf("�������� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                Result = scanf("%d", &n);          
            }
            deldata(head, n);
            break;
        case '�':
            printf("������� ����� ������ ������� ���������� ����������������: ");
            Result = scanf("%d", &n);
            while (Result != 1 || n < 0 || n > count) {
                printf("�������� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                Result = scanf("%d", &n);    
            }
            correct(head, n); 
            break;
        case '�':
            printf("������� ����� ����, �� �������� ���������� ���������� �����: ");
            Result = scanf("%d", &n);
            while (Result != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                while (getchar() != '\n')  continue;
                Result = scanf("%d", &n);             
            }
            finddata(head, n);
            break;
        case '�':
            mergeSortMarkWrapper(&head, &count, dir);
            break;
        case '�':
         
            mergeSortNumWrapper(&head, &count);
            break;
        case '�':
            perform_encoding(FILE_NAME, "encoded.txt");
            perform_decoding("encoded.txt", "decoded.txt");    
            break;
        case '�':
            fvvod(head);
            break;
        case '�':
            head = fvivod(head, &count);
            break;
        case '0': printf("����� �� ���������");
            return 0;
            break;
        default:
            printf("����� ���� ������ �����������. ���������� ��� ���!!!!\n");
            break;

        }
    }
    return 0;
}
