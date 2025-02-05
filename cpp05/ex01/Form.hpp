/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:54 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/05 19:46:13 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#define GRADE_ISLOWER 1
#define	REQUIREDGRADE_TOOLOW 2

class Form
{
	private:
		const std::string	name;
		bool				signedStatus;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		Form(void);
		Form(std::string name, const int _gradeToSign, const int _gradeToExecute);
		~Form(void);
		Form(const Form& other);
		Form& operator=(const Form& other);
		std::string	getName(void) const;
		int			getSignedStatus(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(Bureaucrat& bureaucrat);

		//  -------------- Exception classes ------------------

		class GradeTooHighException : public std::exception
		{
			private:
				std::string	errorMssg;
			public:
				GradeTooHighException(void);
				const char* what() const throw();
				~GradeTooHighException(void) throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string errorMssg;
			public:
				GradeTooLowException(int excep);
				const char* what() const throw();
				~GradeTooLowException(void) throw();
		};
};

std::ostream &operator<<(std::ostream &output_stream, const Form& obj);

#endif 