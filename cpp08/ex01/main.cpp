/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:51:38 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/25 10:14:29 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	printElements(Span& span)
{
	if (!span._arrInts.empty())
		std::cout << "==> ";
	for (unsigned int i = 0; i < span.getSize(); i++)
		std::cout << span[i] << " ";
	std::cout << "\n";
}

// int main()
// {
// 	Span span1(4);

// 	try {
// 		span1.addNumber(0);
// 		span1.addNumber(111);
// 		span1.addNumber(2);
// 		span1.addNumber(-1);
// 	}
// 	catch (std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << "\n";
// 	}
	
// 	std::cout << "span: ";
// 	printElements(span1);

// 	try {

// 		int shortest = span1.shortestSpan();
// 		int longest = span1.longestSpan();
// 		std::cout << "shortest span ==> [" << shortest << "]\n";
// 		std::cout << "longest span ==> [" << longest << "]\n";
// 	}
// 	catch (std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << "\n";
// 	}
// }

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// printElements(sp);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}