/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:37:51 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/19 14:22:50 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
	    std::cout << "./ScalarConverter + [Expected an Input!!]\n";
	    return 0;
	}

	ScalarConverter::convert(av[1]);
}