/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:06:56 by alaktari          #+#    #+#             */
/*   Updated: 2024/11/23 10:49:33 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name("default"), ClapTrap("default_clap_name")
{
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : name(name), ClapTrap(name + "_clap_name")
{
	std::cout << "Diamond " << name << " constructor called\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Diamond constructor for " << name << " called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assingment called\n";
	if (this != &other)
	{
		
	}
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i'm ClapTrap " << name << "\n";	
}