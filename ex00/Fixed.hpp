#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

// Messages:
# define FIXED "\e[0;32mFixed\e[0m"

# define DEF_CONSTR_MSG "\e[0;33mDefault Constructor\e[0m called of "
# define COPY_CONSTR_MSG "\e[0;33mCopy Constructor\e[0m called of "
# define COPY_ASSIGN_OP_MSG "\e[0;35mCopy assignment operator\e[0m called of "
# define DESTR_MSG "\e[0;31mDestructor\e[0m called of "
# define GET_RAW_BITS_MSG "\e[0;35mgetRawBits member function\e[0m called of "
# define SET_RAW_BITS_MSG "\e[0;35msetRawBits member function\e[0m called of "

// Class implementations:
class Fixed {

    private:
        int _value;
        static const int _fraction;        // This is basically the rule by which we get the actual number

    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif
