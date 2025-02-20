/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:21:22 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/20 12:08:04 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		data;

	data.name = "karim";
	data.age = 22;
	uintptr_t uidtValue = Serializer::serialize(&data);
	Data *DataPtr = Serializer::deserialize(uidtValue);

	std::cout << "data name: " << data.name << "\n";
	std::cout << "data age: " << data.age << "\n";
	std::cout << "================================\n";
	std::cout << "returned uintptr_t value: " << uidtValue << "\n";
	std::cout << "returned data name: " << DataPtr->name << "\n";
	std::cout << "returned data age: " << DataPtr->age << "\n";


	// Serializer obj; // Error
	
}