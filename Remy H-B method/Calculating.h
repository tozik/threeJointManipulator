#pragma once
#define _USE_MATH_DEFINES
#include <math.h>]

# define M_PI           3.14159265358979323846  /* pi */
class Calculating
{
public:

	Calculating();
	void CalculateDirectTask(float*,float*,float*, float*, float*, float*);
	void static CalculateInverseTask(float*, float*, float*, float*, float*, float*);
	//void CalculateDirectTask(float, float, float, float*, float*, float*);
	void static CalculateDirectTaskNotPtr(float*, float*, float*, float, float, float);
	void static CalculateInverseTaskNotPtr(float*, float*, float*, float, float, float);
	void taskCalc(float* );
	~Calculating();
};

