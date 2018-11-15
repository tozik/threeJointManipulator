#pragma once
#include <vector>
#include <string>

class ReadingClass
{
public:

	ReadingClass(std::string name);
	void GetLineInstructionsFromFile(std::vector<float> *);
	~ReadingClass();
};

