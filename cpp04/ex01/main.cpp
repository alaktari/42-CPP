/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:21:48 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 14:18:55 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polymorphism.hpp"

int main()
{

    std::cout << "-------- Declaration & Initialization --------\n";
    int numAnimals = 6;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals/2; i++)
        animals[i] = new Dog();

    std::cout << "\n";

    for (int i = numAnimals/2; i < numAnimals; i++)
        animals[i] = new Cat();
    std::cout << "------------------------------------------\n\n";
    

    std::cout << "====== Making Sounds ==============\n";
    for (int i = 0; i < numAnimals; i++)
        animals[i]->makeSound();
    std::cout << "====================================\n\n";
    

    std::cout << "-------- freeing alocated memmory --------\n";
    for (int i = 0; i < numAnimals; i++)
        delete animals[i];
    std::cout << "---------------------------------------\n\n";

    std::cout << "======= Testing Deep Copy =======\n";
    Dog dog1;
    dog1.setIdea("Running around outside", 0);
    dog1.setIdea("Fetch the ball", 1);
    
    Dog dog2 = dog1;
    dog2.setIdea("Sleep all day", 0);

    std::cout << "Dog1 Idea 0: " << dog1.getIdea(0) << "\n";
    std::cout << "Dog1 Idea 1: " << dog1.getIdea(1) << "\n";
    std::cout << "Dog2 Idea 0: " << dog2.getIdea(0) << "\n";
    std::cout << "Dog2 Idea 1: " << dog2.getIdea(1) << "\n";
    std::cout << "=============================\n";

    // -------------------------------------------------------------------------------
    // -------------------------------------------------------------------------------

    std::cout << "======== pointers ============\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    std::cout << "=========================\n";

    return 0;
}
