#include "Header.h"
struct stab* vvod(struct stab* head, struct stab ** tail, int* count1) {
	char choice;
	int i, count = 0, res = 0;
	struct stab* prev = NULL, * current = NULL;

	// если голова списка не NULL, то спрашиваем у пользователя, 
	// хочет ли он создать новый список или дописать в старый
	if (head != NULL) {
		while (1) {
			printf("Создать новую таблицу или дописывать в старую? (N- new, O- old)");
			choice = toupper(getchar());
			if (choice == 'N') {
				// если пользователь выбрал создание нового списка, 
				// то удаляем старый список и обнуляем голову
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
				// если пользователь выбрал дописывание в старый список,
				// то считаем количество элементов в списке
				count = 0;
				current = head;
				while (current != NULL) {
					prev = current;
					current = current->next;
					count++;
				}
			}
			if (choice != 'N' && choice != 'O') {
				// если пользователь ввел что-то непонятное, то пропускаем все символы
				while (getchar() != '\n')
					continue;
				continue;
			}
			while (getchar() != '\n')
				continue;
			break;
		}
	}

	// запрашиваем у пользователя данные для новых элементов списка
	for (; ; count++) {
		current = (struct stab*)malloc(sizeof(struct stab));
		if (head == NULL)
			head = current;
		else {
			// вставляем элемент в конец списка
			prev->next = current;
		}
		current->next = NULL;



		printf("Введите марку %d стабилизатора: ", count + 1); // выводим сообщение для ввода марки стабилизатора
		res = scanf("%11s", current->mark); // считываем введенную марку стабилизатора и сохраняем в структуре current
		while (res != 1 || current->mark <= 0) { // проверяем, что введенное значение корректно
			printf("Значение марки введено не верно, повторите ввод: "); // если значение некорректно, выводим сообщение об ошибке
			while (getchar() != '\n')  continue; // очищаем буфер ввода
			res = scanf("%11s", current->mark); // повторно считываем значение марки			
		}
		while (getchar() != '\n')  continue; 


		// аналогично для следующих полей структуры current: КПД, внутреннее сопротивление, коэффициент стабилизации, коэффициент сглаживания пульсаций
		printf("Введите КПД %d стабилизатора напряжения: ", count + 1);
		res = scanf("%d", &current->KPD);
		while (res != 1 || current->KPD < 0) {
			printf("Значение КПД введено не верно, повторите ввод: ");
			while (getchar() != '\n')  continue;
			res = scanf("%d", &current->KPD);		
		}

		printf("Введите внутреннее сопротивление %d стабилизатора напряжения: ", count + 1);
		res = scanf("%d", &current->Rin);
		while (res != 1 || current->Rin < 0) {
			printf("Значение внутреннего сопротивления введено не верно, повторите ввод: ");
			while (getchar() != '\n')  continue;
			res = scanf("%d", &current->Rin);			
		}

		printf("Введите коэффициент стабилизации %d стабилизатора напряжения: ", count + 1);
		res = scanf("%d", &current->Kst);
		while (res != 1 || current->Kst < 0) {
			printf("Значение коэффициента стабилизации введено не верно, повторите ввод: ");
			while (getchar() != '\n')  continue;
			res = scanf("%d", &current->Kst);
			
		}

		printf("Введите коэффициент сглаживания пульсаций %d стабилизатора напряжения: ", count + 1);
		res = scanf("%d", &current->Ksp);
		while (res != 1 || current->Ksp < 0) {
			printf("Значение коэффициента сглаживания пульсаций введено не верно, повторите ввод: ");
			while (getchar() != '\n')  continue;
			res = scanf("%d", &current->Ksp);
		}

		while (getchar() != '\n')  continue; // очищаем буфер ввода

		// сохраняем текущий элемент в качестве предыдущего и обновляем хвост списка
		prev = current;
		*tail = current;

		char vibor = 0;
		printf("Закончить ввод? (y/n): ");
		scanf("%c", &vibor);
		while (getchar() != '\n')  continue;
		while (toupper(vibor) != 'Y' && toupper(vibor) != 'N') {
			printf("Повторите ввод: ");
			scanf("%c", &vibor);
			while (getchar() != '\n')  continue;
		}

		switch (toupper(vibor)) {
		case 'Y':
			// сохраняем количество элементов в переменной count1 и возвращаем указатель на голову списка
			*count1 = count;
			return head;
		case 'N':
			// иначе пропускаем этот шаг и продолжаем добавлять новые элементы в список
			break;
		}

	}
	while (getchar() != '\n')
		continue;

	return head;
}