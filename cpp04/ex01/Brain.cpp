/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:56:04 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 13:58:08 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Constructor called\n";
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor called\n";
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy Constructor called\n";
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain Copy Assignment called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int idea_index)
{
    return this->ideas[idea_index];
}

void Brain::setIdea(std::string new_idea, int idea_index)
{
    this->ideas[idea_index] = new_idea;
}

Brain* Brain::getBrain(void)
{
    return this;
}
