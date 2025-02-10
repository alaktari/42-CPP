/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeCaster.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:56:22 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/11 00:04:39 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypeCaster.hpp"

ScalarTypeCaster::ScalarTypeCaster(std::string param) : param(param), inChar('\0'),
                    inInt(0), inDouble(0.0), InFloat(0.0f), impossible(false), nonDisplayable(false)
{
    
}

ScalarTypeCaster::~ScalarTypeCaster(void)
{
    
}

ScalarTypeCaster::ScalarTypeCaster(const ScalarTypeCaster& other)
{
    
}

ScalarTypeCaster& ScalarTypeCaster::operator=(const ScalarTypeCaster& other)
{
    return *this;
}

bool ScalarTypeCaster::isChar(void)
{
	if (param.empty())
		return false;
	size_t frontPoss = param.find_first_of('\'');
	size_t BackPoss = param.find_last_of('\'');
	if (!frontPoss && BackPoss == 2 && param.length() == 3)
		return true;
	return false;
}

bool ScalarTypeCaster::isInt(void)
{
	if (param.empty()) 
		return false;
	char *endPtr;
	long value = std::strtol(param.c_str(), &endPtr, 10);
	if (*endPtr != '\0' || value > INT_MAX || value < INT_MIN)
		return false;
	return true;
}

bool ScalarTypeCaster::isFloat(void)
{
	int i = 0;
	int	len;
	
	if (param.empty())
		return false;

	len = param.length();
	if (param.at(i) == '-' || param.at(i) == '+')
		i++;
	for (; i < len; i++)
	{
		if (!isdigit(param.at(i)))
			break ;
	}
	if (param.at(i) == '.' && i)
	{
		i++;
		for (; i < len; i++)
		{
			if (!isdigit(param[i]))
				break ;
		}
		if (param[i] == 'f' && (i + 1) == len)
			return true;
	}
	return false;
}

bool	ScalarTypeCaster::isDouble(void)
{
	int i = 0;
	int	len;
	
	if (param.empty())
		return false;

	len = param.length();
	if (param.at(i) == '-' || param.at(i) == '+')
		i++;
	for (; i < len; i++)
	{
		if (!isdigit(param.at(i)))
			break ;
	}
	if (param.at(i) == '.' && i)
	{
		i++;
		for (; i < len; i++)
		{
			if (!isdigit(param[i]))
				return false;
		}
		if (param[i - 1] != '.')
			return true;
	}
	return false;
}

void    ScalarTypeCaster::setChar(char c)
{
    this->inChar = c;
}

void    ScalarTypeCaster::setInt(int i)
{
    this->inInt = i;
}

void    ScalarTypeCaster::setFloat(float f)
{
    this->InFloat = f;
}

void    ScalarTypeCaster::setDouble(double d)
{
    this->inDouble = d;
}

char    ScalarTypeCaster::getChar(void)
{
    return this->inChar;
}

int    ScalarTypeCaster::getInt(void)
{
    return this->inInt;
}

float    ScalarTypeCaster::getFloat(void)
{
    return this->InFloat;
}

double    ScalarTypeCaster::getDouble(void)
{
    return this->inDouble;
}