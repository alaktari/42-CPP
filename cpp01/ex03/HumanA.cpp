#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name)
{
	std::cout << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
