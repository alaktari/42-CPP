/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeCaster.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:48:28 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/10 17:36:47 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPECASTER_HPP
#define SCALARTYPECASTER_HPP

#include "ScalarConverter.hpp"

class ScalarTypeCaster
{
    private:
        std::string	param;
		char		inChar;
		int			inInt;
		double		inDouble;
		float		InFloat;

		bool		impossible;
		bool		nonDisplayable;
		
    public:
		bool	isChar(void);
		bool	isInt(void);
		bool	isFloat(void);
		bool	isDouble(void);
        
        char	getChar(void);
		int		getInt(void);
		float	getFloat(void);
		double	getDouble(void);

		void	setChar(char c);
		void	setInt(int i);
		void	setFloat(float f);
		void	setDouble(double d);

        ScalarTypeCaster(std::string param);
        ~ScalarTypeCaster(void);
        ScalarTypeCaster(const ScalarTypeCaster& other);
        ScalarTypeCaster& operator=(const ScalarTypeCaster& other);
};

#endif