/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:09:45 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:54:02 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Polymorphism.hpp"

class WrongAnimal
{
    protected:
		std::string type;
	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif