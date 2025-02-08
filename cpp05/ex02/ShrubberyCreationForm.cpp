/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:10:39 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/08 17:31:41 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
	// std::cout << "ShrubberyCreationForm Constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm Destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	// std::cout << "ShrubberyCreationForm Copy Constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	// std::cout << "ShrubberyCreationForm Copy Assignment called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void	treesASCII(const std::string target)
{
	std::ofstream file;
	std::string fileName = target + "_shrubbery";
	file.open(fileName.c_str());

	std::string tree[10] = 
	{"               ,@@@@@@@,\n",
	"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n",
	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n",
	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n",
	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n",
	"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n",
	"   `&%\\ ` /%&'    |.|        \\ '|8'\n",
	"       |o|        | |         | |\n",
	"       |.|        | |         | |\n",
	"     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_\n"};

	for (int i = 0; i < 10; i++)
		file << tree[i];
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor)
{	
	if (!getSignedStatus())
		throw UnsignedFormException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(GRADE_ISLOWER);
	treesASCII(target);
	std::cout << "Form executed successfully 😊\n";
}