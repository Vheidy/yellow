#pragma once
#include "date.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Database {
public:
	void	Add(const Date& data, const string& event); // добавить событие в бау данных по дате
	void	Print(ostream& os) const; // вывести все текущие события
	template<typename Predicate> int RemoveIf(const Predicate& predicate) {
		int res = 0;
		map<Date, set<string>> new_base;
		map<Date, vector<string>> new_order;
		for (const auto& i : order) {
			const auto it = stable_partition(i.second.begin(), i.second.end(),
			[predicate, i](const auto& item){
				return predicate(i.first, item);
			});
			const int tmp = i.second.size();
			if (it == i.second.end()) {
				res += tmp;
			} else {
				new_order[i.first] = vector<string>(it, i.second.end());
				new_base[i.first] = set<string> (it, i.second.end());
				res += tmp - new_order.at(i.first).size();
			}
		}
		base = new_base;
		order = new_order;
		return res;
	}
	template<typename Predicate> vector<pair<Date, string>> FindIf(const Predicate& predicate) const {
		map<Date, vector<string>> tmp;
		vector<pair<Date, string>> res;
		for (const auto& i : order) {
			vector<string> v;
			copy_if(i.second.begin(), i.second.end(), back_inserter(v),
			[predicate, i](const auto& item) {
				return predicate(i.first, item);
			});
			if (v.size() != 0)
				tmp[i.first] = v;
		}
		for (const auto& i : tmp) {
			for (const string& item : i.second) {
				res.push_back(make_pair(i.first, item));
			}
		}
		return res;
	}
	pair<Date, string>	Last(Date data);
private:
	map<Date, vector<string>> order;
	map<Date, set<string>> base;
};

ostream& operator<<(ostream& os, const pair<Date, vector<string>>& pair_);

bool operator<(const pair<Date, string>& left, const pair<Date, string>& right);

bool operator==(const pair<Date, string>& left, const pair<Date, string>& right);

ostream& operator<<(ostream& stream, pair<Date, string> item);