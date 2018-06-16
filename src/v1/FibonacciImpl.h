#pragma once
#include "../IFibonacci.h"

namespace v1 {
	class FibonacciImpl : public IFibonacci {
	public:
		FibonacciImpl() = default;
		virtual ~FibonacciImpl() = default;

		int getValue(int number) override;
	private:
		int getActualValue(int number);
		bool isInputValid(long long number) const;
		bool isReturnTypeMaxRangeExceeded(long long result) const;
	};
}

namespace v2
{
	class FibonacciImpl : public IFibonacci {
	public:
		FibonacciImpl() = default;
		virtual ~FibonacciImpl() = default;

		int getValue(int number) override;
	private:
		int computeFibonacci(int number) const;
	};
}
