// Remy H-B method.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
//#include <sstream>
#include <vector>
#include <bitset>
#include <iostream>
#include <string>
//#include <algorithm>
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

float _timeOfMove = 0;
enum _enumTask
{
	DirectTask,
	InverseTask
};

void TranlateToBits(float value);

int main()
{
	std::vector<float> pointsOfMoving;
	float num;
	std::cout << "Enter the number: ";
	std::cin >> num;

	TranlateToBits(num);

	_xWorld = 0;
	_yWorld = 0;
	_zWorld = 0;

	_firstJoint = 0; //* M_PI / 180;
	_secondJoint = 0; // * M_PI / 180;
	_thirdJoint = 0; // * M_PI / 180;

	ReadingClass _fileWithData;
	_fileWithData.GetLineInstructionsFromFile(&pointsOfMoving);

	std::cout << "\n**************************************";
	std::cout << "\nMember cell for X is == " << &_xWorld;
	std::cout << "\nMember cell for Y is == " << &_yWorld;
	std::cout << "\nMember cell for Z is == " << &_zWorld << "\n";

	InteractionWithUser::PrintRequest();

	int _typeOfTask;
	std::cin >> _typeOfTask;

	if (_typeOfTask == 1)
	{
		std::cout << "\nRun DirectTask\n";
		for (int i = 0; i < (pointsOfMoving.size() / 4); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				switch (j)
				{
				case 0:
				{
					_firstJoint = pointsOfMoving[j*(1 + i)];
					break;
				}
				case 1:
				{
					_secondJoint = pointsOfMoving[j*(1 + i)];
					break;
				}
				case 2:
				{
					_thirdJoint = pointsOfMoving[j*(1 + i)];
					break;
				}
				case 3:
				{
					_timeOfMove = pointsOfMoving[j*(1 + i)];
					break;
				}
				default:
					std::cout << "\Problem with foreach in direct task\n";
					break;
				}
			}
			Calculating::CalculateDirectTaskNotPtr(_firstJointPointer, _secondJointPointer, _thirdJointPointer, 0, 0, 0);
			
		}

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
void TranlateToBits(float value)
{
	//std::cout << "N = (binset) " << std::bitset<12>(value);
	//std::cout << " = (int) " << (int32_t)value;

	float frac_num;
	unsigned int int_num;
	int size;
	unsigned char resultBits[12];

	size = 17;
	int_num = value;
	frac_num = value - floor(value);

	for (int i = size - 1 - 5; i >= 0; i--)
	{
		char result = ((int_num >> i) & 1);
		resultBits[i] = result;
		std::cout << (int)resultBits[i];
	}
	std::cout << ',';
	for (int i = 0; i < 4; i++)
	{
		frac_num *= 2;
		resultBits[i] = floor(frac_num);
		std::cout << (int)resultBits[i];
		//std::cout << floor(frac_num);
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
