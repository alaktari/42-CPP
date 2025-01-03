/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:56:04 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 14:57:55 by alaktari         ###   ########.fr       */
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
    std::cout << "Copy Constructor called\n";
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy Assignment called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int idea_index)
{
    if (idea_index >= 0 && idea_index <= 100)
        return this->ideas[idea_index];
    return "";
}

void Brain::setIdea(std::string new_idea, int idea_index)
{
    if (idea_index >= 0 && idea_index <= 100)
        this->ideas[idea_index] = new_idea;
}

Brain* Brain::getBrain(void)
{
    return this;
}
