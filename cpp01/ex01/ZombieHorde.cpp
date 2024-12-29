#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies;

	zombies = new(std::nothrow) Zombie[N];
	if (zombies == NULL)
		return NULL;
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		zombies[i].set_name(name);
		std::cout << "Zombie " << name << " created\n";
	}
	return (zombies);
}