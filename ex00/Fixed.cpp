#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "\e[0;33mDefault Constructor\e[0m called of " << FIXED << "\n";

    this->_value = 0;
}

Fixed::Fixed(const Fixed &to_copy){
    std::cout << "\e[0;33mCopy Constructor\e[0m called of " << FIXED << "\n";

    this->_value = to_copy._value;
}


Fixed & Fixed::operator=(const Fixed &other){
    std::cout << "\e[0;35mCopy assignment operator\e[0m called of " << FIXED << "\n";

    if (this != &other){
        this->_value = other.getRawBits();
    }
    return *this;
}


Fixed::~Fixed(){
    std::cout << "\e[0;31mDestructor\e[0m called of " << FIXED << "\n";

}



// Other public methods:
int Fixed::getRawBits(void) const {
    std::cout << "\e[0;35mgetRawBits member function\e[0m called of " << FIXED << "\n";

    return (this->_value);
}


void Fixed::setRawBits(int const raw) {
    std::cout << "\e[0;35msetRawBits member function\e[0m called of " << FIXED << "\n";

    this->_value = raw;
}
