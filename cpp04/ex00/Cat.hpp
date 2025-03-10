/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:38:06 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:57:34 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Polymorphism.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void makeSound(void) const;
};

#endif