#pragma once
#include "../IFactorial.h"

namespace v1 {
	class FactorialImpl : public IFactorial {
	public:
		FactorialImpl() = default;
		virtual ~FactorialImpl() = default;

		int getFactorial(int number) override;
	private:
		int getActualFactorial(int number);
		bool isInputValid(int number) const;
		bool isReturnTypeMaxRangeExceeded(long long result) const;
	};
}
namespace v2
{
	class FactorialImpl : public IFactorial
	{
	public:
		FactorialImpl() = default;
		virtual ~FactorialImpl() = default;

		int getFactorial(int number) override;
	private:
		int computeFactorial(int number) const;
	};
}
