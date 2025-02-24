/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:38:43 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 14:24:05 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

Cat::Cat(void) : brain(new Brain())
{
	std::cout << "Cat Constructor called\n";
	type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called\n";
	delete brain;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Cat Copy constructor called\n";
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copry assignement called\n";
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		this->brain = new Brain(*other.getBrain());
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meow meooooooooooooow!!\n";
}

Brain* Cat::getBrain(void) const
{
    return this->brain;
}

std::string Cat::getIdea(int idea_index)
{
    return brain->getIdea(idea_index);
}

void Cat::setIdea(std::string new_idea, int idea_index)
{
    brain->setIdea(new_idea, idea_index);
}
