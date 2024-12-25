/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:33:12 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/24 14:44:10 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor for " << name << " called\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destruct for " << name << " called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignement called\n";
	if (this != &other)
	{
		this->Hit_points = other.Hit_points;
		this->Energy_point = other.Energy_point;
		this->Attack_demage = other.Attack_demage;
	}
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
}

void ScavTrap::guardGate(void)
{
	if (Hit_points > 0 && Energy_point > 0)
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
	else
		std::cout << "already defeated\n";
}