#include <iostream>
#include "src/IFibonacci.h"
#include "src/v1/FibonacciImpl.h"
#include "src/IFactorial.h"
#include "src/v1/FactorialImpl.h"
#include <memory>
#include "VersionSelector.h"

void testFibo_v1();
void testFact_v1();
void testFibo_v2();
void testFact_v2();

int main() {
	//	testFibo_v1();
	//	testFact_v1();

	// testFibo_v2();
	// testFact_v2();

	std::cout << VersionSelector::getResultFibonacci(3, { new v1::FibonacciImpl{}, new v2::FibonacciImpl{}, new v1::FibonacciImpl{} }) << std::endl;
	std::cout << VersionSelector::getResultFactorial(10, { new v1::FactorialImpl{}, new v2::FactorialImpl{}, new v1::FactorialImpl{} }) << std::endl;

	getchar();
	return 0;
}

void testFibo_v1() {
	auto fibo = std::make_unique<v1::FibonacciImpl>();
	for (int i = -1; i <= 20; ++i) {
		std::cout << "Fibo " << i << " " << fibo->getValue(i) << std::endl;
	}
}

void testFact_v1() {
	auto fact = std::make_unique<v1::FactorialImpl>();

	for (int i = -1; i <= 20; ++i) {
		std::cout << "Fact " << i << " " << fact->getFactorial(i) << std::endl;
	}
}

void testFibo_v2()
{
	auto fibo = std::make_unique<v2::FibonacciImpl>();
	for (int i = -1; i <= 20; ++i) {
		std::cout << "Fibo " << i << " " << fibo->getValue(i) << std::endl;
	}
}

void testFact_v2()
{
	auto fact = std::make_unique<v2::FactorialImpl>();

	for (int i = -1; i <= 20; ++i) {
		std::cout << "Fact " << i << " " << fact->getFactorial(i) << std::endl;
	}
}
