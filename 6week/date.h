#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class Date {
public:
	Date(int new_day, int new_month, int new_year);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
private:
	int day, month, year;
};

Date	ParseDate(istream& is);

ostream& operator<<(ostream& stream, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);