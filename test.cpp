#include "Array.h"
#include <cmath>
#include <iostream>
#include "task.h"
#define NUMOFTEST 5
#define NUM 11
 const int arrayData[NUMOFTEST][NUM] = { {5, 4, -1, 0, -90, 1},
										{7, 4, -1, 0, -90, 1, 7, 21},
										{3, 4, -1, 0},
										{10, 4, -1, 0, -90, 1, 7, 21, 66, 0, -67},
										{9, 4, -1, 0, -90, 1, 7, 21, 66, 0} };
const int answer[NUMOFTEST] = { 4, 4, 2, 8, 2 };
using namespace std;

void Test() {

	Array arr;
	for (int i = 0; i < NUMOFTEST; ++i) {
		arr = Array(arrayData[i][0]);
		for(int j = 0; j < arrayData[i][0]; ++j){
			arr[j] = arrayData[i][j+1];
		}
		if (Mediana(arr) != answer[i]) {
			cout << "Тест  " << i + 1 << " не пройден " << endl << endl
				<< "Программа будет закрыта" << endl
				<< "Массив размера " << arr.GetArrSize() << endl;
			for (int k = 0; k < arr.GetArrSize(); ++k) {
				cout << "[" << k+1 << "]: " << arr[k] << ", ";
			}
			cout << endl << "Ожидаемый результат: " << answer[i] << endl
				<< "Полученный результат: " << Mediana(arr) << endl;
			exit(0);
		}
	}
	cout << endl << "Тестирование успешно пройдено!" << endl;
}