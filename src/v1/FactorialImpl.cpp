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

int v2::FactorialImpl::getFactorial(int number)
{
	try {
		return computeFactorial(number);
	}catch(std::invalid_argument e)
	{
		return ERROR_INPUT;
	}
	catch(std::out_of_range e)
	{
		return ERROR_COMPUTE;
	}
}

int v2::FactorialImpl::computeFactorial(int number) const
{
	if (number < 0) throw std::invalid_argument("Wrong input number.");

	int returnValue = FACTORIA_START_VALUE;
	for (int i = FACTORIA_START_VALUE; i <= number; ++i)
	{
		returnValue *= i;
	}
	if (returnValue < 0) throw std::out_of_range("Return type max range exceeded");
	return returnValue;
}
