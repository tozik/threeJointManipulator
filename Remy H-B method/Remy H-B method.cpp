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

float _timeOfMove;
float *_timeOfMovePointer = &_timeOfMove;

unsigned char _resultBitsFirstParametr[12];
unsigned char _resultBitsSecondParametr[12];
unsigned char _resultBitsThirdParametr[12];
unsigned char _resultBitsFourthParametr[12];

enum _enumTask
{
	DirectTask,
	InverseTask
};

void TranlateToBits(float firstValue, unsigned char tempFirstResultBits[12],
					float secondValue, unsigned char tempSecondResultBits[12],
					float thirdValue, unsigned char tempThirdResultBits[12],
					float fourthValue, unsigned char tempFourthResultBits[12]);

int main()
{

	std::vector<float> pointsOfMoving;

	_xWorld = 0;
	_yWorld = 0;
	_zWorld = 0;

	_firstJoint = 0; //* M_PI / 180;
	_secondJoint = 0; // * M_PI / 180;
	_thirdJoint = 0; // * M_PI / 180;

	_timeOfMove = 0;

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
			//Calculating::CalculateDirectTaskNotPtr(_firstJointPointer, _secondJointPointer, _thirdJointPointer, 0, 0, 0);
			Calculating::CalculateDirectTask(_firstJointPointer, _secondJointPointer, _thirdJointPointer, _xWorldPointer, _yWorldPointer, _zWorldPointer);
			/*TranlateToBits(_xWorld, _resultBitsFirstParametr,
						   _yWorld, _resultBitsSecondParametr,
						   _zWorld, _resultBitsThirdParametr,
						   _timeOfMove, _resultBitsFourthParametr);*/
		}

		std::cout << "\nEnd of task\n";
	}

	else if (_typeOfTask == 2)
	{
		std::cout << "\nRun InverseTAsk\n";
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
			//Calculating::CalculateInverseTaskNotPtr(_xWorldPointer, _yWorldPointer, _zWorldPointer, 0, 0, 0);
			/*TranlateToBits(_xWorld, _resultBitsFirstParametr,
						   _yWorld, _resultBitsSecondParametr,
						   _zWorld, _resultBitsThirdParametr,
						   _timeOfMove, _resultBitsFourthParametr);*/
		}
		std::cout << "\nEnd of task\n\n";
	}

	else
	{
		std::cout << "Error of type. \n Choise must be int and 1 or 2\n";
	}

	system("pause");
	return(0);
}


void TranlateToBits(float firstValue, unsigned char tempFirstResultBits[12],
					float secondValue, unsigned char tempSecondResultBits[12],
					float thirdValue, unsigned char tempThirdResultBits[12],
					float fourthValue, unsigned char tempFourthResultBits[12])
{
	//std::cout << "N = (binset) " << std::bitset<12>(value);
	//std::cout << " = (int) " << (int32_t)value;

	int size = 17;

	float frac_numFirst;
	unsigned int int_numFirst;

	float frac_numSecond;
	unsigned int int_numSecond;

	float frac_numThird;
	unsigned int int_numThird;

	float frac_numFourth;
	unsigned int int_numFourth;


#pragma region Translate first pair to bits
	frac_numFirst = firstValue;
	int_numFirst = firstValue - floor(firstValue);

	for (int i = size - 1 - 5; i >= 0; i--)
	{
		char result = ((int_numFirst >> i) & 1);
		tempFirstResultBits[i] = result;
		std::cout << (int)tempFirstResultBits[i];
	}
	std::cout << ',';
	for (int i = 0; i < 4; i++)
	{
		frac_numFirst *= 2;
		tempFirstResultBits[i] = floor(frac_numFirst);
		std::cout << (int)tempFirstResultBits[i];
		frac_numFirst -= floor(frac_numFirst);
	}
#pragma endregion

#pragma region Translate second pair to bits
	frac_numSecond = secondValue;
	int_numSecond = secondValue - floor(secondValue);

	for (int i = size - 1 - 5; i >= 0; i--)
	{
		char result = ((int_numSecond >> i) & 1);
		tempSecondResultBits[i] = result;
		std::cout << (int)tempSecondResultBits[i];
	}
	std::cout << ',';
	for (int i = 0; i < 4; i++)
	{
		frac_numSecond *= 2;
		tempSecondResultBits[i] = floor(frac_numSecond);
		std::cout << (int)tempSecondResultBits[i];
		frac_numSecond -= floor(frac_numSecond);
	}
#pragma endregion

#pragma region Translate third pair to bits
	frac_numThird = thirdValue;
	int_numSecond = thirdValue - floor(thirdValue);

	for (int i = size - 1 - 5; i >= 0; i--)
	{
		char result = ((int_numSecond >> i) & 1);
		tempThirdResultBits[i] = result;
		std::cout << (int)tempThirdResultBits[i];
	}
	std::cout << ',';
	for (int i = 0; i < 4; i++)
	{
		frac_numThird *= 2;
		tempThirdResultBits[i] = floor(frac_numThird);
		std::cout << (int)tempThirdResultBits[i];
		frac_numThird -= floor(frac_numThird);
	}
#pragma endregion

#pragma region Translate fourth pair to bits
	frac_numFourth = fourthValue;
	int_numFourth = fourthValue - floor(fourthValue);

	for (int i = size - 1 - 5; i >= 0; i--)
	{
		char result = ((int_numFourth >> i) & 1);
		tempThirdResultBits[i] = result;
		std::cout << (int)tempThirdResultBits[i];
	}
	std::cout << ',';
	for (int i = 0; i < 4; i++)
	{
		frac_numFourth *= 2;
		tempThirdResultBits[i] = floor(frac_numFourth);
		std::cout << (int)tempThirdResultBits[i];
		frac_numFourth -= floor(frac_numFourth);
	}
#pragma endregion
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
