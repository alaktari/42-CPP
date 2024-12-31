/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:14:01 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/31 16:31:03 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(std::string name) : name(name)
{
    std::cout << "ICharacter Constructor Called\n";
}

ICharacter::ICharacter(void) : name("Default")
{
    std::cout << "ICharacter Default Constructor Called\n";
}

ICharacter::~ICharacter(void)
{
    std::cout << "ICharacter Destructor Called\n";
}

ICharacter::ICharacter(const ICharacter& other)
{
    std::cout << "ICharacter Copy Constructor Called\n";
    if (this != &other)
        name = other.name;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    std::cout << "ICharacter Copy Assignment Called\n";
    if (this != &other)
        name = other.name;
}
