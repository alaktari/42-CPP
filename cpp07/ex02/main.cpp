/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:52:23 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/16 16:24:59 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    unsigned int ArraySize = 5;
    std::srand(std::time(0));
    
    Array<int> nums(ArraySize);
    Array<char> chars(ArraySize);

    for (unsigned int i = 0; i < ArraySize; i++)
        nums[i] = (std::rand() % 201 - 100);

    for (unsigned int i = 0; i < ArraySize; i++)
        std::cout << nums[i] << " ";
    
    std::cout << std::endl;

    try {
        nums[-1] = 155;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    // ==========================================

    char c = 'a';
    for (unsigned int i = 0; i < ArraySize; i++, c++)
        chars[i] = c;

    for (unsigned int i = 0; i < ArraySize; i++)
        std::cout << chars[i] << " ";

    std::cout << std::endl;
    
    
    try {
        nums[100] = 'Z';
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}