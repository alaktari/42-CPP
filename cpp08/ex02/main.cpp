/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:44:11 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/27 09:02:31 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	tests(void)
{
	MutantStack<std::string> mstack;

	mstack.push("111111");
	mstack.push("222222");
	mstack.push("3333333");
	mstack.push("5555555");
	mstack.pop();
	mstack.push("4444444");

	MutantStack<std::string>::iterator it1 = mstack.begin();
	MutantStack<std::string>::iterator it2 = mstack.end();

	for (; it1 != it2; it1++)
		std::cout << *it1 << " ";
	std::cout << "\n";

	it1--;
	
	if (it1 == it2)
		std::cout << "reached the end of the conatainer\n";
	else
		std::cout << "not at the end";

}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// //[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	tests();

	return 0;
}
