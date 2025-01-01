/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:14:57 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/01 20:49:49 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::initializeSlots(void)
{
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

void Character::clearSlots(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (slot[i])
		{
			delete slot[i];
			slot[i] = NULL;
		}
	}
}

void	Character::copySlots(const Character& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.slot[i])
			slot[i] = other.slot[i]->clone();
		else
			slot[i] = NULL;
	}
}

Character::Character(void) : name("default")
{
	initializeSlots();
	std::cout << "Character default Constructor called\n";
}

Character::Character(const std::string& name) : name(name)
{
	initializeSlots();
	std::cout << "Character Parameterized Constructor called\n";
}

Character::Character(const Character& other) : name(other.name)
{
	if (this != &other)
	{
		clearSlots();
		copySlots(other);
	}
	std::cout << "Character Copy Constructor called\n";
}

Character::~Character(void)
{
    clearSlots();
    std::cout << "Character Destructor called\n";
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		clearSlots();
		copySlots(other);
		name = other.name;
	}
	std::cout << "Character copy Assignment called\n";
	return *this;
}

std::string const & Character::getName(void) const
{
	return name;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slot[idx])
		slot[idx]->use(target);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!slot[i])
		{
			slot[i] = m;
			break ;
		}
	}
}

AMateria* Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && slot[idx])
	{
		AMateria* unequipped = slot[idx];
		slot[idx] = NULL;
		return unequipped;
	}
	return NULL;
}