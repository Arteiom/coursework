#include "Header.h" 
fvvod(struct  stab* head) {
    // ќбъ€вление указател€ на текущий элемент списка и переменной дл€ подсчета количества элементов
    struct  stab* current = NULL;
    int i = 0;

    current = head;
    FILE* fl;

    // ÷икл, который считает количество элементов в списке
    while (current != NULL) {
        current = current->next;
        i++;
    }
    current = head;

    // ќткрытие файла дл€ записи, если файл не существует, то он будет создан
    fl = fopen("VVOD.txt", "w");
    fprintf(fl, "%d\n", i);

    // ÷икл, который записывает значени€ полей каждой структуры списка в файл
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