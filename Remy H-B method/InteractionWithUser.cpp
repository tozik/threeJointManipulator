#include "pch.h"
#include "InteractionWithUser.h"
#include <iostream>

InteractionWithUser::InteractionWithUser()
{
}

void InteractionWithUser::PrintRequest()
{
	std::cout << "**********************************\n";
	std::cout << "Please, if you want get a result for inverse task\n";
	std::cout <<"put the input.in file to directory C: ";
	std::cout << "if you want use another directory, change the code please\n ";
	std::cout << "\n**********************************\n";
	std::cout << "\nChoose a method for calculating (working) \n";
	std::cout << "1 - Direct kinematics task\n";
	std::cout << "2 - Inverse kinematics task\n";
	std::cout << "**********************************\n";
	return;
}

InteractionWithUser::~InteractionWithUser()
{
}
