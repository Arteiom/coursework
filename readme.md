Разработать и реализовать на языке C информационно-поисковый справочник радиотехнических деталей. Тип детали выбрать из таблицы приложения 1. 
При запуске программы на выполнение, проанализировать командную строку и если в ней указано имя существующего файла данных, то его и обрабатывать в справочнике (2,3,4). В программе должно появляться цифровое (1) либо буквенное меню в виде латиницы (2) или кириллицы (3, 4), посредством которого должны вызываться следующие пункты, реализованные в программе как отдельные функции (кроме пункта выхода из программы):
a	Создание справочника в памяти (Ввод данных).
b	Вывод справочника на экран. 
c	Добавление данных в конец справочника (1)
d	Удаление данных в конце справочника (1)
e	Добавление данных после записи с указанным номером (2,3,4)
f	Удаление данных с указанным номером (2,3,4)
g	Корректировка данных с указанным номером.
h	Поиск данных по определенному числовому полю (1,2)
i	Поиск данных по определенному текстовому полю (2)
j	Поиск данных по любому указанному пользователем полю (3,4)
k	Сортировки (вид сортировок выбрать из приложения 2 (1,2,3) 
либо согласовать с преподавателем (4))
…
l	Обработка хранимой в файле информации (согласовать с преподавателем) (3,4).
m	Сохранение справочника в файл.
n	Открытие справочника из файла.
o	Выход из программы.
В программе не должно быть глобальных массивов переменных (2,3,4). Все данные передавать как параметры в отдельные функции (2,3,4). В функциях сортировки у пользователя запрашивать направление сортировки: по убыванию либо по возрастанию (2,3,4). Хранение данных в программе должно быть реализовано с помощью связных списков (3,4). Сортировка должна быть произведена с помощью временного копирования в одномерный массив (3) либо непосредственно связного списка (4).
Создать собственный заголовочный файл, включающий директивы препроцессора, определение структуры данных, прототипы используемых функций. Предусмотреть защиту программы от ввода пользователем некорректных данных.
Каждая запись сведений о радиодетали должна состоять из 5 полей: марка (строковый тип); наименования и типы остальных 4 полей выбираются самостоятельно и должны представлять собой реальные параметры радиодеталей. Обрабатываемая база данных должна содержать реальные марки и соответствующие им параметры деталей. Таблица с параметрами деталей (не менее 15 элементов), краткая характеристика и назначение детали должны быть приведены в отчете по работе.



Приложение 1. - Тип радиодетали

№	   Тип элемента	

4.		Стабилизаторы напряжения

 
