#pragma once

struct IFactorial {
	// return: -1 when input is invalid; -2 when unable to calculate
	virtual int getFactorial(int number) = 0;

	virtual ~IFactorial() = default;
};
