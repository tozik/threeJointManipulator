#include "pch.h"
#include "InteractionWithUser.h"
#include <iostream>

InteractionWithUser::InteractionWithUser()
{
}

void InteractionWithUser::PrintRequest()
{
	std::cout << "**********************************\n";
	std::cout << "\nChoose a method for calculating (working) \n";
	std::cout << "1 - Direct kinematics task\n";
	std::cout << "2 - Inverse kinematics task\n";
	std::cout << "**********************************\n";
	return;
}

InteractionWithUser::~InteractionWithUser()
{
}
