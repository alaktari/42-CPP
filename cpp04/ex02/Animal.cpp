/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:22:57 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/29 20:39:40 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

AAnimal::AAnimal(void): type("Unknown")
{
	std::cout << "Animal Constructor called\n";
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal Destructor called\n";
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Animal Copy constructor called\n";
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

std::string AAnimal::getType(void) const
{
	return type;
}
