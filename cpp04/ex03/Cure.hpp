/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:00:08 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/01 11:50:14 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        virtual ~Cure(void);
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        
        AMateria* clone(void) const;
        void use(ICharacter& target);
};

#endif