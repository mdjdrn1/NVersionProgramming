#pragma once
#include "ErrorCodes.h"

namespace v1 {
	class FactorialImpl {
	public:
		FactorialImpl() = default;
		virtual ~FactorialImpl() = default;

		int getFactorial(const int number);
	private:
		int getActualFactorial(int number);
		bool isInputValid(int number) const;
		bool isReturnTypeMaxRangeExceeded(long long result) const;
	};
}

namespace v2
{
	class FactorialImpl {
		static const int FACTORIA_START_VALUE = 1;
	public:
		FactorialImpl() = default;
		virtual ~FactorialImpl() = default;

		int getFactorial(const int number);
	private:
		int computeFactorial(const int number) const;
	};
}

namespace v3
{
	template <int N>
	struct FactorialImpl
	{
		enum { value = N * FactorialImpl<N - 1>::value };
	};

	template <>
	struct FactorialImpl<0>
	{
		enum { value = 1 };
	};
	template <>
	struct FactorialImpl<-1>
	{
		enum { value = ERROR_INPUT };
	};

	template<int N>
	struct FactorialImplTest {
		static void test() {
			std::cout << FactorialImpl<N>::value << std::endl;
			FactorialImplTest<N + 1>::test();
		}
	};

	template<>
	struct FactorialImplTest<21> {
		static void test() {}
	};


}
