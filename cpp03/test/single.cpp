// single inheritence

#include <iostream>
using namespace std;

class A
{
    private:
        int age;
        string name;
    public:
        ~A(void) { cout << "===> Destruct called\n"; }
        void set(string name, int age);
        void print(void);
};

void A::set(string name, int age)
{
    this->name = name;
    this->age = age;
}

void A::print(void)
{
    cout << "name: " << name << " || age: " << age << "\n";
}

class B : protected A
{
    private:
        int grade;
    public:
        void sett(string name, int age, int grade)
        {
            set(name, age);
            this->grade = grade;
        }
        void display(void)
        {
            print();
            cout << "grade: " << grade << "\n";
        };
        using A::set;

};

int main()
{
    B obj;

}