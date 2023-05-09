#include "Header.h"
void finddata(struct  stab* head, int n) {
    struct  stab* current = NULL;
    int i = 0, findd = 0;

    // Переменные для сравнения ввода с элементом поля
    int numb = 0;
    char str[12];

    current = head;
    switch (n) {
    case 1:
        printf("Введите, что необходимо найти: ");
        scanf("%s", str);

        while (current != NULL) {
            if ((strcoll(current->mark, str)) == 0) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) { 
            printf("%s в марках стабилизатора напряжения не найдено\n", str);
        }
        break;
    case 2:
        printf("Введите, что необходимо найти: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->KPD == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d в КПД стабилизатора напряжения не найдено\n", numb);
        }
        break;
    case 3:
        printf("Введите, что необходимо найти: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->Rin == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d в внутреннем сопротивлении стабилизатора напряжения не найдено\n", numb);
        }
        break;
    case 4:
        printf("Введите, что необходимо найти: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->Kst == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d в коэффициенте стабилизации стабилизатора напряжения не найдено\n", numb);
        }
        break;
    case 5:
        printf("Введите, что необходимо найти: ");
        scanf("%d", &numb);
        while (current != NULL) {
            if (current->Ksp == numb) {
                printf("----------------------------------------------------------------------------------------------------\n|%2.d| %-12s | %-19d | %-20.d | %-14.d | %-16.d |\n----------------------------------------------------------------------------------------------------\n", i + 1, current->mark, current->KPD, current->Rin, current->Kst, current->Ksp);
                findd++;
            }
            current = current->next;
            i++;
        }
        if (findd == 0) {
            printf("%d в коэффициенте сглаживания пульсаций стабилизатора напряжения не найдено\n", numb);
        }
        break;
    default:
        printf("Пункт меню выбран неправильно. Попробуйте ещё раз!!!!\n");
        break;
    }
    while (getchar() != '\n')
        continue;
}