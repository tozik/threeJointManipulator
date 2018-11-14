#include "pch.h"
#include "Calculating.h"
#include <cmath>
#include <iostream>

int _shoulderLength = 10;
int _cubitLength = 5;
int _handBrushLength = 5;

float _twist1 = M_PI / 2;
float _twist2 = 0;
float _twist3 = 0;

Calculating::Calculating()
{
}

void Calculating::CalculateInverseTask(float* _xPointer, float* _yPointer, float* _zPointer,
	float *_firstJoint, float *_secondJoint, float *_thirdJoint)
{
	double _alphaProjectionLength = pow(std::pow(*_xPointer, 2) + std::pow(*_yPointer, 2), 0.5);
	double _beta = (pow(_alphaProjectionLength, 2) + pow(*_zPointer, 2) + pow(_cubitLength, 2) - pow(_cubitLength, 3)) / (2 * _cubitLength);

	double _xoyProjectionDobble = (pow(*_xPointer, 2) + pow(*_yPointer, 2));

	double _xoyProjection = pow(_xoyProjectionDobble, 0.5);
	double _z0Projection = *_zPointer - _shoulderLength;

	double _radiusVectorToPointFromZero = pow((pow(_xoyProjection, 2) + pow(_z0Projection, 2)), 0.5);

	double  _alphaAngleForCubit = acos((pow(_cubitLength, 2) + pow(_radiusVectorToPointFromZero, 2) - pow(_handBrushLength, 2)) / (2 * _cubitLength*_radiusVectorToPointFromZero));
	double  _betaAngleForHandBrush = acos((_cubitLength*_cubitLength + _handBrushLength * _handBrushLength - _radiusVectorToPointFromZero * _radiusVectorToPointFromZero) / (2 * _cubitLength*_handBrushLength));

	//All joints showing radians measure
	*_firstJoint = (atan((*_yPointer / *_xPointer)));
	*_secondJoint = (asin(_z0Projection / _xoyProjection) + _alphaAngleForCubit);
	*_thirdJoint = (M_PI - (_betaAngleForHandBrush));

	std::cout << "\nValue J1=" << *_firstJoint << " in radians";
	std::cout << "\t\tValue J2=" << *_secondJoint << " in radians";
	std::cout << "\t\tValue J3=" << *_thirdJoint << " in radians";
}

void Calculating::CalculateInverseTaskNotPtr(float* _xPointer, float* _yPointer, float* _zPointer,
	float _firstJoint, float _secondJoint, float _thirdJoint)
{
	double _alphaProjectionLength = pow(std::pow(*_xPointer,2) + std::pow(*_yPointer,2), 0.5);
	double _beta = (pow(_alphaProjectionLength,2) + pow(*_zPointer,2) + pow(_cubitLength,2) - pow(_cubitLength, 3)) / (2 * _cubitLength);

	double _xoyProjectionDobble = (pow(*_xPointer,2) + pow(*_yPointer,2));

	double _xoyProjection = pow(_xoyProjectionDobble, 0.5);
	double _z0Projection = *_zPointer - _shoulderLength;

	double _radiusVectorToPointFromZero = pow((pow(_xoyProjection,2) + pow(_z0Projection,2)), 0.5);

	double  _alphaAngleForCubit = acos((pow(_cubitLength,2) + pow(_radiusVectorToPointFromZero,2) - pow(_handBrushLength,2)) / (2 * _cubitLength*_radiusVectorToPointFromZero));
	double  _betaAngleForHandBrush = acos((_cubitLength*_cubitLength + _handBrushLength * _handBrushLength - _radiusVectorToPointFromZero * _radiusVectorToPointFromZero) / (2 * _cubitLength*_handBrushLength));

	//All joints showing degres measure
	_firstJoint = (atan((*_yPointer / *_xPointer))) * 180 / M_PI;
	_secondJoint = (asin(_z0Projection / _xoyProjection) + _alphaAngleForCubit) * 180 / M_PI;
	_thirdJoint = (M_PI - (_betaAngleForHandBrush)) * 180 / M_PI;

	std::cout << "\nValue J1=" << _firstJoint << " in degrees";
	std::cout << "\t\tValue J2=" << _secondJoint << " in degrees";
	std::cout << "\t\tValue J3=" << _thirdJoint << " in degrees";
}

void Calculating::CalculateDirectTask(float* _firstJointPointer, float* _secondJointPointer, float* _thirdJointPointer,
	float* _x, float* _y, float* _z)
{
	*_x = std::cos(*_firstJointPointer)*
		((_cubitLength*std::cos(*_secondJointPointer)) + (_handBrushLength*std::cos(*_secondJointPointer + *_thirdJointPointer)));
	*_y = std::sin(*_firstJointPointer)*
		((_cubitLength*std::cos(*_secondJointPointer)) + (_cubitLength*std::cos(*_secondJointPointer + *_thirdJointPointer)));
	*_z = _shoulderLength +
		((_cubitLength*std::sin(*_secondJointPointer)) + (_handBrushLength*std::sin(*_secondJointPointer + *_thirdJointPointer)));

	std::cout << "\nValue X=" << *_x;
	std::cout << "\tValue Y=" << *_y;
	std::cout << "\tValue Z=" << *_z;

}

void Calculating::CalculateDirectTaskNotPtr(float* _firstJointPointer, float* _secondJointPointer, float* _thirdJointPointer,
	float _x, float _y, float _z)
{
	_x = std::cos(*_firstJointPointer)*
		((_cubitLength*std::cos(*_secondJointPointer)) + (_handBrushLength*std::cos(*_secondJointPointer + *_thirdJointPointer)));
	_y = std::sin(*_firstJointPointer)*
		((_cubitLength*std::cos(*_secondJointPointer)) + (_cubitLength*std::cos(*_secondJointPointer + *_thirdJointPointer)));
	_z = _shoulderLength +
		((_cubitLength*std::sin(*_secondJointPointer)) + (_handBrushLength*std::sin(*_secondJointPointer + *_thirdJointPointer)));

	std::cout << "\nValue X=" << _x;
	std::cout << "\tValue Y=" << _y;
	std::cout << "\tValue Z=" << _z;

}

Calculating::~Calculating()
{
}
