/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:22:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/31 16:07:45 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "AMateria Constructor called\n";
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria Destructor called\n";
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria Copy Constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria Copy Assignment called\n";
    return *this;
}