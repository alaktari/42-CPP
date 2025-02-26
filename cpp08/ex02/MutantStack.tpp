/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:25:23 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/26 21:50:52 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<class T, class container>
MutantStack<T, container>::MutantStack(void) {
	// std::cout << "MutantStack Dconstructor called\n";
}

template<class T, class container>
MutantStack<T, container>::~MutantStack(void) {
	// std::cout << "MutantStack Destructor called\n";
}

template<class T, class container>
MutantStack<T, container>::MutantStack(const MutantStack& other) {
	// std::cout << "MutantStack Copy Constructor called\n";
	*this = other;
}

template<class T, class container>
MutantStack<T, container>& MutantStack<T, container>::operator=(const MutantStack& other)
{
	// std::cout << "MutantStack Copy Assignment called\n";
	std::stack< T, container >::operator=(other);
	return *this;
}

template<class T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin(void) {
	return this->c.begin();
}

template<class T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end(void) {
	return this->c.end();
}

template<class T, class container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::begin(void) const {
	return this->c.begin();
}

template<class T, class container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::end(void) const {
	return this->c.end();
}