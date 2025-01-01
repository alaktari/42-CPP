/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:05:51 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/01 11:47:57 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		virtual ~Ice(void) ;
		Ice(const Ice& other);
		Ice& operator=(const Ice& Ice);
		
		AMateria *clone(void) const;
		void use(ICharacter& target);
};

#endif