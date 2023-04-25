#include "Header.h" 


struct stab* fvivod(struct stab* head, int* count1) {
    // Объявление указателей на текущий и предыдущий элементы списка и переменной для чтения из файла
    struct stab* current = NULL, * prev = NULL;
    int count;
    // Открытие файла для чтения
    FILE* fl = fopen(FILE_NAME, "r");

    // Чтение количества элементов из файла
    fscanf(fl, "%d", &count);
    // Цикл, который создает структуры и заполняет их поля значениями из файла
    for (int i = 0; i < count; i++) {
        // Выделение памяти для текущей структуры
        current = (struct stab*)malloc(sizeof(struct stab));

        // Если голова списка пуста, то текущая структура становится головой
        if (head == NULL)
            head = current;
        // Иначе текущая структура становится следующей после предыдущей
        else
            prev->next = current;

        // Следующий элемент после текущего - NULL, т.к. текущая структура последняя в списке
        current->next = NULL;
        // Чтение значений полей текущей структуры из файла
        fscanf(fl, "%s", current->mark);
        fscanf(fl, "%d", &current->KPD);
        fscanf(fl, "%d", &current->Rin);
        fscanf(fl, "%d", &current->Kst);
        fscanf(fl, "%d", &current->Ksp);
        // Передвижение указателя prev на текущую структуру
        prev = current;
    }
    // Запись значения count в переменную count1 через указатель на нее
    *count1 = count;

    // Закрытие файла
    fclose(fl);
   
    // Возврат указателя на голову списка
    return head;
}
