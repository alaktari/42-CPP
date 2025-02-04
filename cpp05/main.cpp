#include "Bureaucrat.hpp"

void TooLow(void)
{
	try
	{
		Bureaucrat obj("test1", 150);
		std::cout << obj << "\n";
		obj.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
}

void    TooHigh(void)
{
	try
	{
		Bureaucrat obj("test2", 1);
		std::cout << obj << "\n";
		obj.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
}

int main()
{
	TooLow();
	TooHigh();
}