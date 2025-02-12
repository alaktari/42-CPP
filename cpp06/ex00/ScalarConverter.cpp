/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:44:11 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/12 22:19:55 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::param = "";
char		ScalarConverter::inChar = 0;
int			ScalarConverter::inInt = 0;
double		ScalarConverter::inDouble = 0.0;
float		ScalarConverter::InFloat = 0.0f;
bool		ScalarConverter::intFlag = false;
bool		ScalarConverter::charFlag = false;
bool		ScalarConverter::floatFlag = false;

ScalarConverter::ScalarConverter(void)
{
	// std::cout << "ScalarConverter Constructor callefd\n";
}

ScalarConverter::~ScalarConverter(void)
{
	// std::cout << "ScalarConverter Destructor called\n";
}

bool ScalarConverter::isChar(void)
{
	if (param.empty())
		return false;
	size_t frontPoss = param.find_first_of('\'');
	size_t BackPoss = param.find_last_of('\'');
	if (!frontPoss && BackPoss == 2 && param.length() == 3)
		return true;
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
	return true;
}

bool ScalarConverter::isFloat(void)
{
    if (param.empty())
        return false;

    char *endPtr;
    float value = std::strtof(param.c_str(), &endPtr);

    if (*endPtr == 'f' && *(++endPtr) == '\0')
        return true;
    if (*endPtr == '\0' && param.find('e') < param.length())
        return true;
    return false;
}

bool	ScalarConverter::isDouble(void)
{
    if (param.empty())
        return false;

    char *endPtr;
    double value = std::strtod(param.c_str(), &endPtr);

    if (*endPtr == '\0')
        return true;
    return false;
}

void	ScalarConverter::TypeChar(void)
{
	inChar = param[1];
	
	inInt = (static_cast<int>(inChar));
	InFloat = static_cast<float>(inChar);
	inDouble = static_cast<double>(inChar);
	
}

void	ScalarConverter::TypeInt(void)
{
	inInt = atoi(param.c_str());
	
	if (inInt > 255 || inInt < 0)
		charFlag = true;
	else
		inChar = static_cast<char>(inInt);
	InFloat = static_cast<float>(inInt);
	inDouble = static_cast<double>(inInt);
}

void	ScalarConverter::TypeFloat(void)
{
	InFloat = std::strtof(param.c_str(), NULL);
	double ckecker = InFloat;
	
	if (InFloat > 255 || InFloat < 0 || std::isnan(InFloat))
		charFlag = true;
	else
		inChar = static_cast<char>(InFloat);
	if (ckecker > INT_MAX || ckecker < INT_MIN || std::isnan(InFloat))
		intFlag = true;
	else
		InFloat = static_cast<int>(InFloat);
	inDouble = static_cast<double>(InFloat);
}

void	ScalarConverter::TypeDouble(void)
{
	inDouble = std::strtod(param.c_str(), NULL);
	
	if (inDouble > 255 || inDouble < 0 || std::isnan(inDouble))
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
		InFloat = static_cast<float>(inDouble);
}

void	ScalarConverter::displayer(void)
{
	std::cout << "char: ";
	if (isprint(inChar) && !charFlag)
		std::cout << '\'' << inChar << "'\n";
	else if (!charFlag)
		std::cout << "Non displayable\n";
	else
		std::cout << "impossible\n";
	
	std::cout << "int: ";
	if (!intFlag)
		std::cout << inInt << "\n";
	else
		std::cout << "impossible\n";
		
	std::cout << "float: ";
	if (!floatFlag)
		std::cout << std::fixed << InFloat << "f\n";
	else
		std::cout << "impossible\n";
	std::cout << "Double: " << inDouble << "\n";
	
}

int	ScalarConverter::convert(std::string _param)
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
		return ((std::cout << "Invalid input\n"), 0);
	displayer();
	return 0;
}