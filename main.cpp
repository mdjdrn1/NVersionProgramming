#include <iostream>
#include "src\v1\FactorialImpl.h"
#include "src\v1\FibonacciImpl.h"
#include <memory>
#include "VersionSelector.h"

void testFibo_v1();
void testFact_v1();
void testFibo_v2();
void testFact_v2();
void testFibo_v3();
void testFact_v3();

constexpr int getTestedValue() {
	return 10;
}

int main() {
	//testFibo_v1();
	//testFact_v1();
	//testFibo_v2();
	//testFact_v2();
	//testFibo_v3();
	//testFact_v3();

	v1::FactorialImpl factorial_v1;
	v2::FactorialImpl factorial_v2;
	std::cout << VersionSelector::getFinalResult({
		factorial_v1.getFactorial(getTestedValue()),
		factorial_v2.getFactorial(getTestedValue()),
		v3::FactorialImpl<getTestedValue()>::value
	}) << std::endl;

	v1::FibonacciImpl fibonacci_v1;
	v2::FibonacciImpl fibonacci_v2;
	std::cout << VersionSelector::getFinalResult({
		fibonacci_v1.getValue(getTestedValue()),
		fibonacci_v2.getValue(getTestedValue()),
		v3::FibonacciImpl<getTestedValue()>::value
	}) << std::endl;

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

//Testing values from -1 to 20 - can't handle range errors in this algorithm 
void testFibo_v3()
{
	v3::FibonacciImplTest<-1>::test();
}

//Testing values from -1 to 20 - can't handle range errors in this algorithm 
void testFact_v3()
{
	v3::FactorialImplTest<-1>::test();
}