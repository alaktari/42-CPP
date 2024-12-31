#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	counter = 0;
	curr_index = 0;
}

int	PhoneBook::add_contact(void)
{
	std::string	user_input;

	std::string str[5] ={	"First Name", "Last Name", "Nickname",
		"Darkest Secret", "Phone Number"};
	std::string spaces[5] = {"    ", "     ", "      ", "", "  "};
	std::cout << std::endl;
	if (curr_index == 8)
		curr_index = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "      Enter " << str[i] << spaces[i] << "  : ";
		if (!getline(std::cin, user_input))
			return ((std::cout << "\nExiting the program..." << std::endl), 0);
		if (user_input.empty()) {
			if (!is_empty(&user_input, str[i], spaces[i]))
				return (0);
		}
		contacts_arr[curr_index].new_contact(user_input, (i + 1));
	}
	if (counter != 8)
		counter++;
	curr_index++;
	std::cout << std::endl;
	return ((std::cout << " [  The new contact has been added successfully  ]\n\n"), 1);
}

void	PhoneBook::print_added_contacts(void)
{
	int spaces;
	
	std::cout << "    index |First Name| LastName | NickName |\n";
	std::cout << "    ______|__________|__________|__________|\n";
	for (int index = 0; index < counter; index++)
	{
		std::cout << "         " << index << '|';
		for (int i = 1; i < 4; i++)
		{
			spaces = 10 - contacts_arr[index].get_contact_infos(i).length();
			if (spaces < 0)
			{
				std::cout << contacts_arr[index].get_contact_infos(i).substr(0, 9);
				std::cout << '.';
			}
			else
			{
				for (int x = 0; x < spaces; x++)
					std::cout << ' ';
				std::cout << contacts_arr[index].get_contact_infos(i);
			}
			std::cout << '|';
		}
		std::cout << std::endl;
		std::cout << "    ------|----------|----------|----------|\n";
	}
}

static	int input_index(std::string *user_input, int counter)
{
	int index;

	while (1)
	{
		std::cout << "Select the index of a contact you want to display: ";
		if (!getline(std::cin, *user_input))
		{
			std::cout << "\nExiting the program..." << std::endl;
			return (-1);
		}
		if (is_allnum(*user_input))
		{
			index = atoi((*user_input).c_str());
			if (index >= counter)
			{
				std::cout << "   ==>  Out of range [0, " << (counter - 1) << "]";
				std::cout << ", Please try again !!\n";
				continue ;
			}
			return index;
		}
		else if (!(*user_input).empty())
			std::cout << "BAD INPUT, TRY AGAIN PLEASE!!" << std::endl;
	}
}

int	PhoneBook::search_for_contact(void)
{
	std::string	user_input;
	int			index;
	std::string	str[6] = {
		"   First Name     : ", "   Last Name      : ",
		"   Nickname       : ", "   Darkest Secret : ", "   Phone Number   : "
	};
	std::cout << std::endl;
	print_added_contacts();
	std::cout << std::endl;
	index = input_index(&user_input, counter);
	if (index == -1)
		return (0);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << str[i] << contacts_arr[index].get_contact_infos(i + 1);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return (1);
}
