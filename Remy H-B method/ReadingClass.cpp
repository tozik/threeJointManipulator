
#include "pch.h"
#include "ReadingClass.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
string fileName= "C:\\Users\\tozik\\OneDrive\\Рабочий стол\\RemyRotics\\input.in";
std::ifstream _fileReader;

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
		std::cout << value;
		_fileReader.close();
	}
	else
		std::cerr << "Unable to open file" << std::endl;

}

ReadingClass::~ReadingClass()
{
	_fileReader.close();
}
