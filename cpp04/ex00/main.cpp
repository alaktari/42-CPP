/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:21:48 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:58:03 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

int main()
{
	std::cout << "----------- Declaratoin --------------------\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	std::cout << "--------------------------------------------\n\n";


	std::cout << "---------------- Calling methods -----------\n";
    std::cout << "Type ==> " << j->getType() << " " << std::endl;
    std::cout << "Type ==> " << i->getType() << " " << std::endl;
    std::cout << "Makeing sound:    "; i->makeSound();
    std::cout << "Makeing sound:    "; j->makeSound();
    std::cout << "Makeing sound:    "; meta->makeSound();
	std::cout << "---------------------------------------------\n\n";

	std::cout << "-------- freeing the allcated memmory --------\n";
    delete meta;
    delete j;
    delete i;
	std::cout << "----------------------------------------------\n\n";


	std::cout << "----------- Declaratoin --------------------\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
	std::cout << "--------------------------------------------\n\n";



	std::cout << "---------------- Calling methods -----------\n";
    std::cout << "Type ==> " << wrongI->getType() << " " << std::endl;
    std::cout << "Makeing sound:    ";wrongI->makeSound();
    std::cout << "Makeing sound:    ";wrongMeta->makeSound();
	std::cout << "---------------------------------------------\n\n";

	std::cout << "-------- freeing the allcated memmory --------\n";
    delete wrongMeta;
    delete wrongI;
	std::cout << "----------------------------------------------\n";


    return 0;
}
