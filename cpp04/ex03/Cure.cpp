/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:05:27 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/31 16:08:10 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	std::cout << "Cure Constructor called\n";
	type = "cure";
}

Cure::~Cure(void)
{
	std::cout << "Cure Destructor called\n";
}

Cure::Cure(const Cure& other)
{
	std::cout << "Cure Copy Constructor called\n";
	if (this != &other)
        type = other.type;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure Copy Assignment called\n";
	if (this != &other)
        type = other.type;
}
