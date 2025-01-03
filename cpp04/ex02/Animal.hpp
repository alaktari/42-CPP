/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:13:25 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 14:58:17 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include "Polymorphism.hpp"

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif