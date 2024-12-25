#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class A
{
	private:
		string name;
	public:
		A(string name) : name(name){ cout << "Construct A called\n"; }
		void print(void) { cout << "==> " << name << "\n"; }
};

class A1 : virtual public A
{
	public:
		A1(string name) : A(name)
		{ cout << "A1 constructor called\n";
		//   cout << "add in A1 ==> " << (A*)this << "\n";
		}
};

class A2 : virtual public A
{
	public:
		A2(string name) : A(name)
		{ cout << "A2 constructor called\n";
		//   cout << "add in A2 ==> " << (A*)this << "\n";
		}
};

class B : public A1, public A2
{
	public:
		B(string name) :A1(name), A2(name), A(name) // here
		{ cout << "b constructor called\n"; }
};

int main()
{
	B obj("karim");
	obj.A1::print();
}