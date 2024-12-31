#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int                 fixed;
		static const int    franctional_bits;
	public:
		// 1. Default Constructor
		Fixed(void);

		// 2. Copy Constructor
		Fixed(const Fixed &other);

		// 3. Copy Assignment operator overload
		Fixed &operator=(const Fixed &other);

		// 4. Destructor
		~Fixed(void);

		// 5. Member Function
		int getRawBits( void ) const;

		// 6. Member Function
		void    setRawBits( int const raw );
};


#endif