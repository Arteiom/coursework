#include "Header.h"
deldata(struct  stab* head, int n) {
	// Объявляем указатели на текущий элемент и предыдущий элемент структуры stab
	struct  stab* current = NULL, * prev = NULL;
	// Выделяем память для новой структуры stab
	struct stab* new = (struct stab*)malloc(sizeof(struct stab));

	// Инициализируем счетчик и текущий элемент
	int counter = 0;
	current = head;

	// Ищем элемент, который нужно удалить
	while (counter < (n - 1)) {
		prev = current;
		current = current->next;
		counter++;
	}

	// Удаляем найденный элемент и освобождаем память
	prev->next = current->next;
	free(current);

	printf("Запись удалена");
	while (getchar() != '\n')
		continue;
}


