#include "Header.h" 
fvvod(struct  stab* head) {
    // ���������� ��������� �� ������� ������� ������ � ���������� ��� �������� ���������� ���������
    struct  stab* current = NULL;
    int i = 0;

    current = head;
    FILE* fl;

    // ����, ������� ������� ���������� ��������� � ������
    while (current != NULL) {
        current = current->next;
        i++;
    }
    current = head;

    // �������� ����� ��� ������, ���� ���� �� ����������, �� �� ����� ������
    fl = fopen("VVOD.txt", "w");
    fprintf(fl, "%d\n", i);

    // ����, ������� ���������� �������� ����� ������ ��������� ������ � ����
    while (current != NULL) {
        fprintf(fl, "%s\n", current->mark);
        fprintf(fl, "%d\n", current->KPD);
        fprintf(fl, "%d\n", current->Rin);
        fprintf(fl, "%d\n", current->Kst);
        fprintf(fl, "%d\n", current->Ksp);
        current = current->next;
    }
    fclose(fl);
}