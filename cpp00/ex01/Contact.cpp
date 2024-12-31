#include "Phonebook.hpp"

void	Contact::new_contact(std::string user_input, int which)
{
	if (which == 1)
		first_name = user_input;
	else if (which == 2)
		last_name = user_input;
	else if (which == 3)
		nickname = user_input;
	else if (which == 4)
		secret = user_input;
	else
		phone_number = user_input;
}

std::string Contact::get_contact_infos(int which)
{
	if (which == 1)
		return (first_name);
	else if (which == 2)
		return (last_name);
	else if (which == 3)
		return (nickname);
	else if (which == 4)
		return (secret);
	return (phone_number);
}
