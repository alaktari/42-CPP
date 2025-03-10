/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:22:47 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/06 12:24:22 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float	getTheValue(std::string& token)
{
	int index = token.find(',');

	std::string	value = token.substr(index + 1);
	return std::strtof(value.c_str(), NULL);
}

std::vector<int> spliteDate(std::string& buffer, char delimeter, float& value)
{
	std::vector<int> splited;
	std::stringstream ss(buffer);
	std::string token;

	while (getline(ss, token, delimeter))	
		splited.push_back(std::strtod(token.c_str(), NULL));
	value = getTheValue(token);
	return splited;
}

void BitcoinExchange::getDataBase(void)
{
	std::string	buffer;
	float		value;

	getline(databaseFile, buffer);
	while (getline(databaseFile, buffer))
	{	
		std::vector<int> key = spliteDate(buffer, '-', value);	
		databaseHolder[key] = value;
	}
}

bool	getDateParts(int& datePart, std::string& token, int tokenNum)
{
	char	*endPtr;
	long	currPart;

	if (tokenNum == 0)
	{
		if (token.size() != 4)
			return false;
		currPart = std::strtol(token.c_str(), &endPtr, 10);
		if (*endPtr != '\0' || currPart > 2022 || currPart < 2009)
			return false;
		datePart = currPart;
	}
	else if (tokenNum == 1)
	{
		if (token.size() != 2)
			return false;
		currPart = std::strtol(token.c_str(), &endPtr, 10);
		if (*endPtr != '\0' || currPart > 12 || currPart <= 0)
			return false;
		datePart = currPart;
	}
	else if (tokenNum == 2)
	{
		if (token.size() != 3)
			return false;
		currPart = std::strtol(token.c_str(), &endPtr, 10);
		if (*endPtr != ' ' || currPart > 31 || currPart <= 0)
			return false;
		datePart = currPart;
	}
	return true;
}

std::vector<int>	getDate(std::string& dateHolder, bool& checker)
{
	std::string			token;
	std::stringstream	ss(dateHolder);
	std::vector<int>	date;
	int					tokenNum = 0;
	int					datePart;

	while (getline(ss, token, '-'))
	{
		if (!getDateParts(datePart, token, tokenNum))
			throw BitcoinExchange::BtcExchangeException(dateHolder, INVALIDDATE);
		date.push_back(datePart);
		tokenNum++;
	}
	if (tokenNum != 3)
		checker = true;
	if (date[YEAR] == 2009) {
		if (date[MONTH] == 1 && date[DAY] < 2)
			throw BitcoinExchange::BtcExchangeException(dateHolder, INVALIDDATE);
	}
	return date;
}

std::vector<int>	BitcoinExchange::spliteLine(std::string& inputLine, float& value)
{
	std::string			token;
	std::stringstream	ss(inputLine);
	int					tokensNum = 0;
	std::vector<int>	date;
	bool				checker = false;
	char *endPtr;

	while (getline(ss, token, '|'))
	{
		if (!tokensNum)
		{
			if (token.size() != 11)
					throw BitcoinExchange::BtcExchangeException(inputLine, BADINPUT);
			date =  getDate(token, checker);
		}
		else
		{
			value = std::strtof(token.c_str(), &endPtr);
			if (token[0] != ' ' || !token[1] || *endPtr != '\0')
				throw BitcoinExchange::BtcExchangeException(inputLine, BADINPUT);
			else if ((double)value > 1000)
				throw BitcoinExchange::BtcExchangeException(inputLine, TOOLARGENUMBER);
			else if ((double)value < 0)
				throw BitcoinExchange::BtcExchangeException(inputLine, NOTPOSSITIVE);
		}
		tokensNum++;
	}
	if (tokensNum != 2)
		throw BitcoinExchange::BtcExchangeException(inputLine, BADINPUT);

	return date;
}

void	decrementDate(std::vector<int>& key)
{
	if (key[2] == 1)
	{
		key[2] = 31;
		if (key[1] == 1)
		{
			key[1] = 12;
			key[0] -= 1;
		}
		else
			key[1] -= 1;
	}
	else
		key[2] -= 1;
}

void	BitcoinExchange::calculateAndDisplay(std::vector<int> key, float value)
{
	float			calculatedValue;
	unsigned int	size;
	while (1)
	{
		if (databaseHolder.find(key) != databaseHolder.end()) {
			calculatedValue = value * databaseHolder[key];
			size = key.size();
			for (unsigned int i = 0; i < size; i++) {
				if (i)
					std::cout << "-";
				if (key[i] < 10)
					std::cout << "0";
				std::cout << key[i];
			}
			std::cout << " => " << value << " = " << calculatedValue << "\n";
			break ;
		}
		else
			decrementDate(key);
	}
}

void	BitcoinExchange::outputValues(void)
{
	std::string			inputLine;
	std::vector<int>	inputs;
	float				value;

	getline(inputFile, inputLine);
	if (inputLine != "date | value")
		throw BitcoinExchange::BtcExchangeException("", InvalidInputs);
	while (getline(inputFile, inputLine))
	{
		try {
			inputs = this->spliteLine(inputLine, value);
			calculateAndDisplay(inputs, value);
		}
		catch (std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}
}

BitcoinExchange::BitcoinExchange(std::string inputFileName)
{
	databaseFilePath = "data.csv";
	inputFilePath = inputFileName;
	
	inputFile.open(inputFilePath.c_str());
	databaseFile.open(databaseFilePath.c_str());

	if (!databaseFile.is_open())
		throw BtcExchangeException(databaseFilePath, InvalidDataBaseFile);
	
	if (!inputFile.is_open())
		throw BtcExchangeException(inputFilePath, InvalidInputFile);

	this->getDataBase();
	this->outputValues();
}

BitcoinExchange::~BitcoinExchange(void) {
	databaseFile.close();
	inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		databaseHolder = other.databaseHolder;
		inputFilePath = other.inputFilePath;
		databaseFilePath = other.databaseFilePath;
		
		databaseFile.open(databaseFilePath.c_str());
		if (!databaseFile.is_open())	
			throw BtcExchangeException(databaseFilePath, InvalidDataBaseFile);
		inputFile.open(inputFilePath.c_str());
		if (!inputFile.is_open())
			throw BtcExchangeException(inputFilePath, InvalidInputFile);
	}
	return *this;
}


BitcoinExchange::BtcExchangeException::BtcExchangeException(std::string param, int exceptionType)
{
	if (exceptionType == InvalidInputFile)
		errorMssg = "Cannot open the input file '" + param + "'";
	else if (exceptionType == InvalidDataBaseFile)
		errorMssg = "Cannot open the database file '" + param + "'";
	else if (exceptionType == InvalidInputs)
		errorMssg = "Invalid input file (Expected first line : \"date | value\")";
	else if (exceptionType == BADINPUT)
		errorMssg = "Error: bad input => " + param;
	else if (exceptionType == TOOLARGENUMBER)
		errorMssg = "Error: too large a number.";
	else if (exceptionType == NOTPOSSITIVE)
		errorMssg = "Error: not a positive number.";
	else if (exceptionType == INVALIDDATE)
		errorMssg = "Invalid Date => " + param;
}

const char* BitcoinExchange::BtcExchangeException::what(void) const throw()
{
	return errorMssg.c_str();
}

BitcoinExchange::BtcExchangeException::~BtcExchangeException(void) throw() {}