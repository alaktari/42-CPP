#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name)
{
	std::cout << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with his Weapon type " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks without Weapon " << std::endl;
}