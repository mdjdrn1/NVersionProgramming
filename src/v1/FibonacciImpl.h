#pragma once
#include "ErrorCodes.h"

namespace v1 {
	class FibonacciImpl {
	public:
		FibonacciImpl() = default;
		virtual ~FibonacciImpl() = default;

		int getValue(int number);
	private:
		int getActualValue(int number);
		bool isInputValid(long long number) const;
		bool isReturnTypeMaxRangeExceeded(long long result) const;
	};
}

namespace v2
{
	class FibonacciImpl {
	public:
		FibonacciImpl() = default;
		virtual ~FibonacciImpl() = default;

		int getValue(int number);
	private:
		int computeFibonacci(int number) const;
	};
}

namespace v3 {
	template <int T>
	struct FibonacciImpl
	{
		enum { value = (FibonacciImpl<T - 1>::value + FibonacciImpl<T - 2>::value) };
	};
	template <>
	struct FibonacciImpl<-1>
	{
		enum { value = ERROR_INPUT };
	};

	template <>
	struct FibonacciImpl<0>
	{
		enum { value = 1 };
	};

	template <>
	struct FibonacciImpl<1>
	{
		enum { value = 1 };
	};

	template <>
	struct FibonacciImpl<2>
	{
		enum { value = 1 };
	};

	template <int T>
	struct FibonacciImplTest {
		static void test() {
			std::cout << FibonacciImpl<T>::value << " ";
			FibonacciImplTest<T - 1>::test();
		}
	};
	template <>
	struct FibonacciImplTest<-2> {
		static void test() {
		}
	};
}