#include "Header.h"

int main(void) {
    struct  stab* head = NULL, * tail = NULL;
    int i = 0, k = 0, n, res = 0, count = 0;
    unsigned char ans = 0;

    setlocale(LC_ALL, "RU");
    while (1) {
        printf("а. Создание справочника в памяти (Ввод данных).\nб. Вывод справочника на экран.\nв. Добавление данных после записи с указанным номером \nг. Удаление данных с указанным номером\nд. Корректировка данных с указанным номером\nе. Поиск данных по любому указанному пользователем полю\nж. Сортировка пузырьком по текстовому полю\nз. Сортировка пузырьком по числовому полю\nи. Обработка хранимой в файле информации\nк. Сохранение справочника в файл.\nл. Открытие справочника из файла.\n0. выход из программы.\nВыберите номер необходимого варианта:");

        scanf("%c", &ans);
        while (getchar() != '\n')  continue;
        while (ans != 160 && ans != 161 && ans != 162 && ans != 163 && ans != 164 && ans != 165 && ans != 166 && ans != 167 && ans != 168 && ans != 170 && ans != 171 && ans != 48) {
            printf("Повторите ввод: ");
            scanf("%c", &ans);
            while (getchar() != '\n')  continue;
        }

        switch (ans) {
        case 160:
            head = vvod(head, &tail, &count);
            break;

        case 161:
            vyvod(head);
            break;
        case 162:
            printf("Введите номер записи после которой необходимо добавить новый элемент: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            newdata(head, n);
            break;
        case 163:
            printf("Введите номер записи которую необходимо удалить: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            deldata(head, n);
            break;
        case 164:
            printf("Введите номер записи которую необходимо откорректировать: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            correct(head, n); 
            break;
        case 165:
            printf("Введите номер поля, по которому необходимо произвести поиск: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            finddata(head, n);
            break;
        case 166:
            // Сортировка по тектовому полю

            break;

        case 167:
            // Сортировка по числовому полю


            break;
        case 168:
            // Обработка хранимой в файле информации

            break;
        case 170:
            fvvod(head);
            break;
        case 171:
            head = fvivod(head, &count);
            break;
        case 48: printf("Выход из программы");
            return 0;
            break;
        default:
            printf("Пункт меню выбран неправильно. Попробуйте ещё раз!!!!\n");
            break;

        }
    }
    return 0;
}
