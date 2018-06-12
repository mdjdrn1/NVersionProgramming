#pragma once

struct IFibonacci {
	// return: -1 when input is invalid; -2 when unable to calculate
	virtual int getValue(int number) = 0;

	virtual ~IFibonacci() = default;
};
