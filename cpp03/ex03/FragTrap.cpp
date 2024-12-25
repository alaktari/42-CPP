/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:25:32 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/24 15:33:16 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor for " << this->name << " called\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destruct for " << name << " called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called\n";
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignement called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->Hit_points = other.Hit_points;
		this->Energy_point = other.Energy_point;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (Energy_point > 0 && Hit_points > 0)
	    std::cout << "FradTrap " << name << " requests a positive high five! ✋\n";
	else
		std::cout << "There is no high five, Already defeated\n";
}