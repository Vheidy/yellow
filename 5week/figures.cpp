#include <iostream>
#include <istream> 
#include <sstream> 
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure {
public:
	virtual string Name () const = 0;
	virtual double Perimeter () const = 0;
	virtual double Area () const = 0;
};

class Triangle : public Figure {
public:
	Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
	string Name() const override { return "TRIANGLE"; }
	double Perimeter () const override { return (a + b + c); }
	double Area () const override {
		double p;
		p = (a + b + c) / 2.0;
		return (sqrtl(p * (p - a) * (p - b) * (p - c)));
	}
private:
	const double a, b, c;
};

class Rect : public Figure {
public:
	Rect (double x, double y) : width(x), height(y) {}
	string Name() const override { return "RECT"; }
	double Perimeter () const override { return ((width + height) * 2); }
	double Area () const override { return (width * height); }
private:
	const double width, height;
};

class Circle : public Figure {
public:
	Circle(double r) : radius(r) {}
	string Name() const override {return "CIRCLE"; }
	double Perimeter () const override { return(2 * 3.14 * radius); }
	double Area () const override { return (3.14 * radius * radius); }
private:
	const double radius;
};

shared_ptr<Figure>	CreateFigure(istringstream& is) {
	string fig;
	is >> fig;
	if (fig == "RECT") {
		double a, b;
		is >> a >> b;
		return make_shared<Rect>(a, b);
	} else if (fig == "TRIANGLE") {
		double a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	} else if (fig == "CIRCLE") {
		double r;
		is >> r;
		return make_shared<Circle>(r);
	}
	return 0;
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
			is >> ws;
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
				 << current_figure->Name() << " "
				 << current_figure->Perimeter() << " "
				 << current_figure->Area() << endl;
			}
		}
	}
	return 0;
}