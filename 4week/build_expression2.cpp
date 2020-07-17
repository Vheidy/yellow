#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <deque>

using namespace std;

using namespace std;

void	ft_bracket(deque<string>& str) {
	str.push_back(")");
	str.push_front("(");
}

bool	ft_priority(const stack<string>& sign, const string& cur) {
	map<string, int> priority = {{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};
	if (priority[cur] > priority.at(sign.top())) {
		return true;
	} else {
		return false;
	}
}

int		main() {
	int x, q;
	cin >> x >> q;
	stack<string> sig;
	deque<string> str;
	// string str;
	str.push_back(to_string(x));
	for (int i = 0; i < q; i++) {
		string sign, val;
		cin >> sign >> val;
		if (i != 0 && ft_priority(sig, sign))
				ft_bracket(str);
		sig.push(sign);
		if (sign == "+") {
			str.push_back(" + ");
			str.push_back(val);
			// str += " + " + val;
		} else if (sign == "-") {
			str.push_back(" - ");
			str.push_back(val);
			// str += " - " + val;
		} else if (sign == "*") {
			str.push_back(" * ");
			str.push_back(val);
			// str += " * " + val;
		} else if (sign == "/") {
			str.push_back(" / ");
			str.push_back(val);
			// str += " / " + val;
		}
	}
	for (const auto& i : str) {
		cout << i;
	}
	cout << endl;
	return 0;
}