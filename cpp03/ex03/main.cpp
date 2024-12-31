/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:28 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/30 15:03:31 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Diamond");
    std::cout << "\n\n";

    diamond.attack("enemy");
    diamond.takeDamage(20);
    diamond.beRepaired(15);
    diamond.highFivesGuys();
    diamond.whoAmI();

    std::cout << "\n\n";
    return 0;
}
