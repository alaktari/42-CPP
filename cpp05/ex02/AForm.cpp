/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:07:57 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/08 17:30:02 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("Unkown"), signedStatus(false), gradeToSign(150), gradeToExecute(150)
{
	// std::cout << "Default Constructor Called\n";
}

AForm::AForm(std::string name, const int _gradeToSign, const int _gradeToExecute) : name(name),
			signedStatus(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	// std::cout << "Constructor called\n"
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException(REQUIREDGRADE_TOOLOW);
}

AForm::~AForm(void)
{
	// std::cout << "AForm destructor called\n";
}

AForm::AForm(const AForm& other) : name(other.name), signedStatus(other.signedStatus),
			gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	// std::cout << "Copy Constructor called\n";
}

AForm& AForm::operator=(const AForm& other)
{
	// std::cout << "Copy Assignment called\n";
	if (this != &other)
		this->signedStatus = other.signedStatus;
	return *this;
}

AForm::GradeTooHighException::GradeTooHighException(void)
{
	errorMssg = "the required Grade is too High";
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return errorMssg.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(int excep)
{
	if (excep == GRADE_ISLOWER)
		errorMssg =	"The Bureaucrat's grade is lower than the required grade";
	else
		errorMssg = "the required Grade is too Low";
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw() {}

const char* AForm::GradeTooLowException::what() const throw()
{
	return errorMssg.c_str();
}

AForm::UnsignedFormException::UnsignedFormException(void)
{
	errorMssg = "The form is unsigned";
}

AForm::UnsignedFormException::~UnsignedFormException(void) throw() {}

const char*	AForm::UnsignedFormException::what() const throw()
{
	return errorMssg.c_str();
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException(GRADE_ISLOWER);
	signedStatus = true;
}

std::string	AForm::getName(void) const
{
	return name;
}

int	AForm::getSignedStatus(void) const
{
	return signedStatus;
}

int AForm::getGradeToSign(void) const
{
	return gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return gradeToExecute;	
}

std::ostream&	operator<<(std::ostream &output_stream, const AForm& obj)
{
	output_stream << "AForm '" << obj.getName() << "' is ";
	if (obj.getSignedStatus())
		output_stream << "[signed] 👍👍";
	else
		output_stream << "[not signed] 👎👎";
	output_stream << "\n(grade required to sign it: " << obj.getGradeToSign();
	output_stream << " || grade required to execute it: " << obj.getGradeToExecute();
	output_stream << ")\n";

	return output_stream;
}