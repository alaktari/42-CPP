/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:37:51 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/20 09:33:19 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	Test(void)
{
	// ----- Test the two type of casting (c++/c style) ----
	char c = 'a';
    char *p = &c;

    int *ptr1 = (int*)p;
    // int *ptr2 = static_cast<int*>(p); // ==> Error

    std::cout << "ptr1 => " << *ptr1 << "\n";
    // std::cout << "ptr2 => " << *ptr2 << "\n";/
}

int main(int ac, char** av)
{
	if (ac != 2)
	{
	    std::cout << "./ScalarConverter + [Expected an Input!!]\n";
	    return 0;
	}

	ScalarConverter::convert(av[1]);

	// Test();
}