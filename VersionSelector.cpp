#include "VersionSelector.h"
#include <map>

int VersionSelector::getFinalResult(const std::vector<int>& values)
{
	std::map<int, int> results;
	for (auto value : values) {
		auto it = results.find(value);
		if (it != results.end()) {
			it->second++;
		}
		else {
			results[value] = 1;
		}
	}
	if (results.size() == values.size()) {
		return ERROR_CODE;
	}
	std::pair<int, int> finalResult;
	for (auto result : results) {
		finalResult = result.second > finalResult.second ? result : finalResult;
	}
	return finalResult.first;
}
