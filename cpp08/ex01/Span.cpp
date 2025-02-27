/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:33:22 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/27 08:42:55 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _capacity(2), _size(0), _shortSpan(0),
					_longSpan(0), _arrInts() {
	// std::cout << "Default constructor called\n";
	_arrInts.reserve(_capacity);
}

Span::Span(unsigned int N) : _capacity(N), _size(0), _shortSpan(0),
								_longSpan(0), _arrInts() {
	// std::cout << "Span Paramitrized Constructor called\n";
	_arrInts.reserve(_capacity);
}

Span::~Span(void) {
	// std::cout << "Span Destructor called\n";
}

Span::Span(const Span& other) : _capacity(other._capacity), _size(other._size),
								_shortSpan(other._shortSpan),_longSpan(other._longSpan),
								_arrInts(other._arrInts) {
	// std::cout << "Span Copy Constructor called\n";
}

Span& Span::operator=(const Span& other) {
	// std::cout << "Span Copy Assignment called\n";
	if (this != &other)
	{
		_capacity = other._capacity;
		_arrInts = other._arrInts;
		_size = other._size;
		_shortSpan = other._shortSpan;
		_longSpan = other._longSpan;
	}
	return *this;
}

unsigned int	Span::getSize(void) const
{
	return _size;
}

void	Span::addNumber(int Number)
{
	std::stringstream ss;
	ss << "Cannot add another integer: Vector capacity exceeded (capacity = " << _capacity << ")";
	
	if (_size >= _capacity)
		throw std::out_of_range(ss.str());
	_arrInts.push_back(Number);
	_size++;

	if (_size == 2)
	{
		int	distance = abs(_arrInts[0] - _arrInts[1]);
		_shortSpan = distance;
		_longSpan = distance;
	}
}

int&	Span::operator[](unsigned int index)
{
	return _arrInts[index];
}

void	printElements2(Span& span)
{	
	std::cout << "sorted: ";
	for (unsigned int i = 0; i < span.getSize(); i++)
		std::cout << span._sorted[i] << " ";
	std::cout << "\n";
}

unsigned int	Span::shortestSpan(void)
{
	if (_size < 2)
		throw std::logic_error("Cannot find shortest span: Container has fewer than 2 elements.");

	else if (_size > 2)
	{
		_sorted = _arrInts;
		std::sort(_sorted.begin(), _sorted.end());
		for (unsigned int i = 1; i < _size; i++) {
			if (abs(_sorted[i - 1] - _sorted[i]) < _shortSpan)
				_shortSpan = abs(_sorted[i - 1] - _sorted[i]);
		}
	}
	return _shortSpan;
	
}

unsigned int	Span::longestSpan(void)
{
	if (_size < 2)
		throw std::logic_error("Cannot find longest span: Container has fewer than 2 elements.");
	if (_size > 2)
	{
		_sorted = _arrInts;
		std::sort(_sorted.begin(), _sorted.end());
		_longSpan = _sorted.back() - _sorted.front();
	}
	return _longSpan;
}