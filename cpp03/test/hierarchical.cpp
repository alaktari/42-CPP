#include <iostream>
#include <string>

using namespace std;

class A
{
	private:
		int a;
		int b;
	public:
		A(int a, int b) : a(a), b(b) {};
		int get_a(void) { return a; }
		int get_b(void) { return b; }
};

class Sum : public A
{
	private:
		int sam;
	public:
		Sum(int a, int b) : A(a, b) {};
		void print_sum(void) { cout << "Sum: " << get_a() + get_b() << "\n"; }
};

class Multiple : public A
{
	private:
		int multiple;
	public:
		Multiple(int a, int b) : A(a, b) {};
		void print_miltiple(void) { cout << "Miltiple: " << get_a() * get_b() << "\n"; }
};

int main()
{
	int a = 2;
	int b = 4;
	Sum obj1(a, b);
	Multiple obj2(a, b);

	obj1.print_sum();
	obj2.print_miltiple();
}