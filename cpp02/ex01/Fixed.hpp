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

};

// 6. Overload insertion operator
std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed);


#endif