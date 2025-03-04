/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:22:47 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/04 17:57:03 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::vector<std::string> spliteDate(std::string& buffer, char delimeter)
{
	std::vector<std::string> splited;
	std::stringstream ss(buffer);
	std::string token;

	while (getline(ss, token, delimeter))
		splited.push_back(token);
	return splited;

}

float	getTheValue(std::vector<std::string>& key)
{
	int index = key[2].find(',');

	std::string	value = key[2].substr(index + 1); 
	key[2] = key[2].substr(0, index);

	return std::strtof(value.c_str(), NULL);
}

void BitcoinExchange::getDataBase(void)
{
	std::string buffer;

	getline(databaseFile, buffer);
	while (getline(databaseFile, buffer))
	{
		std::vector<std::string> key = spliteDate(buffer, '-');
		float value = getTheValue(key);
		databaseHolder[key] = value;
	}
}

// void	BitcoinExchange::checksTheInputs(std::string& inputLine, bool firstLine)
// {
// 	if (firstLine)
// 	{
// 		if (inputLine != "date | value")
// 			throw BitcoinExchange::BtcExchangeException::BtcExchangeException(InvalidDataBaseFile);
// 	}
// }

// void	BitcoinExchange::outputsValues(void)
// {
// 	std::string					inputLine;
// 	std::vector<std::string>	inputs;

// 	while (getline(inputFile, inputLine))
// 	{
// 		try {
// 			this->checksTheInputs(inputLine, 1);
// 		}
// 		catch (std::exception& e) {
// 			std::cout << e.what() << "\n";
// 		}
// 		break;
// 	}
// }

BitcoinExchange::BitcoinExchange(std::string inputFileName)
{
	std::string database = "data.csv";
	
	inputFile.open(inputFileName.c_str());
	databaseFile.open(database.c_str());

	if (inputFile.is_open())
		std::cout << "is opened\n";
	else
		throw BtcExchangeException(inputFileName, InvalidInputFile);

	if (databaseFile.is_open())
		std::cout << "is opened\n";
	else
		throw BtcExchangeException(database, InvalidDataBaseFile);
	this->getDataBase();
	// this->outputsValues();
}

BitcoinExchange::BtcExchangeException::BtcExchangeException(std::string fileName, int exceptionType)
{
	if (!exceptionType)
		errorMssg = "Cannot open the input file '" + fileName + "'";
	else
		errorMssg = "Cannot open the database file '" + fileName + "'";
}

const char* BitcoinExchange::BtcExchangeException::what(void) const throw()
{
	return errorMssg.c_str();
}

BitcoinExchange::BtcExchangeException::~BtcExchangeException(void) throw() {}