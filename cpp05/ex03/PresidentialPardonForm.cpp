/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:26:28 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/18 10:29:56 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm("PresidentialPardonForm", 25, 5), target(_target)
{
	// std::cout << "PresidentialPardonForm Constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm Destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
	// std::cout << "PresidentialPardonForm Copy Constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	// std::cout << "PresidentialPardonForm Copy Assignment called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSignedStatus())
		throw UnsignedFormException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(GRADE_ISLOWER);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}