/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:55:24 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/15 10:22:51 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

Base * generate(void)
{
	int randomNum = (std::rand() % 3);
	
	switch(randomNum)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	std::cout << "The actual type of the object pointed to by p is ";

	if (dynamic_cast<A*>(p))
		std::cout << "'A'";
	else if (dynamic_cast<B*>(p))
		std::cout << "'B'";
	else
		std::cout << "'C'";
	std::cout << " (using pointer)\n";
}

void identify(Base& p)
{
	std::cout << "The actual type of the object pointed to by p is ";

	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "'A'";
		static_cast<void>(a);
	} catch (std::exception& e) { /* Do nothing */ }

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "'B'";
		static_cast<void>(b);
	} catch (std::exception& e) { /* Do nothing */ }

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "'C'";
		static_cast<void>(c);
	} catch (std::exception& e) { /* Do nothing */ }
	

	std::cout << " (using reference)\n";
}

int main()
{
    std::srand(std::time(0));

    Base *p;

    p = generate();
    identify(p);
    identify(*p);

    delete p;
}