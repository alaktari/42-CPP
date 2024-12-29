#include "Zombie.hpp"

Zombie	*newzombie(std::string name)
{
	Zombie *new_zombie = new(std::nothrow) Zombie(name);
	return (new_zombie);
}
