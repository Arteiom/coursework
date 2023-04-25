#include "Header.h" 


struct stab* fvivod(struct stab* head, int* count1) {
    // ���������� ���������� �� ������� � ���������� �������� ������ � ���������� ��� ������ �� �����
    struct stab* current = NULL, * prev = NULL;
    int count;
    // �������� ����� ��� ������
    FILE* fl = fopen(FILE_NAME, "r");

    // ������ ���������� ��������� �� �����
    fscanf(fl, "%d", &count);
    // ����, ������� ������� ��������� � ��������� �� ���� ���������� �� �����
    for (int i = 0; i < count; i++) {
        // ��������� ������ ��� ������� ���������
        current = (struct stab*)malloc(sizeof(struct stab));

        // ���� ������ ������ �����, �� ������� ��������� ���������� �������
        if (head == NULL)
            head = current;
        // ����� ������� ��������� ���������� ��������� ����� ����������
        else
            prev->next = current;

        // ��������� ������� ����� �������� - NULL, �.�. ������� ��������� ��������� � ������
        current->next = NULL;
        // ������ �������� ����� ������� ��������� �� �����
        fscanf(fl, "%s", current->mark);
        fscanf(fl, "%d", &current->KPD);
        fscanf(fl, "%d", &current->Rin);
        fscanf(fl, "%d", &current->Kst);
        fscanf(fl, "%d", &current->Ksp);
        // ������������ ��������� prev �� ������� ���������
        prev = current;
    }
    // ������ �������� count � ���������� count1 ����� ��������� �� ���
    *count1 = count;

    // �������� �����
    fclose(fl);
   
    // ������� ��������� �� ������ ������
    return head;
}
