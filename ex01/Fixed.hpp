#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

// Messages:
# define FIXED "\e[0;32mFixed\e[0m"

# define DEF_CONSTR_MSG "\e[0;33mDefault Constructor\e[0m called of "
# define COPY_CONSTR_MSG "\e[0;33mCopy Constructor\e[0m called of "
# define FLOAT_CONSTR_MSG "\e[0;33mFloat Constructor\e[0m called of "
# define INT_CONSTR_MSG "\e[0;33mInt Constructor\e[0m called of "
# define COPY_ASSIGN_OP_MSG "\e[0;35mCopy assignment operator\e[0m called of "
# define DESTR_MSG "\e[0;31mDestructor\e[0m called of "
# define GET_RAW_BITS_MSG "\e[0;35mgetRawBits member function\e[0m called of "
# define SET_RAW_BITS_MSG "\e[0;35msetRawBits member function\e[0m called of "
# define TO_INT_MSG "\e[0;35mtoInt member function\e[0m called of "
# define TO_FLOAT_MSG "\e[0;35mtoFloat member function\e[0m called of "

// Class implementations:
class Fixed {

    private:
        int _value;
        static const int _fraction;

    public:
        Fixed();
        Fixed( const Fixed &copy );
        Fixed( const float num );
        Fixed( const int num );
        Fixed& operator=( const Fixed &assign );
        ~Fixed();

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

};

// Other Fixed functions:
std::ostream& operator<<( std::ostream& os, const Fixed& fixed);

#endif
