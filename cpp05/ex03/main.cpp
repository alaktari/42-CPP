/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:00:30 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/08 21:15:48 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Intern someRandomIntern;

	AForm* rrf1 = someRandomIntern.makeForm("Shrubbery request", "Bender1");
	AForm* rrf2 = someRandomIntern.makeForm("robotomy request", "Bender2");
	AForm* rrf3 = someRandomIntern.makeForm("PresidentialPardonF request", "Bender3");
	AForm* rrf4 = someRandomIntern.makeForm("blabla request", "Bender4");

	delete rrf1;
	delete rrf2;
	delete rrf3;
	delete rrf4;

}