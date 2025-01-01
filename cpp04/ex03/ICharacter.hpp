/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:09:19 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/01 16:09:17 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter(void);
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual AMateria* unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif