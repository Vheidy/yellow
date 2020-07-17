#include <map>
#include <iostream>
#include <string>

using namespace std;

string  Find_Name(int year, const map<int, string>& name) {
    auto nm = name.upper_bound(year);
    if (nm != name.begin())
        return (--nm)->second;
    return "";
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
      first[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      last[year] = last_name;
  }
  string GetFullName(int year) {
      const string first_name = Find_Name(year, first);
      const string last_name = Find_Name(year, last);
      if (!first_name.empty() && !last_name.empty()) {
          return first_name + " " + last_name;
      } else if (first_name.empty() && !last_name.empty()) {
          return last_name + " with unknown first name";
      } else if (!first_name.empty() && last_name.empty()) {
        return first_name + " with unknown last name";
      } else {
           return "Incognito";
      }
  }
private:
  map<int, string> first;
  map<int, string> last;
};
