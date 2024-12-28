/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:36:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:57:37 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

Dog::Dog(void)
{
    std::cout << "Dog Constructor called\n";
    type = "Dog";
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor called\n";
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog Copy constructor called\n";
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Cat Copy assignement called\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof woof woof!!!\n";
}
