#include "interface.h"
#include<iostream>
#include<locale.h>
#include"task.h"
#include"enter.h"
#include "test.h"
#include"Array.h"
#include"file.h"

#define FROM -100
#define TO 100

using namespace std;
//именнованный массив для выбора пункта меню
enum menu {
	EXIT,
	TASK,
	TEST
};
//именнованный массив для выбора пункта подменю
enum taskmenu {
	RETURN,//назад
	KEYBORD,//ввод с клавиатуры
	INP_FILE,//ввод из файла
	RANDOM//заполнение массива произвольными числами
};
//функция для вывода приветствия
void Greatings()
{
	cout << "=============" << endl
		<< "Вересова В.А." << endl
		<< "группа №404" << endl
		<< "Email: daiti.ru.ua@gmail.com" << endl
		<< "Лабораторная работа №2" << endl
		<< "Вариант №1" << endl
		<< "Напишите программу, находящую «медиану» массива. То есть индекс ячейки" << endl
		<< "массива, сумма элементов слева от которой минимально отличается от суммы" << endl
		<< "элементов справа." << endl
		<< "=============" << endl;
	system("pause");
}
//функция для вывода и взаимодействия с меню
void Menu()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;

	do
	{
		system("cls");
		cout << "Лабораторная работа №1" << endl
			<< "1 - Нахождение медианы массива" << endl
			<< "2 - Тестирование" << endl
			<< "0 - Выход" << endl;

		input(userChoice);

		switch (userChoice)
		{
		case TASK: {
			system("cls");
			MenuTask();
			break;
		}
		case TEST: {
			system("cls");
			cout << "Тестирование" << endl << endl;
			//Test();
			system("pause");
			break;
		}
		case EXIT: break;
		default: {
			cout << "Введите корректное значение!" << endl;
			system("pause");
			break;
		}
		}

	} while (userChoice != EXIT);
}
//функция для вывода и взимоействия с пунктами подменю
void MenuTask()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;
	int arrSize = 0;
	Array arr;
	//double x = 0, y = 0, radius = 0;

	//флаг выхода из подменю
	//false - не выходить из подменю
	//true - выход из подменю
	bool flagExitSubMenu = true;

	//флаг сохранения в файл
	//false - не сохранять данные в файл
	//true - сохранять данные в файл
	bool flagSaveToFile = false;


	do
	{
		system("cls");
		cout << "1 - Ввод с клавиатуры" << endl
			<< "2 - Ввод из файла" << endl
			<< "3 - Автоматический ввод произвольных значений" << endl
			<< "0 - Назад" << endl;
		input(userChoice);

		switch (userChoice)
		{
		//ввод данных с клавиатуры
		case KEYBORD: {
			cout << "Введите количество элементов массива" << endl;
			input(arrSize);
			while (arrSize <= 0) {
				cout << "Количество элементов массива не может быть отрицательным или нулевым." << endl
					<< "Введите корректное значение" << endl;
				input(arrSize);
			}
			arr = Array(arrSize);
			cout << "Введите элементы массива (" << arrSize << "):" << endl;
			for (int i = 0; i < arrSize; ++i) {
				cout << "[" << i + 1 << "]: ";
				input(arr[i]);
			}
			break;
		}
		//ввод из файла
		case INP_FILE: {
			while (arrSize == 0) {
				cout << "Данные для массива:" << endl;
				arr = InputFromFile();
			}
			break;
		}
		//ввод произвольных чисел
		case RANDOM: {
			cout << "Введите количество элементов массива" << endl;
			input(arrSize);
			while (arrSize <= 0) {
				cout << "Количество элементов массива не может быть отрицательным или нулевым." << endl
					<< "Введите корректное значение" << endl;
				input(arrSize);
			}
			arr = Array(arrSize);
			for (int i = 0; i < arrSize; ++i) {
				arr[i] = RandomInt(FROM, TO);
			}
		}
		//вернуться в главное меню
		case RETURN: {
			flagExitSubMenu = false;
			break;
		}
		default: {
			cout << "Введите корректное значение!" << endl;
			system("pause");
			break;
		}
		}
		//выполняется если были введены данные двух окружностей
		//и не выбран пункт НАЗАД
		if (flagExitSubMenu && arr.GetArrSize() > 0) {
			cout << "Массив размера " << arr.GetArrSize() << endl;
			for (int i = 0; i < arr.GetArrSize(); ++i) {
				cout << arr[i] << " ";
			}
			cout << "Медиана массива: " << Mediana(arr) << endl << endl;
			

			cout << "Желаете сохранить исходные данные в файл?" << endl
				<< "1 - Да" << endl
				<< "0 - Нет" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile)
				SaveInitialDataToFile(arr);

			cout << "Желаете сохранить результат в файл?" << endl
				<< "1 - Да" << endl
				<< "0 - Нет" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile)
				SaveResultToFile(arr, Mediana(arr));

			userChoice = RETURN;
		}
		system("pause");

	} while (userChoice != RETURN);
}