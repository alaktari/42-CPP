/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:06:18 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/22 10:25:49 by alaktari         ###   ########.fr       */
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

template <class T>
Array<T>::Array(void) : arr(NULL)
{
	// std::cout << "Array Constructor caled\n";
}

template <class T>
Array<T>::Array(unsigned int n) : _size(n)
{
	// std::cout << "Array Paramitrized Constructor caled\n";
	arr = new T[n];
}

template <class T>
Array<T>::~Array(void)
{
	// std::cout << "Array Destructor caled\n";
	delete[] arr;
}

template <class T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	// std::cout << "Array Copy Constructor caled\n";
	if (this != &other)
	{
		arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			arr[i] = other.arr[i];
	}
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
	// std::cout << "Array Copy Assignment caled\n";
	if (this != &other)
	{
		delete[] arr;
		_size = other._size;
		arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <class T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

template <class T>
bool Array<T>::isEmpty(void)
{
	if (!arr)
		return true;
	return false;
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size || index < 0)
		throw InvalidIndexException();
	return arr[index];
}

template <class T>
std::ostream &operator<<(std::ostream &output_stream, Array<T>& arr)
{
	unsigned int arrSize = arr.size();

	if (arr.isEmpty())
		return output_stream;
	for (unsigned int i = 0; i < arrSize; i++)
        output_stream << arr[i] << " ";
	return output_stream;
}

#endif