/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:28:52 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/24 11:05:38 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	int     arr[] = {1, 5, -8, 99 , 0, 2};
	size_t  size = sizeof(arr) / sizeof(int);
	int 	index;
	
	std::vector<int> container1(arr, arr + size);
	std::list<int> container2(arr, arr + size);
	
	std::cout << "======= Using a vector container =========\n";
	index = easyfind(container1, -123);
	if (index >= 0)
		std::cout << "FOUND in index: " << index << "\n";
	else
		std::cout << "NOT FOUND\n";

	std::cout << "======= Using a list container =========\n";
	index = easyfind(container2, 99);
	if (index >= 0)
		std::cout << "FOUND in index: " << index << "\n";
	else
		std::cout << "NOT FOUND\n";
}