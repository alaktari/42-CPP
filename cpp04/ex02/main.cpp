/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:21:48 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/29 20:40:26 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

int main()
{

	AAnimal *A1 = new Dog;

	std::cout << "Type:" << A1->getType() << "\n";
	A1->makeSound();
	delete A1;

	std::cout << std::endl;
	
	AAnimal *A2 = new Cat;
	std::cout << "Type:" << A2->getType() << "\n";
	A2->makeSound();
	delete A2;

	// Animal A; // ERROR!!
	// Animal *A = new Animal; // ERROR!!
	
	return 0;
}
