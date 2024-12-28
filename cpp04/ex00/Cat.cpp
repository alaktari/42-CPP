/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:38:43 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:57:30 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

Cat::Cat(void)
{
    std::cout << "Cat Constructor called\n";
    type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor called\n";
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat Copy constructor called\n";
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copry assignement called\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow meow meooooooooooooow!!\n";
}