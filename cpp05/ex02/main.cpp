/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:00:30 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/18 10:28:46 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void Failed_ShrubberyCreationForm(void)
{
	ShrubberyCreationForm obj("home");
	Bureaucrat bureaucrat("bob", 140);

	bureaucrat.signForm(obj);

	try {
		obj.execute(bureaucrat);
	}
	catch (std::exception& e)
	{
		std::cout << "Form execution failed: " << e.what() << "\n";
	}
}
void valid_ShrubberyCreationForm(void)
{
	ShrubberyCreationForm obj("home");
	Bureaucrat bureaucrat("bob", 130);

	bureaucrat.signForm(obj);

	try {
		obj.execute(bureaucrat);
	}
	catch (std::exception& e)
	{
		std::cout << "Form execution failed: " << e.what() << "\n";
	}
}

void	failed_RobotomyRequestForm(void)
{
	RobotomyRequestForm obj("home");
	Bureaucrat bureaucrat("bob", 100);

	try{
		obj.execute(bureaucrat);
	}
	catch (std::exception& e)
	{
		std::cout << "the robotomy failed: " << e.what() << "\n";
	}
		
}

void	valid_RobotomyRequestForm(void)
{
	RobotomyRequestForm obj("home");
	Bureaucrat bureaucrat("bob", 10);

	bureaucrat.signForm(obj);

	try{
		obj.execute(bureaucrat);
	}
	catch (std::exception& e)
	{
		std::cout << "the robotomy failed: " << e.what() << "\n";
	}
}

void	failed_PresidentialPardonForm(void)
{
	PresidentialPardonForm obj("home");
	Bureaucrat bureaucrat("bob", 6);

	bureaucrat.signForm(obj);
	
	try{
		obj.execute(bureaucrat);
	}
	catch (std::exception& e)
	{
		std::cout << "The pardon failed: " << e.what() << "\n";
	}
	
}

void	vaild_PresidentialPardonForm(void)
{
	PresidentialPardonForm obj("home");
	Bureaucrat bureaucrat("bob", 5);

	bureaucrat.signForm(obj);
	
	try{
		obj.execute(bureaucrat);
	}
	catch (std::exception& e)
	{
		std::cout << "The pardon failed: " << e.what() << "\n";
	}
	
}

void	failed_executeFormMethod(void)
{
	PresidentialPardonForm obj("home");
	Bureaucrat bureaucrat("bob", 6);

	bureaucrat.signForm(obj);
	try {
		bureaucrat.executeForm(obj);
	}
	catch (std::exception& e)
	{
		std::cout << "failed to execute: " << e.what() << "\n";
	}
}

void	valid_executeFormMethod(void)
{
	PresidentialPardonForm obj("home");
	Bureaucrat bureaucrat("bob", 5);

	bureaucrat.signForm(obj);

	try {
		bureaucrat.executeForm(obj);
	}
	catch (std::exception& e)
	{
		std::cout << "failed to execute: " << e.what() << "\n";
	}
}

int main()
{

	// Failed_ShrubberyCreationForm();
	// valid_ShrubberyCreationForm();

	// failed_RobotomyRequestForm();
	// valid_RobotomyRequestForm();

	// failed_PresidentialPardonForm();
	// vaild_PresidentialPardonForm();

	// failed_executeFormMethod();
	// valid_executeFormMethod();
	
}