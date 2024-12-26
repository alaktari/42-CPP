/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:06:56 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/25 19:03:33 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
	name = "default";
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	std::cout << "DiamondTrap " << name << " constructor called\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destruct called for " << name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assingment called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i'm DiamondTrap " << name << " ,and my ClapTrap name is " << ClapTrap::name << "\n";	
	
	std::cout << "HP: " << Hit_points << " || EP: " << Energy_point << " || AD: " << Attack_demage << "\n";
}