/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:40:55 by alaktari          #+#    #+#             */
/*   Updated: 2025/03/08 19:31:33 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <ctime>

void	concatenatingArguments(std::string& params, char** av, int ac);

template <typename T>
void	desplayElementAndTime(T container, float duration_deque, float duration_list, std::string params)
{
	size_t cSize = container.size();
	T helper = container;

	if (cSize > 8) {
		params.erase(16, params.size() - 16);
		params += "[...]";
	}
	std::cout << "Before:  " << params << "\n";
	std::cout << "After:   ";
	for (size_t i = 0; i < cSize; i++) {
		if (i)
			std::cout << " ";
		std::cout << container.front();
		container.pop_front();
		if (cSize > 8 && i == 7) {
			std::cout << " [...]";
			break ;
		}
	}
	std::cout << "\nTime to process a range of " << cSize;
	std::cout << " elements with std::deque :  " << duration_deque << " us\n";
	std::cout << "Time to process a range of " << cSize;
	std::cout << " elements with std::list  :  " << duration_list << " us\n";
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
void	getLosersAndWiners(T& losers, T& winers, std::pair<unsigned int, unsigned int>* myPairs,
							unsigned int pairNum)
{
	if (pairNum < 2) {
		winers.push_back(myPairs[0].first);
		winers.push_back(myPairs[0].second);
		return ;
	}
	for (unsigned int i = 0; i < pairNum; i++) {
		losers.push_back(myPairs[i].first);
		winers.push_back(myPairs[i].second);
	}
}

template <typename T>
void	sortLastTwoElement(T& winers)
{
	unsigned int	temp;

	if (winers.front() > winers.back()) {
		temp = winers.front();
		winers.pop_front();
		winers.push_back(temp);
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
void	binarySearchInsert(T& winers, T losers)
{
	if (losers.empty())
		return ;
	while (!losers.empty()) {
		sortLastTwoElement(winers);
		binarySearchInsertForOne(winers, losers.front());
		losers.pop_front();
	}
}

template <typename T>
void    mergeInsertAlgo(T& container)
{
	T										losers;
	T										winers;
	unsigned int							cSize = container.size();
	unsigned int							pairNum = cSize / 2;
	std::pair<unsigned int, unsigned int>	myPairs[pairNum];
	ssize_t									oddElement = -1;

	getPairsAndSort(container, myPairs, pairNum);
	getLosersAndWiners(losers, winers, myPairs, pairNum);

	if (cSize % 2)
		oddElement = container.back();
	
	if (pairNum > 2) 
		mergeInsertAlgo(winers);

	if (oddElement != -1)
		binarySearchInsertForOne(winers, oddElement);
	binarySearchInsert(winers, losers);
	container = winers;
}

template<typename T>
float    TimeTrackedSort(std::string& param, T& container)
{
	clock_t start_deque = clock();
    collectParsedIntegers(param, container);
	clock_t end_deque = clock();

    mergeInsertAlgo(container);

	return (float(end_deque - start_deque) / CLOCKS_PER_SEC * 1000);

}

#endif