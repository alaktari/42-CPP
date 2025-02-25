/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:21:15 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/25 10:16:13 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>

class Span
{
	public:
		unsigned int		_capacity;
		unsigned int		_size;
		int					_shortSpan;
		int					_longSpan;
		std::vector<int>	_arrInts;
		std::vector<int>	_sorted;
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(const Span& other);
		unsigned int	getSize(void) const;
		Span& operator=(const Span& other);
		void addNumber(int Number);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		int& operator[](unsigned int);
};

#endif