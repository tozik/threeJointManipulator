#pragma once
class Packing
{
public:
	Packing();
	static void TranlateAndPackBits(
		float *,
		float *,
		float *,
		float *);
	static void UnTranlateAndUnPackBits(
		float *,
		float *,
		float *,
		float *);
	~Packing();
};

