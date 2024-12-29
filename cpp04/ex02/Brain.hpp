/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:06:25 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/29 11:48:29 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Polymorphism.hpp"

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain(void);
        ~Brain(void);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        std::string getIdea(int idea_index);
        void setIdea(std::string new_idea, int idea_index);
        Brain* getBrain(void);
};

#endif