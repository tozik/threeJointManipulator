// Remy H-B method.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <sstream>
#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <algorithm>
#include "Remy H-B method.h"
#include "InteractionWithUser.h"
#include "Calculating.h"
#include "ReadingClass.h"


float _xWorld;
float _yWorld;
float _zWorld;

float *_xWorldPointer = &_xWorld;
float *_yWorldPointer = &_yWorld;
float *_zWorldPointer = &_zWorld;

float _firstJoint;
float _secondJoint;
float _thirdJoint;

float *_firstJointPointer = &_firstJoint;
float *_secondJointPointer = &_secondJoint;
float *_thirdJointPointer = &_thirdJoint;

int _typeOfTask;

enum _enumTask
{
	DirectTask,
	InverseTask
};

void TranlateToBits();

int main()
{
	//double num;
	//std::cout << "Enter the number: ";
	//std::cin >> num;
	//TranlateToBits(num);

	_xWorld = 10;
	_yWorld = 0;
	_zWorld = 10;

	_firstJoint = 45 * M_PI / 180;
	_secondJoint = 0 * M_PI / 180;
	_thirdJoint = 0 * M_PI / 180;

	ReadingClass _fileWithData;
	_fileWithData.GetLineInstructionsFromFile();

	std::cout << "*******************";

	std::cout << "\nMember cell for X is == " << &_xWorld;
	std::cout << "\nMember cell for Y is == " << &_yWorld;
	std::cout << "\nMember cell for Z is == " << &_zWorld << "\n";

	InteractionWithUser::PrintRequest();

	std::cin >> _typeOfTask;

	if (_typeOfTask == 1)
	{
		std::cout << "\nRun DirectTask\n";

		Calculating::CalculateDirectTaskNotPtr(_firstJointPointer, _secondJointPointer, _thirdJointPointer,
			0, 0, 0);
		std::cout << "\nEnd of task\n";

	}
	else if (_typeOfTask == 2)
	{
		std::cout << "\nRun InverseTAsk\n";
		Calculating::CalculateInverseTaskNotPtr(_xWorldPointer, _yWorldPointer, _zWorldPointer, 0, 0, 0);
		std::cout << "\nEnd of task\n\n";

	}
	else
	{
		std::cout << "Error of type. \n Choise must be int and 1 or 2\n";
	}

	system("pause");
	return(0);
}
void TranlateToBits(double value)
{
	//std::cout << "N = (binset) " << std::bitset<12>(value);
	//std::cout << " = (int) " << (int32_t)value;

	double frac_num;
	unsigned int int_num;
	int sz;

	sz = 12;
	int_num = value;
	frac_num = value - floor(value);

	for (int i = sz - 1; i >= 0; i--)
	{
		std::cout << ((int_num >> i) & 1);
	}
	std::cout << ',';
	for (int i = 0; i < 4; i++)
	{
		frac_num *= 2;
		std::cout << floor(frac_num);
		frac_num -= floor(frac_num);
	}
	std::cout << std::endl;

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
