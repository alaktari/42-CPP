/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:54:56 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/05 17:37:51 by alaktari         ###   ########.fr       */
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
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}
			
void Bureaucrat::incrementGrade(void)
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}
	
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the Bureaucrat Grade is too high";
}	

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the Bureaucrat Grade is too Low";
}

std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat& obj)
{
	output_stream << obj.getName() << ", bureaucrat grade: " << obj.getGrade() << "\n";
	return output_stream;
}