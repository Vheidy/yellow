#include "date.h"

Date::Date (int new_year, int new_month, int new_day) {
	year = new_year;
	if (new_month > 12 || new_month < 1)
		throw runtime_error("Month value is invalid: " + to_string(new_month));
	month = new_month;
	if (new_day > 31 || new_day < 1)
		throw runtime_error("Day value is invalid: " + to_string(new_day));
	day = new_day;
}
int Date::GetYear() const { return year; }
int Date::GetMonth() const { return month; }
int Date::GetDay() const { return day; }

Date	ParseDate(istream& os){
	int year, month, day;
	try {
		string date;
		os >> date;
		istringstream is(date);
		bool ok = true;

		ok = ok && (is >> year);
		ok = ok && (is.peek() == '-');
		is.ignore(1);

		ok = ok && (is >> month);
		ok = ok && (is.peek() == '-');
		is.ignore(1);

		ok = ok && (is >> day);
		ok = ok && is.eof();
		
		if (!ok) 
			throw runtime_error("Wrong date format: " + date);
		Date(year, month, day);
	} catch (const exception& e) {
		cout << e.what() << endl;
	}
	return Date(year, month, day);
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() <<
	"-" << setw(2) << setfill('0') << date.GetMonth() <<
	"-" << setw(2) << setfill('0') << date.GetDay();
	return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
	vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
	vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
	vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
	vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
	vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
	vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}