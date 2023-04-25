#include "Header.h"


int main(void) {

    #define ALPHABET_SIZE 256
    #define MAX_FILENAME_LENGTH 256

    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    struct  stab* head = NULL, * tail = NULL;
    int i = 0, k = 0, n, res = 0, count = 0;
    unsigned char ans = 0;

    int dir = 1;

    system("chcp 1251>nul");
    while (1) {
        printf("�. �������� ����������� � ������ (���� ������).\n�. ����� ����������� �� �����.\n�. ���������� ������ ����� ������ � ��������� ������� \n�. �������� ������ � ��������� �������\n�. ������������� ������ � ��������� �������\n�. ����� ������ �� ������ ���������� ������������� ����\n�. ���������� �������� �� ���������� ����\n�. ���������� �������� �� ��������� ����\n�. ��������� �������� � ����� ����������\n�. ���������� ����������� � ����.\n�. �������� ����������� �� �����.\n0. ����� �� ���������.\n�������� ����� ������������ ��������:");

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
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            newdata(head, n);
            break;
        case '�':
            printf("������� ����� ������ ������� ���������� �������: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            deldata(head, n);
            break;
        case '�':
            printf("������� ����� ������ ������� ���������� ����������������: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            correct(head, n); 
            break;
        case '�':
            printf("������� ����� ����, �� �������� ���������� ���������� �����: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            finddata(head, n);
            break;
        case '�':

            break;

        case '�':
            mergeSortNumWrapper(&head, &count, dir);
            break;

        case '�':
            
            run_program();
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
