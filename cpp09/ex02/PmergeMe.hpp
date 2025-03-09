/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:40:55 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/09 13:52:33 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <climits>
#include <algorithm>

void		concatenatingArguments(std::string& params, char** av, int ac);
void		printElemts(std::deque<unsigned int> de);
void		printElemts(std::list<unsigned int> lst);
void		printParams(std::string params);


template <typename T>
void	desplayElementAndTime(T container, double dequeTime, double listTime, std::string params)
{
	size_t cSize = container.size();
	T helper = container;

	std::cout << "Before:  ";
	printParams(params);
	std::cout << "After:   ";
	printElemts(container);
	
	std::cout << "Time to process a range of " << cSize;
	std::cout << " elements with std::deque :  " << dequeTime << " us\n";
	std::cout << "Time to process a range of " << cSize;
	std::cout << " elements with std::list  :  " << listTime << " us\n";
}

template<typename T>
void	collectParsedIntegers(std::string param, T& container)
{
	std::string			token;
	std::stringstream	ss(param);
	char 				*endPtr;
	long				number;

	while (getline(ss, token, ' ')) {
		number = strtod(token.c_str(), &endPtr);
    	if ((*endPtr != ' ' && *endPtr != '\0') || number < 0 || number > INT_MAX) {
			std::cout << "Error\n";
			return ;
		}
		container.push_back(number);
	}
}

template <typename T>
void	getPairsAndSort(T container, std::pair<unsigned int, unsigned int>* myPairs,
							unsigned int pairNum)
{
	for (unsigned int i = 0; i < pairNum; i++) {
		myPairs[i].first = container.front();
		container.pop_front();
		myPairs[i].second = container.front();
		container.pop_front();
		if (myPairs[i].first > myPairs[i].second)
			std::swap(myPairs[i].first, myPairs[i].second);
	}
}

template <typename T>
void	getLosersAndwinners(T& losers, T& winners, std::pair<unsigned int, unsigned int>* myPairs,
							unsigned int pairNum)
{
	if (pairNum < 2) {
		winners.push_back(myPairs[0].first);
		winners.push_back(myPairs[0].second);
		return ;
	}
	for (unsigned int i = 0; i < pairNum; i++) {
		losers.push_back(myPairs[i].first);
		winners.push_back(myPairs[i].second);
	}
}

template <typename T>
void	sortLastTwoElement(T& winners)
{
	unsigned int	temp;

	if (winners.front() > winners.back()) {
		temp = winners.front();
		winners.pop_front();
		winners.push_back(temp);
	}
}

template <typename T>
void	binarySearchInsertForOne(T& sortedContainer, unsigned int newElement)
{
	typename T::iterator it = std::lower_bound(sortedContainer.begin(), sortedContainer.end(),
													newElement);
	sortedContainer.insert(it, newElement);
}

template <typename T>
void	binarySearchInsert(T& winners, T losers)
{
	if (losers.empty())
		return ;
	while (!losers.empty()) {
		sortLastTwoElement(winners);
		binarySearchInsertForOne(winners, losers.front());
		losers.pop_front();
	}
}

template <typename T>
void    mergeInsertAlgo(T& container)
{
	T										losers;
	T										winners;
	unsigned int							cSize = container.size();
	unsigned int							pairNum = cSize / 2;
	std::pair<unsigned int, unsigned int>	myPairs[pairNum];
	ssize_t									oddElement = -1;

	if (cSize == 1)
		return ;
	getPairsAndSort(container, myPairs, pairNum);
	getLosersAndwinners(losers, winners, myPairs, pairNum);

	if (cSize % 2)
		oddElement = container.back();
	
	if (pairNum > 2) 
		mergeInsertAlgo(winners);

	if (oddElement != -1)
		binarySearchInsertForOne(winners, oddElement);
	binarySearchInsert(winners, losers);
	container = winners;
}

template<typename T>
double	TimeTrackedSort(std::string& param, T& container)
{
	clock_t start = clock();
    collectParsedIntegers(param, container);
    mergeInsertAlgo(container);
	clock_t end = clock();

	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
}

#endif