#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int                 fixed;
		static const int    fractional_bits;
	public:
		// 1. Default Constructors
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);

		// 2. Copy Constructor
		Fixed(const Fixed &other);

		// 3. Copy Assignment operator overload
		Fixed &operator=(const Fixed &other);

		// 4. Destructor
		~Fixed(void);

		// 5. Member Functions
		int getRawBits( void ) const;
		void    setRawBits( int const bits);
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed& min(Fixed& ref1, Fixed &ref2);
		static const Fixed& min(const Fixed& ref1, const Fixed& ref2);
		static Fixed& max(Fixed& ref1, Fixed& ref2);
		static const Fixed& max(const Fixed& ref1, const Fixed& ref2);

		/* - - 7. The 6 comparison operators: (>, <, >=, <=, == and !=) - - */
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		/* - - 8. the 4 arithmetic operators (+, -, *, and /) - - - - - - - - */
		float	operator+(const Fixed& other) const;
		float	operator-(const Fixed& other) const;
		float	operator*(const Fixed& other) const;
		float	operator/(const Fixed& other) const;

		/* - - 9. The 4 increment/decrement - - - - - - - - - - - - - - */
		Fixed operator++(int);
		Fixed operator++();
		Fixed operator--(int);
		Fixed operator--();




};

// 6. Overload insertion operator
std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed);
	 


#endif