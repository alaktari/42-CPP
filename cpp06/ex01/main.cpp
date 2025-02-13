/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:21:22 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/13 16:39:25 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data		data;
	uintptr_t	*ptr;

	data.name = "karim";
	uintptr_t uidtValue = Serialization::serialize(&data);
	Data *DataPtr = Serialization::deserialize(uidtValue);

	std::cout << "data name: " << data.name << "\n";
	std::cout << "returned uintptr_t value: " << uidtValue << "\n";
	std::cout << "returned data value: " << DataPtr->name << "\n";

	// Serialization obj; // Error 
	
}