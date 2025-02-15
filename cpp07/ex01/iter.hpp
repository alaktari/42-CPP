/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:02:00 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/15 20:56:32 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <climits>

template <typename anyType>
void	iter(anyType* ptr, int lenght, void (*func)(anyType& elem))
{
	for (int i = 0; i < lenght; i++)
        func(ptr[i]);
}

#endif