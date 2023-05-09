#include "Header.h"


int main(void) {

    struct  stab* head = NULL, * tail = NULL;
    int i = 0, k = 0, n, res = 0, count = 0;
    unsigned char ans = 0;

    int dir = 1;

    system("chcp 1251>nul");
    while (1) {
        printf("а. Создание справочника в памяти (Ввод данных).\nб. Вывод справочника на экран.\nв. Добавление данных после записи с указанным номером \nг. Удаление данных с указанным номером\nд. Корректировка данных с указанным номером\nе. Поиск данных по любому указанному пользователем полю\nж. Сортировка слиянием по текстовому полю Mark\nз. Сортировка слиянием по числовому полю KPD\nи. Обработка хранимой в файле информации\nк. Сохранение справочника в файл.\nл. Открытие справочника из файла.\n0. выход из программы.\nВыберите номер необходимого варианта:");

        scanf("%c", &ans);
        while (getchar() != '\n')  continue;
        while (ans != 'а' && ans != 'б' && ans != 'в' && ans != 'г' && ans != 'д' && ans != 'е' && ans != 'ж' && ans != 'з' && ans != 'и' && ans != 'к' && ans != 'л' && ans != '0') {
            printf("Повторите ввод: ");
            scanf("%c", &ans);
            while (getchar() != '\n')  continue;
        }

        switch (ans) {
        case 'а':
            head = vvod(head, &tail, &count);
            break;

        case 'б':
            vyvod(head);
            break;
        case 'в':
            printf("Введите номер записи после которой необходимо добавить новый элемент: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            newdata(head, n);
            break;
        case 'г':
            printf("Введите номер записи которую необходимо удалить: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            deldata(head, n);
            break;
        case 'д':
            printf("Введите номер записи которую необходимо откорректировать: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            correct(head, n); 
            break;
        case 'е':
            printf("Введите номер поля, по которому необходимо произвести поиск: ");
            res = scanf("%d", &n);
            while (res != 1 || n < 0) {
                printf("Значение введено не верно, повторите ввод: ");
                res = scanf("%d", &n);
                while (getchar() != '\n')  continue;
            }
            finddata(head, n);
            break;
        case 'ж':
            mergeSortMarkWrapper(&head, &count, dir);
            break;
        case 'з':
            mergeSortNumWrapper(&head, &count, dir);
            break;
        case 'и':
            encode(FILE_NAME, "encoded.txt");
            decode("encoded.txt", "decoded.txt");    
            break;
        case 'к':
            fvvod(head);
            break;
        case 'л':
            head = fvivod(head, &count);
            break;
        case '0': printf("Выход из программы");
            return 0;
            break;
        default:
            printf("Пункт меню выбран неправильно. Попробуйте ещё раз!!!!\n");
            break;

        }
    }
    return 0;
}
