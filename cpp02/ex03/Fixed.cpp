#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed(void) : fixed(0)
{
	// std::cout << "Default construct called\n";
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::Fixed(const int number)
{
	// std::cout << "Int construcotr called\n";
    this->fixed = number << fractional_bits;
}

Fixed::Fixed(const float number)
{
	// std::cout << "Float construct called\n";
	this->fixed = (int)(roundf(number * (1 << fractional_bits)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operation called\n";
	if (this != &other)
		fixed = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	return fixed;
}

void	Fixed::setRawBits( int const bits)
{
	this->fixed = bits;
}

float	Fixed::toFloat( void ) const
{
	return (float)(fixed) / (1 << fractional_bits);
}

int	Fixed::toInt( void ) const
{
	return (this->fixed >> fractional_bits);
}

int	Fixed::getFractionalBits(void)
{
	return fractional_bits;
}

std::ostream &operator<<(std::ostream &output_stream, const Fixed &obj)
{
	// std::cout << "Overload insertion operator called\n";
	output_stream << obj.toFloat();
	return (output_stream);
}

Fixed& Fixed::min(Fixed& ref1, Fixed &ref2)
{
	// std::cout << "max called\n";
	return (ref1.fixed < ref2.fixed) ? ref1 : ref2;
}

const Fixed& Fixed::min(const Fixed& ref1, const Fixed& ref2)
{
	// std::cout << "const max called\n";
	return (ref1.fixed < ref2.fixed) ? ref1 : ref2;
}

Fixed& Fixed::max(Fixed& ref1, Fixed& ref2)
{
	// std::cout << "max called\n";
	return (ref1.fixed > ref2.fixed) ? ref1 : ref2;
}

const Fixed& Fixed::max(const Fixed& ref1, const Fixed& ref2)
{
	// std::cout << "const max called\n";
	return (ref1.fixed > ref2.fixed) ? ref1 : ref2;
}

float	Fixed::operator+(const Fixed& other) const
{
	// std::cout << "Overload Additing operation called\n";
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed& other) const
{
	// std::cout << "Overload Subtraction operation called\n";
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed& other) const
{
	// std::cout << "Overload Multiplication operation called\n";
	return ((this->toFloat() * other.toFloat()));
}

float	Fixed::operator/(const Fixed& other) const
{
	// std::cout << "Overload Division operation called\n";
	if (other.fixed == 0)
	{
        std::cerr << "Error: Division by zero" << std::endl;
        return (0);
    }
	return (this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed& other) const
{
	// std::cout << "Overload Greater than operation called\n";
	return this->fixed > other.fixed;
}

bool Fixed::operator<(const Fixed& other) const
{
	// std::cout << "Overload Less than operation called\n";
	return this->fixed < other.fixed;
}

bool Fixed::operator>=(const Fixed& other) const
{
	// std::cout << "Overload Greater than or equal to operation called\n";
	return this->fixed >= other.fixed;
}

bool Fixed::operator<=(const Fixed& other) const
{
	// std::cout << "Overload Less than or equal to operation called\n";
	return this->fixed <= other.fixed;
}

bool Fixed::operator==(const Fixed& other) const
{
	// std::cout << "Overload Equal to operation called\n";
	return this->fixed == other.fixed;
}

bool Fixed::operator!=(const Fixed& other) const
{
	// std::cout << "Overload Not equal to operation called\n";
	return this->fixed != other.fixed;
}

Fixed Fixed::operator++(int)
{
	// std::cout << "Overload Postfix Increment operation called\n";
	Fixed old = *this;
	fixed++;
	return old;
}

Fixed Fixed::operator++()
{
	// std::cout << "Overload Prefix Increment operation called\n";
	fixed++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	// std::cout << "Overload Postfix Decrement operation called\n";
	Fixed old = *this;
	fixed--;
	return old;
}

Fixed Fixed::operator--()
{
	// std::cout << "Overload Prefix Decrement operation called\n";
	fixed--;
	return *this;
}