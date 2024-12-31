/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:00:08 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/31 20:50:32 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        ~Cure(void);
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        std::string clone(void);

        AMateria* clone() const;
};

#endif