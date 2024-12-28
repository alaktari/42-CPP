/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaktari <alaktari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:13:25 by alaktari          #+#    #+#             */
/*   Updated: 2024/12/28 21:40:03 by alaktari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual void makeSound(void) const;
		std::string getType(void) const;
};

/*
What Happens Internally:
	When a method is virtual, the compiler creates a vtable (virtual table) for the class.
	Each class object has a vptr (virtual pointer) that points to the vtable. At runtime,
	the vtable is used to resolve the correct method to call based on the actual object type,
	not the pointer type.

Without virtual:
	The compiler uses the type of the pointer/reference to determine which method to call at compile time.

With virtual:
	The compiler defers the decision to runtime, using the vtable to call the correct method based
	on the actual type of the object
*/

/*
Why Make Destructors Virtual?
	In C++, when you delete an object through a pointer to the base class,
	the destructor that gets called depends on whether the destructor is virtual:

			*If the destructor is not virtual:

				Only the base class destructor is called.
				The derived class destructor is not called,
				which can lead to resource leaks if the derived class allocated resources
				that need to be released.
				
			*If the destructor is virtual:

				The derived class destructor is called first, followed by the base class destructor.
				This ensures proper cleanup of the derived class resources.
*/

#endif