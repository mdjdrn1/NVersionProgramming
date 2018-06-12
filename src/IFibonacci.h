#pragma once

struct IFibonacci {
	static const int ERROR_INPUT = -1;
	static const int ERROR_COMPUTE = -2;
	// return: -1 when input is invalid; -2 when unable to compute result
	virtual int getValue(int number) = 0;

	virtual ~IFibonacci() = default;
};
