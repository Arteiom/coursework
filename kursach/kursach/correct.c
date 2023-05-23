#include "Header.h"
void correct(struct  stab* head, int n) {
    struct  stab* current = NULL;
    int counter = 0, choice, res = 0;
    current = head;
    char ans = 0;


    // ищем запись с заданным номером n
    while (counter < (n - 1)) {
        current = current->next;
        counter++;
    }
    printf("Выбранная запись для корректировки\n");
    printf("----------------------------------------------------------------------------------------------------\n|    марка     | КПД стаб. напряжен. | внут. сопр. ст. нап. |   коэф. стаб.  | коэф. сг. пульс. |\n----------------------------------------------------------------------------------------------------\n");
    printf("| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);

    while (1) {
        printf("1. Изменение марки.\n2. Изменение КПД стабилизатора напряжения.\n3. Изменение внутреннего сопротивления стабилизатора напряжения\n4. Изменение коэффициента стабилизации стабилизатора напряжения\n5. Изменение коэффициента сглаживания пульсаций стабилизатора напряжения\n0. Корректировка окончена.\nВыберите нормер необходимого варианта:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Введите новое название марки: ");
            res = scanf("%11s", current->mark); 
            while (res != 1 || current->mark <= 0) {
                printf("Значение марки введено не верно, повторите ввод: "); 
                while (getchar() != '\n')  continue; 
                res = scanf("%11s", current->mark); 		
            }
            while (getchar() != '\n')  continue;

            break;
        case 2:
            printf("Введите новое значение КПД стабилизатора напряжения: ");
            res = scanf("%d", &current->KPD);
            while (res != 1 || current->KPD < 0) {
                printf("Значение КПД введено не верно, повторите ввод: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->KPD);
            }
            break;
        case 3:
            printf("Введите новое значение внутреннего сопротивления стабилизатора напряжения : ");
            res = scanf("%d", &current->Rin);
            while (res != 1 || current->Rin < 0) {
                printf("Значение внутреннего сопротивления введено не верно, повторите ввод: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->Rin);
            }
            break;
        case 4:
            printf("Введите новое значение коэффициента стабилизации стабилизатора напряжения: ");
            res = scanf("%d", &current->Kst);
            while (res != 1 || current->Kst < 0) {
                printf("Значение внутреннего сопротивления введено не верно, повторите ввод: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->Kst);
            }
            break;
        case 5:
            printf("Введите новое значение коэффициента сглаживания пульсаций стабилизатора напряжения: ");
            res = scanf("%d", &current->Ksp);
            while (res != 1 || current->Ksp < 0) {
                printf("Значение внутреннего сопротивления введено не верно, повторите ввод: ");
                while (getchar() != '\n')  continue;
                res = scanf("%d", &current->Ksp);
            }        
            break;
        case 0: printf("Корректировка окончена\n");
            while (getchar() != '\n') continue;          
            return;
            break;
        default:
            printf("Пункт меню выбран неправильно. Попробуйте ещё раз!!!!\n");
            break;
        }
    }
    while (getchar() != '\n')
        continue;
}