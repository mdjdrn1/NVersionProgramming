#include "FibonacciImpl.h"
#include <stdexcept>

int v1::FibonacciImpl::getValue(int number) {
	if (!isInputValid(number)) {
		return ERROR_INPUT;
	}

	try {
		return getActualValue(number);
	}
	catch (const std::out_of_range& e) {
		return ERROR_COMPUTE;
	}
}

int v1::FibonacciImpl::getActualValue(int number) {
	if (number == 0 || number == 1) {
		return number;
	}

	auto result = getActualValue(number - 1) + getActualValue(number - 2);

	if (isReturnTypeMaxRangeExceeded(result)) {
		throw std::out_of_range("Return type max range exceeded");
	}

	return result;
}

bool v1::FibonacciImpl::isInputValid(long long number) const {
	return number > 0;
}

bool v1::FibonacciImpl::isReturnTypeMaxRangeExceeded(long long result) const {
	return result < 0;
}
