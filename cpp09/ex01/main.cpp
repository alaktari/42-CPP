/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:04:51 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/06 15:12:29 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
	{
		std::cout << "Error\n";
		return 0;
	}
	if (!RPNCalculation(av[1]))
		std::cout << "Error\n";
}