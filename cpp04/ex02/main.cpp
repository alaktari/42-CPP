/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:21:48 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 14:23:10 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

int main()
{

	{
			// TEST 1:
		AAnimal *A1 = new Dog;

		std::cout << "\nType:" << A1->getType() << "\n";
		A1->makeSound();
		delete A1;

		std::cout << std::endl;

		AAnimal *A2 = new Cat;
		std::cout << "\nType:" << A2->getType() << "\n";
		A2->makeSound();
		
		std::cout << std::endl;
		delete A2;

		// Animal A; // ERROR!!
		// Animal *A = new Animal; // ERROR!!

	}
	
	std::cout << "\n-------------------------\n\n";

	{
			// TEST	2:
		Dog kelb;
		
		std::cout << "\n the type : " << kelb.getType() << "\n";
		kelb.setIdea("i like playing with cats", 90);
		std::cout << " the idea : " << kelb.getIdea(90) << "\n\n";
	}
	
	return 0;
}
