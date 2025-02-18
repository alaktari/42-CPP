/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:32:59 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/18 10:37:19 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	// std::cout << "Intern Constructor called\n";
	availableRequests[0] = "Shrubbery request";
	availableRequests[1] = "robotomy request";
	availableRequests[2] = "PresidentialPardonF request";
}

Intern::~Intern(void)
{
	// std::cout << "Intern Destructor called\n";
}

Intern::Intern(const Intern& other)
{
	// std::cout << "Intern Copy Constructor called\n";
	for (int i = 0; i < 3; i++)
		availableRequests[i] = other.availableRequests[i];
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 3; i++)
			availableRequests[i] = other.availableRequests[i];
	}
	return *this;
}

AForm* Intern::makeForm(std::string _name, std::string _target)
{
	int requestIndex = 0;

	while (requestIndex < 3 && _name != availableRequests[requestIndex])
		requestIndex++;
	if (requestIndex < 3)
		std::cout << "Intern creates " << _name << " form\n";
	switch (requestIndex)
	{
		case 0:
			return new ShrubberyCreationForm(_target);
		case 1:
			return new RobotomyRequestForm(_target);
		case 2:
			return new PresidentialPardonForm(_target);
		case 3:
			std::cout << "==> Intern cannot create " << _name << " form" << " 👎" << std::endl;
	}
	return NULL;
}