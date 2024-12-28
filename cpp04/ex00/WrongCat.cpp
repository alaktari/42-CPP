/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:18:10 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 19:43:29 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat Constructor called\n";
    type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor called\n";
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "WrongCat Copy constructor called\n";
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat Copry assignement called\n";
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}
