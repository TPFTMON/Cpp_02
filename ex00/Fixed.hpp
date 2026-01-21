#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {

    private:
        int _value;
        static const int _fraction;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &assign);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif
