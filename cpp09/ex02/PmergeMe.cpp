/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:54:08 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/09 13:15:34 by alaktari         ###   ########.fr       */
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
