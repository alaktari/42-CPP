/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:55:24 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/21 11:23:39 by alaktari         ###   ########.fr       */
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
	std::cout << "The actual type of the object pointed to by 'p' is ";

	if (dynamic_cast<A*>(p))
		std::cout << "'A'";
	else if (dynamic_cast<B*>(p))
		std::cout << "'B'";
	else if (dynamic_cast<C*>(p))
		std::cout << "'C'";
	else
	{
		std::cout << "None of them!!\n";
		return ;
	}
	std::cout << " (using pointer)\n";
}

void identify(Base& p)
{
	std::cout << "The actual type of the object pointed to by 'p' is ";

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "'A'";
	}
	catch (std::exception& e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "'B'";
		}
		catch (std::exception& e) {
			try {
					(void)dynamic_cast<C&>(p);
					std::cout << "'C'";
			}
			catch (std::exception& e) {
				std::cout << "None of them!!\n";
				return ;
			}
		}
	}
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