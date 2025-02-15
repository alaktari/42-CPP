/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_templates.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:22:42 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/15 20:37:29 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_TEMPLATES_HHP
#define FUNCTION_TEMPLATES_HHP

#include <typeinfo>

template <typename anyType>
void printElem(anyType& elem)
{
	std::cout << elem << "\n";
}

#endif