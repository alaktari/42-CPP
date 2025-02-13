/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:48:11 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/13 16:39:03 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization(void) {}
Serialization::~Serialization(void) {}

uintptr_t Serialization::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}