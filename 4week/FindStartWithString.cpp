#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
	if (prefix.empty())
		return {range_begin, range_begin};
	auto beg = lower_bound(range_begin, range_end, prefix);
	string tmp = prefix;
	++tmp[tmp.size() - 1];
	auto end = lower_bound(range_begin, range_end, tmp);
	return {beg, end};
}

