/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:41:48 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/09 13:46:02 by alaktari         ###   ########.fr       */
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

	double dequeTime = TimeTrackedSort(params, container1);
	double listTime = TimeTrackedSort(params, container2);

	desplayElementAndTime(container2, dequeTime, listTime, params);
}
