/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:43:54 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/08 20:46:09 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#define GRADE_ISLOWER 1
#define	REQUIREDGRADE_TOOLOW 2

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				signedStatus;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
							AForm(void);
							AForm(std::string name, const int _gradeToSign, const int _gradeToExecute);
							virtual ~AForm(void);
							AForm(const AForm& other);
		AForm& 				operator=(const AForm& other);
		std::string			getName(void) const;
		int					getSignedStatus(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(Bureaucrat const & bureaucrat);
		virtual void		execute(Bureaucrat const & executor) = 0;

		//  -------------- Exception classes ------------------

		class GradeTooHighException : public std::exception
		{
			private:
				std::string	errorMssg;
			public:
							GradeTooHighException(void);
							~GradeTooHighException(void) throw();
				const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string errorMssg;
			public:
							GradeTooLowException(int excep);
							~GradeTooLowException(void) throw();
				const char*	what() const throw();
		};
		class UnsignedFormException : public std::exception
		{
			private:
				std::string	errorMssg;
			public:
							UnsignedFormException(void);
							~UnsignedFormException(void) throw();
				const char*	what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output_stream, const AForm& obj);

#endif 