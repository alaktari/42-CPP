#include "Zombie.hpp"

static bool    is_allnum(std::string str)
{
    int len = str.length();
	int x = 0;

	if (!str[0])
		return (false);
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
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
        if ((!isdigit(str[x]) && str[x] != '+') || (str[x] == '+'
				&& (!isdigit(str[x + 1]))))
            return (false);
		x++;
    }
	return (true);
}

int main(int ac, char **av)
{
	int checker = 1;
	if (ac == 3)
	{
		Zombie *zombies;
		int		n;

		if (is_allnum(av[1]) && av[2][0] && ((n = atoi(av[1])) > 0))
		{
			zombies = zombieHorde(n, av[2]);
			if (!zombies)
				return ((std::cout << "Memory allocation failed!\n"), 1);
			std::cout << std::endl;
			for (int i = 0; i < n; i++)
				zombies[i].announce();
			std::cout << std::endl;
			delete[] zombies;
			std::cout << std::endl;
			checker = 0;
		}
	}
	if (checker)
	{
		std::cout << "Expected:  ./zombiehorde";
		std::cout << "   [Number of Zombies]   [Zombies name]\n";
	}
}
