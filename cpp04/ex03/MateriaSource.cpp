/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:22:27 by alaktari          #+#    #+#             */
/*   Updated: 2025/01/02 11:33:27 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

void MateriaSource::initializeMaterias(void)
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;   
}

void MateriaSource::copyMateria(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

void MateriaSource::clearMaterias(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
		{
			// // std::cout << "====>   I'm clearing <==== \n";
			delete materias[i];
			materias[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(void)
{
	initializeMaterias();
	// std::cout << "Materia Constructor called\n";
}

MateriaSource::~MateriaSource(void)
{
	clearMaterias();
	// std::cout << "Materia destructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	if (this != &other)
		copyMateria(other);
	// std::cout << "Materia Copy Constructor called\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		clearMaterias();
		copyMateria(other);
	}
	// std::cout << "MateriaSource Copy Assignment called\n";
	return *this;
}


void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			materias[i] = materia->clone();
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}