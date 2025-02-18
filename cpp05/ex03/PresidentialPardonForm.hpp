/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:11:34 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/18 10:29:49 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string				target;
	public:
								PresidentialPardonForm(std::string _target);
								~PresidentialPardonForm();
								PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		void				    execute(Bureaucrat const & executor) const ;
};

#endif