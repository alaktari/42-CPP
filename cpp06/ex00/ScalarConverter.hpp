/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:55:53 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/19 14:44:18 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
	private:
		static std::string	param;
		static char			inChar;
		static int			inInt;
		static double		inDouble;
		static float		inFloat;

		static bool			intFlag;
		static bool			charFlag;
		static bool			floatFlag;

		
		ScalarConverter(void);
		~ScalarConverter(void);
		
	public:

		
		static bool		isChar(void);
		static bool		isInt(void);
		static bool		isFloat(void);
		static bool		isDouble(void);

		static void		TypeChar(void);
		static void		TypeInt(void);
		static void		TypeFloat(void);
		static void		TypeDouble(void);
		
		static void		displayer(void);

		static void		convert(std::string param);
};


#endif