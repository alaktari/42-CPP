/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:27:23 by alaktari          #+#    #+#             */
/*   Updated: 2025/02/08 19:43:19 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    private:
        std::string availableRequests[3];  
    public:
        Intern(void);
        ~Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string _name, std::string _target);
};

#endif