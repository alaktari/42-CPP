/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:07:57 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/05 22:22:35 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Unkown"), signedStatus(false), gradeToSign(150), gradeToExecute(150)
{
	// std::cout << "Default Constructor Called\n";
}

Form::Form(std::string name, const int _gradeToSign, const int _gradeToExecute) : name(name),
			signedStatus(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	// std::cout << "Constructor called\n"
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException(REQUIREDGRADE_TOOLOW);
}

Form::~Form(void)
{
	// std::cout << "Form destructor called\n";
}

Form::Form(const Form& other) : name(other.name), signedStatus(other.signedStatus),
			gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	// std::cout << "Copy Constructor called\n";
}

Form& Form::operator=(const Form& other)
{
	// std::cout << "Copy Assignment called\n";
	if (this != &other)
		this->signedStatus = other.signedStatus;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(void)
{
	errorMssg = "the required Grade is too High";
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return errorMssg.c_str();
}

Form::GradeTooLowException::GradeTooLowException(int excep)
{
	if (excep == GRADE_ISLOWER)
		errorMssg =	"The Bureaucrat's grade is lower than the required grade";
	else
		errorMssg = "the required Grade is too Low";
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
	return errorMssg.c_str();
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException(GRADE_ISLOWER);
	signedStatus = true;
}

std::string	Form::getName(void) const
{
	return name;
}

int	Form::getSignedStatus(void) const
{
	return signedStatus;
}

int Form::getGradeToSign(void) const
{
	return gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return gradeToExecute;	
}

std::ostream&	operator<<(std::ostream &output_stream, const Form& obj)
{
	output_stream << "Form '" << obj.getName() << "' is ";
	if (obj.getSignedStatus())
		output_stream << "[signed] 👍👍";
	else
		output_stream << "[not signed] 👎👎";
	output_stream << "\n(grade required to sign it: " << obj.getGradeToSign();
	output_stream << " || grade required to execute it: " << obj.getGradeToExecute();
	output_stream << ")\n";

	return output_stream;
}