#include "VersionSelector.h"
#include <map>


int VersionSelector::getResultFibonacci(int input, std::vector<IFibonacci*> impls) {
	std::map<int, int> results;
	for(auto impl : impls) {
		auto result = impl->getValue(input);
		auto it = results.find(result);
		if(it != results.end()) {
			++it->second;
		} else {
			results[result] = 1;
		}
	}

	for(auto r : results) {
		if(r.second >= 2) {
			return r.first;
		}
	}

	return ERROR_CODE;
}

int VersionSelector::getResultFactorial(int input, std::vector<IFactorial*> impls) {
	std::map<int, int> results;
	for (auto impl : impls) {
		auto result = impl->getFactorial(input);
		auto it = results.find(result);
		if (it != results.end()) {
			++it->second;
		}
		else {
			results[result] = 1;
		}
	}

	for (auto r : results) {
		if (r.second >= 2) {
			return r.first;
		}
	}

	return ERROR_CODE;
}
