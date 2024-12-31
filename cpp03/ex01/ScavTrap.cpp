/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:33:12 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/30 15:09:31 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	Hit_points = 100;
	Energy_point = 50;
	Attack_demage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	Hit_points = 100;
	Energy_point = 50;
	Attack_demage = 20;
	std::cout << "ScavTrap constructor for " << this->name << " called\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destruct for " << name << " called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor for " << name << " called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap Copy assignement for " << name << " called\n";
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (Hit_points > 0 && Energy_point > 0)
	{
		Energy_point--;
		if (Energy_point == 0)
		{
			std::cout << "ScavTrap " << name << " has been defeated\n";
			return ;
		}
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", causing " << Attack_demage << " points of demage!";
		std::cout << "  (EP:" << Energy_point << ", HP:" << Hit_points << ")\n";
	}
	else
		std::cout << "Can't attack " << target << ", Already defeated\n";
}

void ScavTrap::guardGate(void)
{
	if (Hit_points > 0 && Energy_point > 0)
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
	else
		std::cout << "ScavTrap is not in Gate keeper mode any more, already defeated\n";
}
