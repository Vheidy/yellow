#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& t) : Name(t){}
    const string Name;
};


class Dog : public Animal{
public:
	Dog(const string& i) : Animal(i){}
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

// int main() {
// 	Dog d("Bax");
// 	d.Bark();
// 	return 0;
// }