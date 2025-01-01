/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:22:28 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/01 11:45:37 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("default")
{
    std::cout << "AMateria Default Constructor called\n";
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria Parameterized Constructor called\n";
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria Destructor called\n";
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout << "AMateria Copy Constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria Copy Assignment called\n";
    if (this != &other) 
        type = other.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria used on " << target.getName() << "\n";
}
