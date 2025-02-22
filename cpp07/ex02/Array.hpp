/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:06:18 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/22 10:50:48 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <ctime>

template <class T>
class Array
{
	private:
		T *arr;
		unsigned int _size;
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](unsigned int);
		unsigned int size(void) const;
		bool	isEmpty(void);

		//  Exception Class
		class InvalidIndexException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Passed index is out of bounds";}
    };
};

#include "Array.tpp"

#endif