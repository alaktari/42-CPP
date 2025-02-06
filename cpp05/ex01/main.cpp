/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:00:30 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/06 11:48:11 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void requiredGradeTooLow(void)
{
	try
	{
		Form	contractForm("Contract", 200, 100);

		std::cout << contractForm;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
}

void    requiredGradeTooHigh(void)
{
	try
	{
		Form	contractForm("Contract", 5, 0);

		std::cout << contractForm;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
}

void	bureaucratGradeTooLow(void)
{
	try
	{
		Bureaucrat	bureaucrat("johnBureaucrat", 80);
		Form		contractForm("Contract", 50, 1);

		contractForm.beSigned(bureaucrat);
		std::cout << contractForm;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
}

void	validRequiredGrade(void)
{
	Form	*Ptr;

	try
	{
		Bureaucrat	bureaucrat("johnBureaucrat", 3);
		Ptr = new Form("Contract", 5, 100);

		std::cout << *Ptr;
		Ptr->beSigned(bureaucrat);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
		return ;
	}
	std::cout << "===============================\n";
	std::cout << *Ptr;
	delete Ptr;
}

void	signFormMethod(void)
{
	Bureaucrat	bureaucrat("johnBureaucrat", 100);
	Form		contractForm("Contract", 50, 50);

	std::cout << bureaucrat;
	bureaucrat.signForm(contractForm);
}

void	generalTest(void)
{
	Bureaucrat	bureaucrat("johnBureaucrat", 11);
	Form		contractFrom("Contract", 10, 10);
	
	std::cout << "========================\n";
	std::cout << bureaucrat;
	std::cout << contractFrom;
	try {	
		contractFrom.beSigned(bureaucrat);
	}
	catch (std::exception& e) {
		std::cout << "----------------------------------------\n";
		std::cout << e.what() << "\n";
		std::cout << "----------------------------------------\n";
	}

	bureaucrat.incrementGrade();
	std::cout << bureaucrat;
	contractFrom.beSigned(bureaucrat);
	std::cout << "========================\n";
	std::cout << contractFrom;
}

int main()
{
	// requiredGradeTooLow();
	// requiredGradeTooHigh();
	// bureaucratGradeTooLow();
	// validRequiredGrade();
	// signFormMethod();
	// generalTest();
}