#pragma once
#include <vector>
#include <map>

struct VersionSelector {
	static const int ERROR_CODE = -3;

	static int getFinalResult(const std::vector<int>& values);
};

