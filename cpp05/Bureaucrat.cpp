/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:54:56 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/04 16:15:17 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Unkown"), grade(150)
{
	// std::cout << "Default Bureaucrat Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	// std::cout << "Parameterized Bureaucrat Constructor called\n";
	if (grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat Destructor called\n";
}

std::string Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	// std::cout << "Bureaucrat Copy Constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

void Bureaucrat::decrementGrade(void)
{
	grade++;
	if (grade > 150)
		throw GradeTooLowException();
}
			
void Bureaucrat::incrementGrade(void)
{
	grade--;
	if (grade < 1)
		throw GradeTooHighException();
}
	
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the Grade is too high";
}	

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the Grade is too Low";
}

std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat& obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return output_stream;
}