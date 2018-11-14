
#include "pch.h"
#include "ReadingClass.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string fileName= "C:\\Users\\tozik\\OneDrive\\Рабочий стол\\RemyRotics\\input.in";
ifstream _fileReader;
vector<float> pointsOfMoving;

ReadingClass::ReadingClass()
{
	cout << "\nTrying to open file input.in with data about trajectory\n";
	cout << "With adress\n" << fileName<<"\n";
	_fileReader.open(fileName);
}

void ReadingClass::GetLineInstructionsFromFile(vector<float> *pointsPointerFromMain)
{
	if (_fileReader.is_open())
	{
		std::string value;
		value.assign((std::istreambuf_iterator<char>(_fileReader.rdbuf())), std::istreambuf_iterator<char>());
		_fileReader.close();
		cout << "\nReading finished\n";

		string element;
		stringstream ss(value);									//initialise string stream
		while (ss >> element)
			pointsPointerFromMain->push_back(::atof(element.c_str()));
		
		//Debug information about data from file with trajectory
		//for (int i = 0; i < pointsOfMoving.size(); i++)
		//	cout << "Component " << i + 1 << " : " << pointsOfMoving[i] << endl;
	
	}
	else
		std::cerr << "Unable to open file" << std::endl;
}

ReadingClass::~ReadingClass()
{
	_fileReader.close();
}
