/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/30 14:20:16 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap a;
		std::cout << std::endl;
		
		a.attack("EVIL");
		a.takeDamage(50);
		a.attack("EVIL");
		a.takeDamage(30);
		a.attack("EVIL");
		a.beRepaired(5);
		a.takeDamage(30);
		a.beRepaired(100);
	
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		ScavTrap b("HERO");
		std::cout << std::endl;
		
		b.attack("EVIL");
		b.attack("EVIL");
		b.takeDamage(50);
		b.attack("EVIL");
		b.attack("EVIL");
		b.takeDamage(20);
		b.attack("EVIL");
		b.guardGate();
		b.beRepaired(50);
		b.takeDamage(30);
		b.attack("EVIL");
		b.beRepaired(10);
		b.takeDamage(50);
		b.attack("EVIL");
		b.attack("EVIL");
		b.attack("EVIL");
		b.takeDamage(50);
		b.beRepaired(100);

		std::cout << std::endl;
	}

}
