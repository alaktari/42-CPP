/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:15 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/05 17:49:09 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try {
			BitcoinExchange btcExchange(av[1]);
		}
		catch (std::exception& e) {
			std::cout << e.what() << "\n";
			return 1;
		}
	}
	else
		std::cout << "Invalid input!!\n";
}