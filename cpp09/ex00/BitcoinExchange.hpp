/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:34:23 by imihihamid        #+#    #+#             */
/*   Updated: 2025/03/04 17:57:12 by alaktari         ###   ########.fr       */
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


#define InvalidInputFile 0
#define InvalidDataBaseFile 1

class BitcoinExchange
{
	private:
		std::ifstream			databaseFile;
		std::ifstream			inputFile;
		std::map<std::vector<std::string>, float>	databaseHolder;
	public:
		BitcoinExchange(std::string fileName);
		void					getDataBase(void);
		void					outputsValues(void);
		void	checksTheInputs(std::string& inputLine, bool firstLine);
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