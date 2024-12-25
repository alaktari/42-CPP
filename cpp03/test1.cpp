#include <iostream>
#include <cstdio>

using namespace std;

class A
{
    protected:
        string  name;
        int     age;
        int     level;
    public:
        A (string name) : name(name), age(22), level(3) {};
        void eat(void) { cout << "I'm eating.\n"; }
        void sleep(void) { cout << "I'm sleeping.\n"; }
        void play(void) { cout << "I'm playing.\n"; }
};


class A1: virtual public A
{
    public:
        void eat(void) { cout << "I'm not eating\n"; }
        A1 (string name) : A(name) {}
};

class A2: virtual public A
{
    public:
        A2(string name) : A(name) {}
        void sleep() { cout << "I'm not sleeping.\n"; }
};

class MyClass: public A1, public A2
{
    private:
        string name;
    public:
        MyClass(string name) : A(name), A1(name + "_clap_name"), A2(name), name(name) {}
        void    message(void) { cout << " Hello I'm " << name << "\n"; }

        void printDetails() {
        cout << "Name: " << A1::name << "\n"; // From A1
        cout << "Level: " << A1::level << "\n"; // From A1
        cout << "Age: " << A2::age << "\n";   // From A2
    }

};


int main()
{
    MyClass obj("karim");
    obj.printDetails();
    return 0;
}