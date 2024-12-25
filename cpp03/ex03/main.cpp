/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/24 15:32:39 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	{
		FragTrap frag;
		std::cout << std::endl;

		frag.attack("EVIL");
		frag.highFivesGuys();
		frag.takeDamage(100);
		frag.attack("EVIL");
		frag.beRepaired(100);

		std::cout << std::endl;
	}
	std::cout << "===================================\n";
	{
		FragTrap	frag("LBATAL");
		std::cout << std::endl;

		frag.attack("WELD_NASS");
		frag.takeDamage(99);
		frag.beRepaired(19);
		frag.attack("WELD_NASS");
		frag.takeDamage(50);
		frag.beRepaired(100);
		frag.attack("WELD_NASS");
		frag.highFivesGuys();
		
		std::cout << std::endl;
	}
}
