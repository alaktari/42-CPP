/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:19 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/18 10:29:46 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> 
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string				target;
	public:
								RobotomyRequestForm(std::string _target);
								~RobotomyRequestForm();
								RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);
		void				    execute(Bureaucrat const & executor) const ;
};

#endif