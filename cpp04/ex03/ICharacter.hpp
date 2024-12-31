/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:09:19 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/31 16:30:22 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class ICharacter
{
	protected:
		std::string name;
	public:
		ICharacter(void);
		ICharacter(std::string name);
		ICharacter(const ICharacter& other);
		ICharacter& operator=(const ICharacter& other);
		virtual ~ICharacter(void);
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif