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
//������������ ������ ��� ������ ������ ����
enum menu {
	EXIT,
	TASK,
	TEST
};
//������������ ������ ��� ������ ������ �������
enum taskmenu {
	RETURN,//�����
	KEYBORD,//���� � ����������
	INP_FILE,//���� �� �����
	RANDOM//���������� ������� ������������� �������
};
//������� ��� ������ �����������
void Greatings()
{
	cout << "=============" << endl
		<< "�������� �.�." << endl
		<< "������ �404" << endl
		<< "Email: daiti.ru.ua@gmail.com" << endl
		<< "������������ ������ �2" << endl
		<< "������� �1" << endl
		<< "�������� ���������, ��������� �������� �������. �� ���� ������ ������" << endl
		<< "�������, ����� ��������� ����� �� ������� ���������� ���������� �� �����" << endl
		<< "��������� ������." << endl
		<< "=============" << endl;
	system("pause");
}
//������� ��� ������ � �������������� � ����
void Menu()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;

	do
	{
		system("cls");
		cout << "������������ ������ �1" << endl
			<< "1 - ���������� ������� �������" << endl
			<< "2 - ������������" << endl
			<< "0 - �����" << endl;

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
			cout << "������������" << endl << endl;
			//Test();
			system("pause");
			break;
		}
		case EXIT: break;
		default: {
			cout << "������� ���������� ��������!" << endl;
			system("pause");
			break;
		}
		}

	} while (userChoice != EXIT);
}
//������� ��� ������ � ������������ � �������� �������
void MenuTask()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;
	int arrSize = 0;
	Array arr;
	//double x = 0, y = 0, radius = 0;

	//���� ������ �� �������
	//false - �� �������� �� �������
	//true - ����� �� �������
	bool flagExitSubMenu = true;

	//���� ���������� � ����
	//false - �� ��������� ������ � ����
	//true - ��������� ������ � ����
	bool flagSaveToFile = false;


	do
	{
		system("cls");
		cout << "1 - ���� � ����������" << endl
			<< "2 - ���� �� �����" << endl
			<< "3 - �������������� ���� ������������ ��������" << endl
			<< "0 - �����" << endl;
		input(userChoice);

		switch (userChoice)
		{
		//���� ������ � ����������
		case KEYBORD: {
			cout << "������� ���������� ��������� �������" << endl;
			input(arrSize);
			while (arrSize <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrSize);
			}
			arr = Array(arrSize);
			cout << "������� �������� ������� (" << arrSize << "):" << endl;
			for (int i = 0; i < arrSize; ++i) {
				cout << "[" << i + 1 << "]: ";
				input(arr[i]);
			}
			break;
		}
		//���� �� �����
		case INP_FILE: {
			while (arrSize == 0) {
				cout << "������ ��� �������:" << endl;
				arr = InputFromFile();
			}
			break;
		}
		//���� ������������ �����
		case RANDOM: {
			cout << "������� ���������� ��������� �������" << endl;
			input(arrSize);
			while (arrSize <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrSize);
			}
			arr = Array(arrSize);
			for (int i = 0; i < arrSize; ++i) {
				arr[i] = RandomInt(FROM, TO);
			}
		}
		//��������� � ������� ����
		case RETURN: {
			flagExitSubMenu = false;
			break;
		}
		default: {
			cout << "������� ���������� ��������!" << endl;
			system("pause");
			break;
		}
		}
		//����������� ���� ���� ������� ������ ���� �����������
		//� �� ������ ����� �����
		if (flagExitSubMenu && arr.GetArrSize() > 0) {
			cout << "������ ������� " << arr.GetArrSize() << endl;
			for (int i = 0; i < arr.GetArrSize(); ++i) {
				cout << arr[i] << " ";
			}
			cout << "������� �������: " << Mediana(arr) << endl << endl;
			

			cout << "������� ��������� �������� ������ � ����?" << endl
				<< "1 - ��" << endl
				<< "0 - ���" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile)
				SaveInitialDataToFile(arr);

			cout << "������� ��������� ��������� � ����?" << endl
				<< "1 - ��" << endl
				<< "0 - ���" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile)
				SaveResultToFile(arr, Mediana(arr));

			userChoice = RETURN;
		}
		system("pause");

	} while (userChoice != RETURN);
}