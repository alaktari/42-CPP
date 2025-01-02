/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:18:10 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 12:48:52 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

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

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat: Meow meow meooooooooooooow!!\n";
}