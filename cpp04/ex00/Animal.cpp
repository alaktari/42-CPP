/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:22:57 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:57:24 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

Animal::Animal(void): type("Unknown")
{
	std::cout << "Animal Constructor called\n";
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal Copy constructor called\n";
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "Error: base class cannot produce sound!!!\n";
}

std::string Animal::getType(void) const
{
	return type;
}
