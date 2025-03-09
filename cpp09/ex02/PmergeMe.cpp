/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:54:08 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/09 13:52:22 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	removeExtraSpaces(std::string& params)
{
	std::string	newOne;
	int			paramSize = params.size();

	for (int i = 0; i < paramSize; i++) {
		if (!newOne.empty() && params[i] == ' ' && !isspace(params[i+1]) && params[i+1] != '\0')
			newOne += ' ';
		else if (!isspace(params[i]))
			newOne += params[i];
	}
	params = newOne;
}

void	concatenatingArguments(std::string& params, char** av, int ac)
{
	std::string helper;

	for (int i = 1; i < ac; i++) {
		if (i > 1)
			params += " ";
		params += av[i];
	}
	removeExtraSpaces(params);
}

void	printElemts(std::deque<unsigned int> de)
{
	size_t deSize = de.size();

	for (size_t i = 0; i < deSize; i++) {
		if (i)
			std::cout << " ";
		std::cout << de[i];
		if (deSize > 5 && i == 3) {
			std::cout << " [...]\n";
			break ;
		}
	}
}

void	printElemts(std::list<unsigned int> lst)
{
	size_t lstSize = lst.size();

	for (size_t i = 0; i < lstSize; i++)
	{
		if (i)
			std::cout << " ";
		std::cout << lst.front();
		lst.pop_front();
		if (lstSize > 5 && i == 3) {
			std::cout << " [...]\n";
			break ;
		}
	}
}

void	printParams(std::string params)
{
	for (unsigned long i = 0, spaces = 0; i < params.size(); i++) {
		std::cout << params[i];
		if (params[i] == ' ')
			spaces++;
		if (spaces == 4) {
			std::cout << "[...]\n";
			break ;
		}
	}
	
}
