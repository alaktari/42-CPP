/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:33:58 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/31 16:07:33 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice(void)
{
	std::cout << "Ice Constructor called\n";
	type = "ice";
}

Ice::~Ice(void)
{
	std::cout << "Ice Destructor called\n";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice Copy Constructor called\n";
	if (this != &other)
        type = other.type;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice Copy Assignment called\n";
	if (this != &other)
        type = other.type;
}