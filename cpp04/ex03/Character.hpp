/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:06:01 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/01 16:08:13 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *slot[4];
		
		void clearSlots(void);
		void initializeSlots(void);
		void copySlots(const Character& other);
	
	public:
		Character(void);
		Character(const std::string& name);
		~Character(void);
		Character(const Character& other);
		Character& operator=(const Character& other);
		
		virtual std::string const & getName(void) const;
		virtual void equip(AMateria* m);
		virtual AMateria* unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

# endif