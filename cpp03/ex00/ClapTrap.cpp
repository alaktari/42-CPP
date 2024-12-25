/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:41:34 by alaktari          #+#    #+#             */
/*   Updated: 2024/11/22 09:39:07 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("default"), Hit_points(10), Energy_point(10), Attack_demage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name): name(name), Hit_points(10), Energy_point(10), Attack_demage(0)
{
	std::cout << "ClapTrap constructor for " << name << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called\n";
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignement called\n";
	if (this != &other)
	{
		name = other.name;
		Hit_points = other.Hit_points;
		Energy_point = other.Energy_point;
		Attack_demage = other.Attack_demage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destruct for " << name << " called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (Energy_point > 0 && Hit_points > 0)
	{
		this->Energy_point--;
		if (Energy_point == 0)
		{
			std::cout << "ClapTrap " << name << " has been defeated\n";
			return ;
		}
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << Attack_demage << " points of demage!";
		std::cout << "  (EP:" << Energy_point << ", HP:" << Hit_points << ")\n";
	}
	else
		std::cout << "ClapTrap " << name << " can't attack " << target << ", already defeated\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
	if (Hit_points > 0)
	{
		if (Hit_points < amount)
			Hit_points = 0;
		else
			Hit_points -= amount;
		if (Hit_points == 0)
		{
			std::cout << "ClapTrap " << name << " has been defeated\n";
			return ;
		}
		std::cout << "ClapTrap " << name << " has taken demage";
		std::cout << ", it caused lost " << amount << " hit points!";
		std::cout << "  (EP:" << Energy_point << ", HP:" << Hit_points << ")\n";
	}
	else
		std::cout << "ClapTrap " << name << " can't take demage, already defeated!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_point > 0 && Hit_points > 0)
	{
		Hit_points += amount;
		Energy_point--;
		std::cout << "ClapTrap " << name << "has repaired itself";
		std::cout << ", restoring " << amount << " hit points";
		std::cout << "  (EP:" << Energy_point << ", HP:" << Hit_points << ")\n";
	}
	else
		std::cout << "can't repair itself, already defeated\n";
}
