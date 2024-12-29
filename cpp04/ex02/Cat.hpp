/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:38:06 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/29 20:40:13 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Polymorphism.hpp"

class Cat: public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void makeSound(void) const;
		std::string getIdea(int idea_index);
        void setIdea(std::string new_idea, int idea_index);
        Brain* getBrain(void) const;
};

#endif