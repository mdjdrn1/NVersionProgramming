#pragma once
#include <vector>
#include "src/IFibonacci.h"
#include "src/IFactorial.h"

struct VersionSelector {
	static const int ERROR_CODE = -3;

	static int getResultFibonacci(int input, std::vector<IFibonacci*> impls);
	static int getResultFactorial(int input, std::vector<IFactorial*> impls);
};

