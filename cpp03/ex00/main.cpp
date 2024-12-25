/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/11/19 10:36:40 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap a;
		std::cout << std::endl;
		
		a.attack("EVIL");
		a.takeDamage(5);
		a.attack("EVIL");
		a.takeDamage(10);
		a.attack("EVIL");
		a.beRepaired(5);
		
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		ClapTrap b("HERO");
		std::cout << std::endl;
		
		b.attack("EVIL");
		b.attack("EVIL");
		b.takeDamage(2);
		b.attack("EVIL");
		b.attack("EVIL");
		b.takeDamage(7);
		b.attack("EVIL");
		b.beRepaired(5);
		b.takeDamage(4);
		b.attack("EVIL");
		b.beRepaired(5);
		b.takeDamage(1);
		b.attack("EVIL");
		b.attack("EVIL");
		b.attack("EVIL");

		std::cout << std::endl;
	}
}