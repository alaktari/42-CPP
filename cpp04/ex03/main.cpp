/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:39:56 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/01 16:13:22 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Cure.hpp"
#include "Character.hpp"

int main()
{
    
    Character a;
    Ice ice;
    Cure cure;

    AMateria *mat1 = ice.clone();
    AMateria *mat2 = cure.clone();

    a.equip(mat1);
    a.equip(mat2);

    Character b = a;

    delete b.unequip(1);

    return 0;
}