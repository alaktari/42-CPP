/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:34:23 by imihihamid        #+#    #+#             */
/*   Updated: 2025/03/05 18:01:18 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <climits>


#define InvalidInputFile 0
#define InvalidDataBaseFile 1
#define InvalidInputs 2
#define BADINPUT 3
#define TOOLARGENUMBER 4
#define NOTPOSSITIVE 5

#define YEAR 0
#define MONTH 1
#define DAY 2

class BitcoinExchange
{
	private:
		std::ifstream			databaseFile;
		std::ifstream			inputFile;
		std::map<std::vector<int>, float>	databaseHolder;
		std::vector<int>					firstKey;
		std::vector<int>					lastKey;
	public:
		BitcoinExchange(std::string fileName);
		void					getDataBase(void);
		void					outputValues(void);
		std::vector<int>		spliteLine(std::string& inputLine, float& value);
		void					calculateAndDisplay(std::vector<int> key, float value);
		// ~BitcoinExchange(void);
		// BitcoinExchange(const BitcoinExchange& other);
		// BitcoinExchange& operator=(const BitcoinExchange& other);

		class BtcExchangeException : public std::exception
		{
			private:
				std::string	errorMssg;
			public:
				BtcExchangeException(std::string inputFileName, int exceptionType);
				const char* what(void) const throw();
				~BtcExchangeException(void) throw();
		};
};

#endif