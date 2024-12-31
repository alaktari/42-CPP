#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	secret;
		std::string	phone_number;
	public:
		void		new_contact(std::string user_input, int which);
		std::string	get_contact_infos(int which);
};

class PhoneBook
{
	private:
		Contact	contacts_arr[8];
		int		counter;
		int		curr_index;
	public:
				PhoneBook(void);
		int		add_contact(void);
		int		search_for_contact(void);
		void	print_added_contacts(void);
};

bool	is_allnum(std::string str);
int		is_empty(std::string *user_input, std::string str, std::string space);

#endif