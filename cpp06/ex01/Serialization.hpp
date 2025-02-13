/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:38:05 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/13 16:37:49 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <string>
#include <iostream>

typedef unsigned long uintptr_t;

struct Data
{
	std::string name;
};

class Serialization
{
	private:
		Serialization(void);
		~Serialization(void);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif