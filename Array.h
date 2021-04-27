#pragma once
class Array
{
private:
	int m_size;
	int * m_array;

public:
	Array();
	Array(int size);
	

    int& operator[](const int index);
	void operator=(Array* arr);
	int GetArrSize();
	int * GetArrayPointer();
	void SetArraySize(int size);
	void SetArrayPointer(int * array);

	~Array();
};

