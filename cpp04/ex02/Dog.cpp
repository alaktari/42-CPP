/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:36:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/29 20:41:09 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

Dog::Dog(void) : brain(new Brain())
{
	std::cout << "Dog Constructor called\n";
	type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called\n";
	delete brain;
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
	{
		AAnimal::operator=(other);
		brain = new Brain(*other.getBrain());
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof woof!!!\n";
}

Brain* Dog::getBrain(void) const
{
    return this->brain;
}
std::string Dog::getIdea(int idea_index)
{
    return brain->getIdea(idea_index);
}

void Dog::setIdea(std::string new_idea, int idea_index)
{
    brain->setIdea(new_idea, idea_index);
}