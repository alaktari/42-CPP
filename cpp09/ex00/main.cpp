/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:15 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/06 12:19:50 by alaktari         ###   ########.fr       */
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
		std::cout << "Error: could not open file.\n";
	return 0;
}