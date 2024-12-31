#include "Phonebook.hpp"

bool    is_allnum(std::string str)
{
    int len = str.length();
	int x = 0;

	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (!str[x])
		return (false);
	while (x < len)
    {
		if ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		{
			while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
				x++;
			if (!str[x])
				return (true);
			else
				return (false);
		}
        if ((!isdigit(str[x]) && str[x] != '+') || (str[x] == '+' && (!isdigit(str[x + 1]))))
            return (false);
		x++;
    }
	return (true);
}

int	is_empty(std::string *user_input, std::string str, std::string space)
{
	while (1)
	{
		std::cout << "        ==> " << str << " can't be empty !!\n";
		std::cout << "      Enter " << str << space << "  : ";
		if (!getline(std::cin, *user_input))
			return (0);
		if ((*user_input).empty())
			continue;
		break ;
	}
	return (1);
}
