
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
	_fileReader.open(fileName);
}

void ReadingClass::GetLineInstructionsFromFile()
{
	if (_fileReader.is_open())
	{
		std::string value;
		value.assign((std::istreambuf_iterator<char>(_fileReader.rdbuf())), std::istreambuf_iterator<char>());
		cout << "\nReading finished\n";
		//std::cout << value;
		_fileReader.close();

		string element;
		stringstream ss(value);									//initialise string stream
		while (ss >> element)
			pointsOfMoving.push_back(::atof(element.c_str()));
		for (int i = 0; i < pointsOfMoving.size(); i++)
			cout << "Component " << i + 1 << " : " << pointsOfMoving[i] << endl;
	}
	else
		std::cerr << "Unable to open file" << std::endl;
}

ReadingClass::~ReadingClass()
{
	_fileReader.close();
}
