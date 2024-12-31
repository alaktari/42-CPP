/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:34:56 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/31 16:37:38 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
    std::cout << "IMateriaSource Constructor called\n";
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    std::cout << "IMateriaSource Copy Constructor called\n";
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
    std::cout << "IMateriaSource Copy Assignment called\n";
    return *this;
}

IMateriaSource::~IMateriaSource(void)
{
    std::cout << "IMateriaSource Destructor called\n";
}
