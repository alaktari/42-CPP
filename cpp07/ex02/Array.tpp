/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:42:11 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/22 10:50:13 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

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