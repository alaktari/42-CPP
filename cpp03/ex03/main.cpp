/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/26 14:38:27 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Diamond");

    diamond.attack("enemy"); // From ScavTrap
    diamond.takeDamage(20);  // From ClapTrap
    diamond.beRepaired(15);  // From ClapTrap
    diamond.highFivesGuys(); // From FragTrap
    diamond.whoAmI();        // Unique to DiamondTrap

    std::cout << "\n\n";
    diamond.whoAmI();
    std::cout << "\n\n";

    return 0;
}
