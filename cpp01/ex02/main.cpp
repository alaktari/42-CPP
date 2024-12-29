#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	////  Printing memory addresses ///////////
	std::cout << '\n' << std::setfill('_') << std::setw(46) << "|< Printing memory addresses ";
	std::cout << ">|" << std::setfill('_') << std::setw(11) << '\n';
	std::cout << "The memory address of the string variable : ";
	std::cout << &brain << std::endl;
	std::cout << "The memory address held by stringPTR      : ";
	std::cout << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      : ";
	std::cout << &stringREF << std::endl;
	std::cout << std::setfill('=') << std::setw(60) << "\n\n";

	////  Printing the Values  /////////////////
	std::cout << std::setfill('_') << std::setw(37) << "|< Printing values ";
	std::cout << ">|" << std::setfill('_') << std::setw(22) << '\n';
	std::cout << "The value of the string variable          : ";
	std::cout << brain << std::endl;
	std::cout << "The value pointed by stringPTR            : ";
	std::cout << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : ";
	std::cout << stringREF << std::endl;
	std::cout << std::setfill('=') << std::setw(62) << "\n\n";
}
