/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:40:55 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/07 16:33:43 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <climits>
#include <ctime>
#include <cstdlib>

template<typename T>
void	collectParsedIntegers(std::string param, T& container)
{
	std::string			token;
	std::stringstream	ss(param);
	char 				*endPtr;
	long				number;

	while (getline(ss, token, ' ')) {
		number = strtod(token.c_str(), &endPtr);
    	if ((*endPtr != ' ' && *endPtr != '\0') || number < 0 || number > INT_MAX) {
			std::cout << "Error\n";
			return ;
		}
		container.push_back(number);
	}
}
void    PairElements(std::deque<unsigned int>& container);
void    PairElements(std::list<unsigned int>& container);

template<typename T>
void    TimeTrackedSort(std::string param, T& container)
{
    collectParsedIntegers(param, container);

    PairElements(container);
}


#endif