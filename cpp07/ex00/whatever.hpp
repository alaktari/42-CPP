/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:32:25 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:43 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename anyType>
void	swap(anyType& first, anyType& second)
{
	anyType temp;
	
	temp = first;
	first = second;
	second = temp;
}

template <typename anyType>
anyType	min(anyType first, anyType second)
{
	return (first < second)? first : second;
}

template <typename anyType>
anyType	max(anyType first, anyType second)
{
	return (first > second)? first : second;
}

#endif