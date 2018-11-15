// Remy H-B method.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
//#include <sstream>
#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <bitset>
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

std::bitset<12> _resultBitsFirstParametr;
std::bitset<12> _resultBitsSecondParametr;
std::bitset<12> _resultBitsThirdParametr;
std::bitset<12> _resultBitsFourthParametr;

std::bitset<12> *_resultBitsFirstParametrPointer = &_resultBitsFirstParametr;
std::bitset<12> *_resultBitsSecondParametrPointer = &_resultBitsSecondParametr;
std::bitset<12> *_resultBitsThirdParametrPointer = &_resultBitsThirdParametr;
std::bitset<12> *_resultBitsFourthParametrPointer = &_resultBitsFourthParametr;

enum _enumTask
{
	DirectTask,
	InverseTask
};

void TranlateToBits(float *firstValue,
	float *secondValue,
	float *thirdValue,
	float *fourthValue);

int main()
{
	/*TranlateToBits(10.5, 11, 12, 13);
	std::cout << _resultBitsFirstParametr << "\tsizeof\t" << _resultBitsFirstParametr.size() << std::endl;
	std::cout << _resultBitsSecondParametr << "\tsizeof\t" << _resultBitsSecondParametr.size() << std::endl;
	std::cout << _resultBitsThirdParametr << "\tsizeof\t" << _resultBitsThirdParametr.size() << std::endl;
	std::cout << _resultBitsFourthParametr << "\tsizeof\t" << _resultBitsFourthParametr.size() << std::endl;*/

	std::cout << std::endl;
	std::vector<float> pointsOfMoving;

	_xWorld = 0;
	_yWorld = 0;
	_zWorld = 0;

	_firstJoint = 0; //* M_PI / 180;
	_secondJoint = 0; // * M_PI / 180;
	_thirdJoint = 0; // * M_PI / 180;

	_timeOfMove = 0;

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

		ReadingClass _fileWithData("inputJoints.in");
		_fileWithData.GetLineInstructionsFromFile(&pointsOfMoving);

		for (int i = 0, k = 1; i < (pointsOfMoving.size() / 4); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				switch (j)
				{
				case 0:
				{
					_firstJoint = pointsOfMoving[k++ - 1];
					break;
				}
				case 1:
				{
					_secondJoint = pointsOfMoving[k++ - 1];
					break;
				}
				case 2:
				{
					_thirdJoint = pointsOfMoving[k++ - 1];
					break;
				}
				case 3:
				{
					_timeOfMove = pointsOfMoving[k++ - 1];
					break;
				}
				default:
					std::cout << "\Problem with foreach in direct task\n";
					break;
				}
			}
			//Calculating::CalculateDirectTaskNotPtr(_firstJointPointer, _secondJointPointer, _thirdJointPointer, 0, 0, 0);
			Calculating::CalculateDirectTask(
				_firstJointPointer,
				_secondJointPointer,
				_thirdJointPointer,
				_xWorldPointer,
				_yWorldPointer,
				_zWorldPointer);

		}

		std::cout << "\nEnd of task\n";
	}

	else if (_typeOfTask == 2)
	{
		std::cout << "\nRun InverseTAsk\n";

		ReadingClass _fileWithData("input.in");
		_fileWithData.GetLineInstructionsFromFile(&pointsOfMoving);

		for (int i = 0, k = 1; i < (pointsOfMoving.size() / 4); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				switch (j)
				{
				case 0:
				{
					_xWorld = pointsOfMoving[k++ - 1];
					break;
				}
				case 1:
				{
					_yWorld = pointsOfMoving[k++ - 1];
					break;
				}
				case 2:
				{
					_zWorld = pointsOfMoving[k++ - 1];
					break;
				}
				case 3:
				{
					_timeOfMove = pointsOfMoving[k++ - 1];
					break;
				}
				default:
					std::cout << "\Problem with foreach in direct task\n";
					break;
				}
			}

			Calculating::CalculateInverseTask(
				_xWorldPointer,
				_yWorldPointer,
				_zWorldPointer,
				_firstJointPointer,
				_secondJointPointer,
				_thirdJointPointer);

			if ((*_firstJointPointer > M_PI || *_firstJointPointer < -M_PI || *_firstJointPointer!= *_firstJointPointer)
				|| (*_secondJointPointer > M_PI / 2 || *_secondJointPointer < -M_PI / 2 || *_secondJointPointer!=*_secondJointPointer)
				|| (*_thirdJointPointer > M_PI || *_thirdJointPointer < -M_PI || *_thirdJointPointer!=*_thirdJointPointer))
			{
				std::cout <<"Position nubmer ["<< i+1 << "] not reachable or problem with data\n";
			}
			else
			{
				TranlateToBits(_firstJointPointer,
					_secondJointPointer,
					_thirdJointPointer,
					_timeOfMovePointer);
			}

			std::cout << _resultBitsFirstParametr << "\t";
			std::cout << _resultBitsSecondParametr << "\t";
			std::cout << _resultBitsThirdParametr << "\t";
			std::cout << _resultBitsFourthParametr << std::endl;

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

void TranlateToBits(float *firstValue,
	float *secondValue,
	float *thirdValue,
	float *fourthValue)

{
	std::bitset<12>  bitsFirstValue(4096 * ((*firstValue) / (2 * M_PI)));
	std::bitset<12>  bitsSecondValue(4096 * ((*secondValue) / (2 * M_PI)));
	std::bitset<12>  bitsThirdValue(4096 * ((*thirdValue) / (2 * M_PI)));
	std::bitset<12>  bitsFourthValue(4096 * ((*fourthValue) / (2 * M_PI)));

	*_resultBitsFirstParametrPointer = bitsFirstValue;
	*_resultBitsSecondParametrPointer = bitsSecondValue;
	*_resultBitsThirdParametrPointer = bitsThirdValue;
	*_resultBitsFourthParametrPointer = bitsFourthValue;
}
