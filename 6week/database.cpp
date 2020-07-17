#include "database.h"
#include <algorithm>
#include <iostream>

using namespace std;

void	Database::Add(const Date& data, const string& event){
	base[data].insert(event);
	if (count(begin(order[data]), end(order[data]), event) == 0)
		order[data].push_back(event);
}
void	Database::Print(ostream& os) const{
	for (const auto& i : order) {
		for (const auto& j : i.second) {
			os << i.first << " " << j << endl;
		}
	}
}
template<typename Predicate> int Database::RemoveIf(Predicate predicate){}
template<typename Predicate> vector<pair<Date, string>>	Database::FindIf(Predicate predicate){}
pair<Date, string>	Database::Last(Date data){
	auto it = order.upper_bound(data);
	if (it == begin(order))
		throw invalid_argument("No entries");
	else {
		it--;
		string res;
		return make_pair(it->first, it->second.back());
	}
}

ostream& operator<<(ostream& os, const pair<Date, vector<string>>& pair_)
{
	for (const auto& item : pair_.second)
	{
		os << pair_.first << " " << item << endl;
	}

	return os;
}


bool operator<(const pair<Date, string>& left, const pair<Date, string>& right)
{
	return left.first < right.first;
}


bool operator==(const pair<Date, string>& left, const pair<Date, string>& right)
{
	return left.first == right.first && right.second == left.second;
}

ostream& operator<<(ostream& stream, pair<Date, string> item) {
	stream << item.first << " " << item.second << endl;
	return stream;
}