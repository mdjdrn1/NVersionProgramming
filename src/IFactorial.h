#pragma once

struct IFactorial {
	static const int ERROR_INPUT = -1;
	static const int ERROR_COMPUTE = -2;
	static const int FACTORIA_START_VALUE = 1;
	// return: -1 when input is invalid; -2 when unable to compute result
	virtual int getFactorial(int number) = 0;

	virtual ~IFactorial() = default;
};
