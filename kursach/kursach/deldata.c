#include "Header.h"
deldata(struct  stab* head, int n) {
	// ��������� ��������� �� ������� ������� � ���������� ������� ��������� stab
	struct  stab* current = NULL, * prev = NULL;
	// �������� ������ ��� ����� ��������� stab
	struct stab* new = (struct stab*)malloc(sizeof(struct stab));

	// �������������� ������� � ������� �������
	int counter = 0;
	current = head;

	// ���� �������, ������� ����� �������
	while (counter < (n - 1)) {
		prev = current;
		current = current->next;
		counter++;
	}

	// ������� ��������� ������� � ����������� ������
	prev->next = current->next;
	free(current);

	printf("������ �������");
	while (getchar() != '\n')
		continue;
}


