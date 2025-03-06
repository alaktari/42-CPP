/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:18:39 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/06 17:11:13 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	getNumber(std::string& token, int& number)
{
	if (token[0] < '0' || token[0] > '9')
		return false ;
	number = token[0] - '0';
	return true;
}

static void	calculate(std::stack<int>& RpnHolder, char operation)
{
	int b = RpnHolder.top();
	RpnHolder.pop();
	
	int a = RpnHolder.top();
	RpnHolder.pop();

	if (operation == '+')
		RpnHolder.push(a + b);
	else if (operation == '-')
		RpnHolder.push(a - b);
	else if (operation == '/') {
		if (b == 0)
			RpnHolder.push(0);
		else
			RpnHolder.push(a / b);
	}
	else
		RpnHolder.push(a * b);
}

static bool	is_operator(std::string& token, char& operation, std::string (&operators)[4])
{
	for (int i = 0; i < 4; i++) {
		if (token == operators[i]) {
			operation = operators[i][0];
			return true;
		}
	}
	return false;
}

bool RPNCalculation(std::string RPNExpression)
{
	std::stack<int>		RpnHolder;
	std::stringstream	ss(RPNExpression);
	std::string			token;
	std::string			operators[4] = {"+", "-", "/", "*"};
	char				operation;
	int					number;

	while (getline(ss, token, ' '))
	{
		if (token.size() != 1)
			return false;
		if (is_operator(token, operation, operators)) {
			if (RpnHolder.size() < 2)
				return false;
			calculate(RpnHolder, operation);
		}
		else {
			if (!getNumber(token, number))
				return false;
			RpnHolder.push(number);
		}
	}
	
	if (RpnHolder.size() != 1)
		return false;

	std::cout << RpnHolder.top() << "\n";
	return true;
}