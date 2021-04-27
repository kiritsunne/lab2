#include "Array.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "task.h"

int Mediana(Array & arr)
{
	int min = INT_MAX;
	int sum = 0, sumRight = 0, sumLeft = 0;
	int mediana = 1;
	for (int i = 0; i < arr.GetArrSize(); ++i) {
		sum += arr[i];
	}
	sumLeft = arr[0];
	sumRight = sum - arr[0] - arr[1];
	for (int i = 1; i < arr.GetArrSize() - 1; ++i) {
		if (abs(sumRight - sumLeft) < min) {
			min = abs(sumRight - sumLeft);
			mediana = i;
		}
		sumRight -= arr[i + 1];
		sumLeft += arr[i];
	}
	return mediana + 1;
}
