#include "Header.h"

int main(void) {
    struct  stab* head = NULL, * tail = NULL;
    int i = 0, k = 0, n, res = 0, count = 0;
    unsigned char ans = 0;

    setlocale(LC_ALL, "RU");
    while (1) {
        printf("�. �������� ����������� � ������ (���� ������).\n�. ����� ����������� �� �����.\n�. ���������� ������ ����� ������ � ��������� ������� \n�. �������� ������ � ��������� �������\n�. ������������� ������ � ��������� �������\n�. ����� ������ �� ������ ���������� ������������� ����\n�. ���������� ��������� �� ���������� ����\n�. ���������� ��������� �� ��������� ����\n�. ��������� �������� � ����� ����������\n�. ���������� ����������� � ����.\n�. �������� ����������� �� �����.\n0. ����� �� ���������.\n�������� ����� ������������ ��������:");

        scanf("%c", &ans);
        while (getchar() != '\n')  continue;
        while (ans != 160 && ans != 161 && ans != 162 && ans != 163 && ans != 164 && ans != 165 && ans != 166 && ans != 167 && ans != 168 && ans != 170 && ans != 171 && ans != 48) {
            printf("��������� ����: ");
            scanf("%c", &ans);
            while (getchar() != '\n')  continue;
        }

        switch (ans) {
        case 160:
            head = vvod(head, &tail, &count);
            break;

        case 161:
            vyvod(head);
            break;
        case 162:
            printf("������� ����� ������ ����� ������� ���������� �������� ����� �������: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            newdata(head, n);
            break;
        case 163:
            printf("������� ����� ������ ������� ���������� �������: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            deldata(head, n);
            break;
        case 164:
            printf("������� ����� ������ ������� ���������� ����������������: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            correct(head, n); 
            break;
        case 165:
            printf("������� ����� ����, �� �������� ���������� ���������� �����: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("�������� ������� �� �����, ��������� ����: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            finddata(head, n);
            break;
        case 166:
            // ���������� �� ��������� ����

            break;

        case 167:
            // ���������� �� ��������� ����


            break;
        case 168:
            // ��������� �������� � ����� ����������

            break;
        case 170:
            fvvod(head);
            break;
        case 171:
            head = fvivod(head, &count);
            break;
        case 48: printf("����� �� ���������");
            return 0;
            break;
        default:
            printf("����� ���� ������ �����������. ���������� ��� ���!!!!\n");
            break;

        }
    }
    return 0;
}
