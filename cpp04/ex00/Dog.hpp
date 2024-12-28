/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:36:37 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:57:40 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Polymorphism.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		void makeSound(void) const;
};

#endif