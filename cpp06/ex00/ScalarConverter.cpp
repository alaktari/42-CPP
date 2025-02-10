/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:44:11 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/11 00:05:46 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarTypeCaster.hpp"

ScalarConverter::ScalarConverter(std::string param)
{
	// std::cout << "ScalarConverter Constructor callefd\n";
}

ScalarConverter::~ScalarConverter(void)
{
	// std::cout << "ScalarConverter Destructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	// std::cout << "Copy Constructor called\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	// std::cout << "ScalarConverter Copy Assignment called\n";
	return *this;
}

void	TypeChar(ScalarTypeCaster& helper, std::string param)
{
	helper.setChar(param[1]);
	// std::cout << "inChar: " << helper.getChar() << "\n";
	
}

void	TypeInt(ScalarTypeCaster& helper, std::string param)
{
	helper.setInt(atoi(param.c_str()));
	// std::cout << "inInt: " << helper.getInt() << "\n";
	
	
}

void    ScalarConverter::convert(std::string param)
{
	ScalarTypeCaster helper(param);

	if (helper.isChar())
	{
		std::cout << "it's a character\n";
		TypeChar(helper, param);
	}
	if (helper.isInt())
	{
		std::cout << "it's an interger\n";
		TypeInt(helper, param);
	}
	// else if (helper.isFloat())
	// {
	// 	std::cout << "it's a float point number\n";
	// }
	// else if (helper.isDouble())
	// {
	// 	std::cout << "it's a double\n";
	// }
}