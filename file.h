#pragma once

#include<string>
#include"Array.h"

using namespace std;
string SaveToFile();
void SaveResultToFile(Array &arr, int result);
void SaveInitialDataToFile(Array &arr);
Array InputFromFile();
bool CheckExistFile(string &filePath);
bool CreateNewFile(string &filePath);
string EnterFilePath();