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

	template<int N>
	struct FactorialImplTest {
		static void test() {
			std::cout << N << " -> " << FactorialImpl<N>::value << std::endl;
			FactorialImplTest<N - 1>::test();
		}
	};

	template<>
	struct FactorialImplTest<-1> {
		static void test() {}
	};


}
