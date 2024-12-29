/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:36:37 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/29 12:43:31 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Polymorphism.hpp"

class Dog: public Animal
{
	private:
		Brain* brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		void makeSound(void) const;
		std::string getIdea(int idea_index);
        void setIdea(std::string new_idea, int idea_index);
        Brain* getBrain(void) const;
};

#endif