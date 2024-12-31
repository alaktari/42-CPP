#include "Phonebook.hpp"

int main()
{
	PhoneBook		phonebook;
	std::string		command;
	int				checker;

	std::cout << "===================================\n\n";
	std::cout << "Enter one of these commands: \n\n";
	std::cout << "  ==> [ADD, SEARCH, EXIT] <== \n\n";
	while (1)
	{
		std::cout << "ENTER YOUR COMMAND HERE: ";
		if (!getline(std::cin, command))
		{
			std::cout << std::endl;
			std::cout << "Exiting the program..." << std::endl;
			break ;
		}
		if (command.empty())
			continue;
		else if (command == "ADD")
			checker = phonebook.add_contact();
		else if (command == "SEARCH")
			checker = phonebook.search_for_contact();
		else if (command == "EXIT")
			return ((std::cout << "Exiting the program..." << std::endl), 0);
		else
		{
			command = "";
			std::cout << "Bad input command, Try again please!!\n";
		}
		if (!checker)
			return (1);
	}
}