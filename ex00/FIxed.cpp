#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
}


Fixed & Fixed::operator=(const Fixed &assign){
    (void) assign;
    return *this;
}


Fixed::~Fixed(){
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}



// Other public methods:
int Fixed::getRawBits(void) const {

}


void Fixed::setRawBits(int const raw) {

}
