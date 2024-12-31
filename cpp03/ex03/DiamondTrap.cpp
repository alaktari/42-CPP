/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:06:56 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/30 14:58:38 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	name = "default";
	ClapTrap::name += "_clap_name";
	Attack_demage = 30;
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	this->name = name;
	Attack_demage = 30;
	std::cout << "DiamondTrap constructor for " << this->name << " called\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor for " << this->name << " called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	name = other.name;
	this->Attack_demage = 30;
	std::cout << "DiamondTrap Copy constructor for " << this->name << " called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	std::cout << "DiamondTrap copy assingment " << name << " called\n";
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	if (Energy_point > 0 && Hit_points > 0)
	{
		std::cout << "Hello i'm DiamondTrap " << name << " ,and my ClapTrap name is " << ClapTrap::name << "\n";
		std::cout << "HP: " << Hit_points << " || EP: " << Energy_point << " || AD: " << Attack_demage << "\n";
	}
	else
		std::cout << "DiamondTrap can't tell you its name, already defeated!!";
}