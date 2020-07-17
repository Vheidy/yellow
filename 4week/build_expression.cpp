#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void	ft_bracket(string& str) {
	str.insert(0, "(");
	str.insert(str.size(), ")");
}

int		main() {
	int x, q;
	cin >> x >> q;
	string str;
	str += to_string(x);
	if (q != 0) {
		ft_bracket(str);
	}
	for (int i = 0; i < q; i++) {
		string sign, val;
		cin >> sign >> val;
		if (sign == "+") {
			str += " + " + val;
			if (i + 1 != q)
				ft_bracket(str);
		} else if (sign == "-") {
			str += " - " + val;
			if (i + 1 != q)
				ft_bracket(str);
		} else if (sign == "*") {
			str += " * " + val;
			if (i + 1 != q)
				ft_bracket(str);
		} else if (sign == "/") {
			str += " / " + val;
			if (i + 1 != q)
				ft_bracket(str);
		}
	}
	cout << str << endl;
	return 0;
}