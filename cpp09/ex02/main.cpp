/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:41:48 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/08 19:30:49 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout <<"Error\n";
		return 0;
	}

	std::deque<unsigned int> container1;
	std::list<unsigned int> container2;
	std::string				params;
	
	concatenatingArguments(params, av, ac);

	float duration_deque = TimeTrackedSort(params, container1);
	float duration_list = TimeTrackedSort(params, container2);

	desplayElementAndTime(container1, duration_deque, duration_list, params);
}
