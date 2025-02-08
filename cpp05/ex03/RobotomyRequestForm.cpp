/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:35:49 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/08 17:28:39 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("RobotomyRequestForm", 72, 45), target(_target)
{
	// std::cout << "RobotomyRequestForm Constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm Destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
	// std::cout << "RobotomyRequestForm Copy Constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	// std::cout << "RobotomyRequestForm Copy Assignment called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (!getSignedStatus())
		throw UnsignedFormException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(GRADE_ISLOWER);

	std::cout << "BZZZZZT! Drilling noises...\n";
	std::srand(std::time(0));
	if (rand() % 2 == 0)  // 50% chance of success
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed! " << target << " is still alive." << std::endl;
}