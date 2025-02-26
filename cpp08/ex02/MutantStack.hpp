/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:44:14 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/26 21:48:53 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<class T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
	private:
	
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		typedef typename container::iterator iterator;
	    typedef typename container::const_iterator const_iterator;
		
		iterator	begin(void);
		iterator	end(void);
		const_iterator begin() const;
    	const_iterator end() const;
};

#include "MutantStack.tpp"

#endif