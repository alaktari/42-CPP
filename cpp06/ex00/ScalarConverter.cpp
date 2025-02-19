/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:44:11 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/19 15:45:44 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::param = "";
char		ScalarConverter::inChar = 0;
int			ScalarConverter::inInt = 0;
double		ScalarConverter::inDouble = 0.0;
float		ScalarConverter::inFloat = 0.0f;
bool		ScalarConverter::intFlag = false;
bool		ScalarConverter::charFlag = false;
bool		ScalarConverter::floatFlag = false;

bool ScalarConverter::isChar(void)
{
	if (param.empty())
		return false;
	size_t frontPoss = param.find_first_of('\'');
	size_t BackPoss = param.find_last_of('\'');
	if (!frontPoss && BackPoss == 2 && param.length() == 3)
	{
		inChar = param[1];
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(void)
{
	if (param.empty()) 
		return false;
	char *endPtr;
	long value = std::strtol(param.c_str(), &endPtr, 10);
	if (*endPtr != '\0' || value > INT_MAX || value < INT_MIN)
		return false;
	inInt = static_cast<int>(value);
	return true;
}

bool ScalarConverter::isFloat(void)
{
    if (param.empty())
        return false;

    char *endPtr;
    inFloat = std::strtof(param.c_str(), &endPtr);
    if (param[0] != 'f' && *endPtr == 'f' && *(endPtr - 1) != '.'
			&& *(++endPtr) == '\0')
		return true;
    return false;
}

bool	ScalarConverter::isDouble(void)
{
    if (param.empty())
        return false;

    char *endPtr;
    inDouble = std::strtod(param.c_str(), &endPtr);
    if (*endPtr == '\0' && (*(endPtr - 1) != '.'))
		return true;
	return false;
}

void	ScalarConverter::TypeChar(void)
{
	inInt = (static_cast<int>(inChar));
	inFloat = static_cast<float>(inChar);
	inDouble = static_cast<double>(inChar);
}

void	ScalarConverter::TypeInt(void)
{
	if (inInt > 127 || inInt < 0)
		charFlag = true;
	else
		inChar = static_cast<char>(inInt);
	inFloat = static_cast<float>(inInt);
	inDouble = static_cast<double>(inInt);
}

void	ScalarConverter::TypeFloat(void)
{
	double checker = static_cast<double>(inFloat);
	
	if (inFloat > 127 || inFloat < 0 || std::isnan(inFloat))
		charFlag = true;
	else
		inChar = static_cast<char>(inFloat);
	if (checker > INT_MAX || checker < INT_MIN || std::isnan(inFloat))
		intFlag = true;
	else
		inInt = static_cast<int>(inFloat);
	inDouble = static_cast<double>(inFloat);
}

void	ScalarConverter::TypeDouble(void)
{
	if (inDouble > 127 || inDouble < 0 || std::isnan(inDouble))
		charFlag = true;
	else
		inChar = static_cast<char>(inDouble);
	if (inDouble > INT_MAX || inDouble < INT_MIN || std::isnan(inDouble))
		intFlag = true;
	else
		inInt = static_cast<int>(inDouble);
	if (inDouble > FLT_MAX || inDouble < -FLT_MAX)
		floatFlag = true;
	else
		inFloat = static_cast<float>(inDouble);
}

void	ScalarConverter::displayer(void)
{

	// ----------- display Char -------------- 
	std::cout << "char: ";
	if (isprint(inChar) && !charFlag)
		std::cout << '\'' << inChar << "'\n";
	else if (!charFlag)
		std::cout << "Non displayable\n";
	else
		std::cout << "impossible\n";
	// ----------------------------------------


	// ---------- Display Int -----------------
	std::cout << "int: ";
	if (!intFlag)
		std::cout << inInt << "\n";
	else
		std::cout << "impossible\n";
	// ----------------------------------------


	// ---------- Display Int -----------------
	std::cout << "float: ";
	if (!floatFlag)
	{
		float	checker = static_cast<float>(static_cast<int>(inFloat));

		if (inFloat > checker)
			std::cout << inFloat << "f\n";
		else
			std::cout << std::fixed << std::setprecision(1) << inFloat << "f\n";
	}
	else
		std::cout << "impossible\n";
	// ----------------------------------------


	// ---------- Display Int -----------------
	std::cout << "Double: " << inDouble << "\n";
	// ----------------------------------------
	
}

void	ScalarConverter::convert(std::string _param)
{
	param = _param;
	
	if (isChar())
		TypeChar();
	else if (isInt())
		TypeInt();
	else if (isFloat())
		TypeFloat();
	else if (isDouble())
		TypeDouble();
	else
	{
		std::cout << "Invalid input: '" << param << "'\n";
		return ;
	}
	displayer();
}