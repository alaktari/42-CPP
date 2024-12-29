#include "Weapon.hpp"

Weapon::Weapon(std::string the_type) : type(the_type) {}

Weapon::~Weapon(void) {}

void	Weapon::setType(std::string the_type)
{
	this->type = the_type;
}

const std::string& Weapon::getType(void)
{
	return	this->type;
}