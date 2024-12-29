#include "Zombie.hpp"

Zombie::Zombie(void){}

void	Zombie::set_name(std::string zombie_name)
{
	name = zombie_name;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << " destroyed\n";
}