/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:25:32 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/30 14:59:20 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	Hit_points = 100;
	Energy_point = 100;
	Attack_demage = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	Hit_points = 100;
	Energy_point = 100;
	Attack_demage = 30;
	std::cout << "FragTrap constructor for " << this->name << " called\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destruct for " << name << " called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor " << name << " called\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap Copy assignement for " << name << " called\n";
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (Energy_point > 0 && Hit_points > 0)
	    std::cout << "FradTrap " << name << " requests a positive high five! ✋\n";
	else
		std::cout << "There is no high five, Already defeated\n";
}