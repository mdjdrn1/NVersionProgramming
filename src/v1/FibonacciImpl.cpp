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

int v2::FibonacciImpl::getValue(int number)
{
	try {
		return computeFibonacci(number);
	}
	catch (std::invalid_argument e)
	{
		return ERROR_INPUT;
	}
	catch (std::out_of_range e)
	{
		return ERROR_COMPUTE;
	}
}

int v2::FibonacciImpl::computeFibonacci(int number) const
{
	if (number < 0) throw std::invalid_argument("Wrong input number.");

	int parent = 0, grandParent = 1, curent = number;

	for (int i = 2; i <= number; ++i)
	{
		curent = grandParent + parent;
		grandParent = parent;
		parent = curent;
	}
	if (number < 0) throw std::out_of_range("Return type max range exceeded");
	return curent;
}
