/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:52:23 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/22 10:49:53 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void    arrayOfIntgers(unsigned int ArraySize)
{
    std::srand(std::time(0));
    
    Array<int> nums(ArraySize);
    for (unsigned int i = 0; i < ArraySize; i++)
        nums[i] = (std::rand() % 201 - 100);
    std::cout << "start with: ";
    std::cout << nums;
    std::cout << std::endl;
    try {
        nums[0] = 9999;
        nums[-1] = 155;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    std::cout << "last update: ";
    std::cout << nums;
}

void    arrayOfCharacters(unsigned int ArraySize)
{
    Array<char> chars(ArraySize);

    char c = 'a';
    for (unsigned int i = 0; i < ArraySize; i++, c++)
        chars[i] = c;
    std::cout << "start with: ";
    std::cout << chars;
    std::cout << std::endl;
    try {
        chars[0] = '*';
        chars[100] = 'Z';
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    std::cout << "last update: ";
    std::cout << chars;
}

int main()
{
    arrayOfIntgers(5);
    std::cout << "\n==========================================\n";
    arrayOfCharacters(5);
}