#include "FactorialImpl.h"
#include <stdexcept>

int v1::FactorialImpl::getFactorial(int number) {
	if (!isInputValid(number)) {
		return ERROR_INPUT;
	}

	try {
		return getActualFactorial(number);
	}
	catch (const std::out_of_range& e) {
		return ERROR_COMPUTE;
	}
}

int v1::FactorialImpl::getActualFactorial(int number) {
	if (number == 0 || number == 1) {
		return 1;
	}

	auto result = number * getFactorial(number - 1);

	if (isReturnTypeMaxRangeExceeded(result)) {
		throw std::out_of_range("Return type max range exceeded");
	}

	return result;
}

bool v1::FactorialImpl::isInputValid(int number) const {
	return number >= 0;
}

bool v1::FactorialImpl::isReturnTypeMaxRangeExceeded(long long result) const {
	return result < 0;
}
