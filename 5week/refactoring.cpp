#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& new_name = "NoName", const string& new_type = "Person") :
    Name(new_name),
    type(new_type) {
    }
    virtual void Walk(const string& destination) {
        cout << type << ": " << Name << " walks to: " << destination << endl;
    }
    void Fast() {
        cout << type << ": " << Name;
    }

    const string Name;
    const string type;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) : 
    Person(name, "Student"),
    FavouriteSong(favouriteSong) {}

    void Walk(const string& destination) override {
        Fast();
        cout << " walks to: " << destination << endl;
        SingSong();
    }

    void Learn() {
        Fast();
        cout << " learns" << endl;
    }

    void SingSong() {
        Fast();
        cout << " sings a song: " << FavouriteSong << endl;
    }



private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) : Subject(subject),
    Person(name, "Student") {}
    void Teach() {
        Fast();
        cout << " teaches: " << Subject << endl;
    }
private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Student") {}

    void Check(const Person& p) {
        Fast();
        cout << " checks " << p.type << ". " << p.type << "'s name is: " << p.Name << endl;
    }
};

void VisitPlaces(Person& p, const vector<string>& places) {
    for (auto m : places) {
        p.Walk(m);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
