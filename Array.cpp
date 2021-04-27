#include "Array.h"

Array::Array()
{
	m_size = 0;
}

Array::Array(int size)
{
	m_size = size;
	m_array = new int[size];
}

int & Array::operator[](const int index)
{
	return m_array[index];
}

void Array::operator=(Array* arr)
{
	this->m_size = arr->GetArrSize();
	arr->SetArraySize(0);
	this->m_array = arr->GetArrayPointer();
	arr->SetArrayPointer(nullptr);
	//return *this;
}

int Array::GetArrSize()
{
	return m_size;
}

int * Array::GetArrayPointer()
{
	return m_array;
}

void Array::SetArraySize(int size)
{
	m_size = size;
}

void Array::SetArrayPointer(int * array)
{
	m_array = array;
}

Array::~Array()
{
	if (m_size != 0)
		delete m_array;
}



