/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:33:58 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 11:33:31 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice Constructor called\n";
}

Ice::~Ice(void)
{
	// std::cout << "Ice Destructor called\n";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	// std::cout << "Ice Copy Constructor called\n";
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
        AMateria::operator=(other);
	// std::cout << "Ice Copy Assignment called\n";
	return *this;
}

AMateria* Ice::clone(void) const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}