#include "Header.h"
struct stab* vvod(struct stab* head, struct stab ** tail, int* count1) {
	char choice;
	int i, count = 0, res = 0;
	struct stab* prev = NULL, * current = NULL;

	// ���� ������ ������ �� NULL, �� ���������� � ������������, 
	// ����� �� �� ������� ����� ������ ��� �������� � ������
	if (head != NULL) {
		while (1) {
			printf("������� ����� ������� ��� ���������� � ������? (N- new, O- old)");
			choice = toupper(getchar());
			if (choice == 'N') {
				// ���� ������������ ������ �������� ������ ������, 
				// �� ������� ������ ������ � �������� ������
				count = 0;
				current = head;
				while (current != NULL) {
					prev = current->next;
					free(current);
					current = prev;
				}
				head = NULL;
			}
			if (choice == 'O') {
				// ���� ������������ ������ ����������� � ������ ������,
				// �� ������� ���������� ��������� � ������
				count = 0;
				current = head;
				while (current != NULL) {
					prev = current;
					current = current->next;
					count++;
				}
			}
			if (choice != 'N' && choice != 'O') {
				// ���� ������������ ���� ���-�� ����������, �� ���������� ��� �������
				while (getchar() != '\n')
					continue;
				continue;
			}
			while (getchar() != '\n')
				continue;
			break;
		}
	}

	// ����������� � ������������ ������ ��� ����� ��������� ������
	for (; ; count++) {
		current = (struct stab*)malloc(sizeof(struct stab));
		if (head == NULL)
			head = current;
		else {
			// ��������� ������� � ����� ������
			prev->next = current;
		}
		current->next = NULL;



		printf("������� ����� %d �������������: ", count + 1); // ������� ��������� ��� ����� ����� �������������
		res = scanf("%s", current->mark); // ��������� ��������� ����� ������������� � ��������� � ��������� current
		while (res != 1 || current->mark <= 0) { // ���������, ��� ��������� �������� ���������
			printf("�������� ������� �� �����, ��������� ����: "); // ���� �������� �����������, ������� ��������� �� ������
			res = scanf("%s", current->mark); // �������� ��������� �������� �����
			while (getchar() != '\n')  continue; // ������� ����� �����
		}

		// ���������� ��� ��������� ����� ��������� current: ���, ���������� �������������, ����������� ������������, ����������� ����������� ���������
		printf("������� ��� %d ������������� ����������: ", count + 1);
		res = scanf("%d", &current->KPD);
		while (res != 1 || current->KPD < 0) {
			printf("�������� ������� �� �����, ��������� ����: ");
			res = scanf("%d", &current->KPD);
			while (getchar() != '\n')  continue;
		}

		printf("������� ���������� ������������� %d ������������� ����������: ", count + 1);
		res = scanf("%d", &current->Rin);
		while (res != 1 || current->Rin < 0) {
			printf("�������� ������� �� �����, ��������� ����: ");
			res = scanf("%d", &current->Rin);
			while (getchar() != '\n')  continue;
		}

		printf("������� ����������� ������������ %d ������������� ����������: ", count + 1);
		res = scanf("%d", &current->Kst);
		while (res != 1 || current->Kst < 0) {
			printf("�������� ������� �� �����, ��������� ����: ");
			res = scanf("%d", &current->Kst);
			while (getchar() != '\n')  continue;
		}

		printf("������� ����������� ����������� ��������� %d ������������� ����������: ", count + 1);
		res = scanf("%d", &current->Ksp);
		while (res != 1 || current->Ksp < 0) {
			printf("�������� ������� �� �����, ��������� ����: ");
			res = scanf("%d", &current->Ksp);
			while (getchar() != '\n')  continue;
		}

		while (getchar() != '\n')  continue; // ������� ����� �����

		// ��������� ������� ������� � �������� ����������� � ��������� ����� ������
		prev = current;
		*tail = current;

		char vibor = 0;
		printf("��������� ����? (y/n): ");
		scanf("%c", &vibor);
		while (getchar() != '\n')  continue;
		while (toupper(vibor) != 'Y' && toupper(vibor) != 'N') {
			printf("��������� ����: ");
			scanf("%c", &vibor);
			while (getchar() != '\n')  continue;
		}

		switch (toupper(vibor)) {
		case 'Y':
			// ��������� ���������� ��������� � ���������� count1 � ���������� ��������� �� ������ ������
			*count1 = count;
			return head;
		case 'N':
			// ����� ���������� ���� ��� � ���������� ��������� ����� �������� � ������
			break;
		}

	}
	while (getchar() != '\n')
		continue;

	return head;
}