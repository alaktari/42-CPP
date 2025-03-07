/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:41:48 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/07 16:33:08 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout <<"Error\n";
		return 0;
	}

	std::deque<unsigned int> container1;
	std::list<unsigned int> container2;
	
	
	TimeTrackedSort(av[1], container1);
	TimeTrackedSort(av[1], container2);


	// for (unsigned i : container1)
	// 	std::cout << i << " ";
	
	// std::cout << "\n";

	// for (unsigned i : container1)
	// 	std::cout << i << " ";
	
}