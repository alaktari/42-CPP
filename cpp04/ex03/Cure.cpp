/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:05:27 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 12:03:26 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure Constructor called\n";
}

Cure::~Cure(void)
{
	// std::cout << "Cure Destructor called\n";
}

Cure::Cure(const Cure& other)
{
	type = other.type;
	// std::cout << "Cure Copy Constructor called\n";
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		type = other.type;
	// std::cout << "Cure Copy Assignment called\n";
	return *this;
}

AMateria* Cure::clone(void) const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *\n";
}