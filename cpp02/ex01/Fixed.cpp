#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed(void) : fixed(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
    this->fixed = number * (1 << fractional_bits);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(number * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		fixed = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called\n";
	return fixed;
}

void	Fixed::setRawBits( int const bits)
{
	this->fixed = bits;
}

float	Fixed::toFloat( void ) const
{
	// std::cout << "toFloat function called" << std::endl;
	return ((float)(this->fixed) / (1 << fractional_bits));
}

int	Fixed::toInt( void ) const
{
	// std::cout << "toInt function called" << std::endl;
	return (this->fixed >> fractional_bits);
}

std::ostream &operator<<(std::ostream &output_stream, const Fixed &obj)
{
	// Overload insertion operation called
	output_stream << obj.toFloat();
	return (output_stream);
}
