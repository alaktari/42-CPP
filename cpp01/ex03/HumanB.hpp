#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon*	weapon;
		std::string	name;
	public:
				HumanB(std::string name);
				~HumanB(void);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif