// Remy H-B method.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <bitset>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include "Remy H-B method.h"
#include "InteractionWithUser.h"
#include "Calculating.h"
#include "ReadingClass.h"
#include "windows.h"
#include "Connection.h"

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

std::vector<unsigned char> _dataToRobot;
std::vector<unsigned char> _dataFromRobot;

std::vector<float> _pointsOfMoving;
std::vector<float> _jointsOfMoving;

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

void TranlateAndPackBits(float *firstValue,
	float *secondValue,
	float *thirdValue,
	float *fourthValue);

void UnTranlateAndUnPackBits(std::vector<unsigned char> data);

int main()
{
	unsigned int start_time;
	unsigned int end_time;

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
	Connection connect;
	int _typeOfTask;
	std::cin >> _typeOfTask;

	if (_typeOfTask == 1)
	{
		std::cout << "\nRun DirectTask\n";

		connect.open();
		connect.receive(_dataFromRobot);
		UnTranlateAndUnPackBits(_dataFromRobot);

		Calculating::CalculateDirectTask(
			_firstJointPointer,
			_secondJointPointer,
			_thirdJointPointer,
			_xWorldPointer,
			_yWorldPointer,
			_zWorldPointer);
		std::cout << "\nEnd of task\n";
	}

	else if (_typeOfTask == 2)
	{
		std::cout << "\nRun InverseTAsk\n";

		ReadingClass _fileWithData("input.in");
		_fileWithData.GetLineInstructionsFromFile(&_pointsOfMoving);

		for (int i = 0, k = 1; i < (_pointsOfMoving.size() / 4); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				switch (j)
				{
				case 0:
				{
					_xWorld = _pointsOfMoving[k++ - 1];
					break;
				}
				case 1:
				{
					_yWorld = _pointsOfMoving[k++ - 1];
					break;
				}
				case 2:
				{
					_zWorld = _pointsOfMoving[k++ - 1];
					break;
				}
				case 3:
				{
					_timeOfMove = _pointsOfMoving[k++ - 1];
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

			if ((*_firstJointPointer > M_PI || *_firstJointPointer < -M_PI || *_firstJointPointer != *_firstJointPointer)
				|| (*_secondJointPointer > M_PI / 2 || *_secondJointPointer < -M_PI / 2 || *_secondJointPointer != *_secondJointPointer)
				|| (*_thirdJointPointer > M_PI || *_thirdJointPointer < -M_PI || *_thirdJointPointer != *_thirdJointPointer))
			{
				std::cout << "Position nubmer [" << i + 1 << "] not reachable or problem with data\n";
			}
			else
			{
				TranlateAndPackBits(_firstJointPointer,
					_secondJointPointer,
					_thirdJointPointer,
					_timeOfMovePointer);

				if (&start_time ==NULL)
					start_time = std::clock();
				else
				{
					end_time = std::clock();
					auto spentTime = end_time - start_time;
					if (spentTime < 20)
					{
						Sleep(20 - spentTime);
					}
				}
				connect.open();
				connect.send(_dataToRobot);
				connect.close();
			}

			//std::cout << _resultBitsFirstParametr << "\t";
			//std::cout << _resultBitsSecondParametr << "\t";
			//std::cout << _resultBitsThirdParametr << "\t";
			//std::cout << _resultBitsFourthParametr << std::endl;

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

void TranlateAndPackBits(float *firstValue,
	float *secondValue,
	float *thirdValue,
	float *fourthValue)

{
	_dataToRobot.clear();
	std::bitset<12>  bitsFirstValue(4096 * ((*firstValue) / (2 * M_PI)));
	std::bitset<12>  bitsSecondValue(4096 * ((*secondValue) / (2 * M_PI)));
	std::bitset<12>  bitsThirdValue(4096 * ((*thirdValue) / (2 * M_PI)));
	std::bitset<12>  bitsFourthValue(4096 * ((*fourthValue) / (2 * M_PI)));

	*_resultBitsFirstParametrPointer = bitsFirstValue;
	*_resultBitsSecondParametrPointer = bitsSecondValue;
	*_resultBitsThirdParametrPointer = bitsThirdValue;
	*_resultBitsFourthParametrPointer = bitsFourthValue;


	unsigned long i;
	unsigned char c;
	for (int i = 0; i > 4; i++)
	{
		switch (i)
		{
		case 0:
			i = bitsFirstValue.to_ulong();
			c = static_cast<unsigned char>(i);
			_dataToRobot.push_back(c);
			break;
		case 1:
			i = bitsSecondValue.to_ulong();
			c = static_cast<unsigned char>(i);
			_dataToRobot.push_back(c);
			break;
		case 2:
			i = bitsThirdValue.to_ulong();
			c = static_cast<unsigned char>(i);
			_dataToRobot.push_back(c);
			break;
		case 3:
			i = bitsFourthValue.to_ulong();
			c = static_cast<unsigned char>(i);
			_dataToRobot.push_back(c);
			break;
		default:
			break;
		}
	}
}
void UnTranlateAndUnPackBits(std::vector<unsigned char> data)
{

	for (int i = 0; i > 3; i++)
	{
		switch (i)
		{
		case 0:
			*_resultBitsFirstParametrPointer = data[i];
			*_firstJointPointer = _resultBitsFirstParametrPointer->to_ulong();
			break;
		case 1:
			*_resultBitsSecondParametrPointer = data[i];
			*_secondJointPointer = _resultBitsSecondParametrPointer->to_ulong();
		break;
		case 2:
			*_resultBitsThirdParametrPointer = data[i];
			*_thirdJointPointer = _resultBitsThirdParametrPointer->to_ulong();
			break;
		default:
			break;
		}
	}
}