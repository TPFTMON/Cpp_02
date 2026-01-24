#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << DEF_CONSTR_MSG << FIXED << "\n";

    this->_value = 0;
}

Fixed::Fixed( const Fixed &to_copy ){
    std::cout << COPY_CONSTR_MSG << FIXED << "\n";

    this->_value = to_copy._value;
}

Fixed::Fixed( const float num ){
    std::cout << FLOAT_CONSTR_MSG << "\n";
    // Multiply by 256 (1 << 8) and round to nearest integer
    // this->_value = roundf(num * (1 << _fraction)); // (?)
}

Fixed::Fixed( const int num ){
    std::cout << INT_CONSTR_MSG << "\n";
    // Shift bits left to make room for fraction
    // this->_value = num << _fraction; (?)
}

Fixed& Fixed::operator=( const Fixed &other ){
    std::cout << COPY_ASSIGN_OP_MSG << FIXED << "\n";

    if (this != &other){
        this->_value = other._value;
    }
    return *this;
}


Fixed::~Fixed(){
    std::cout << DESTR_MSG << FIXED << "\n";

}



// Other public methods:
int Fixed::getRawBits( void ) const{
    std::cout << GET_RAW_BITS_MSG << FIXED << "\n";

    return (this->_value);
}


void Fixed::setRawBits( int const raw ){
    std::cout << SET_RAW_BITS_MSG << FIXED << "\n";

    this->_value = raw;
}

float   Fixed::toFloat( void ) const{
    std::cout << TO_FLOAT_MSG << FIXED << "\n";

    // Cast to float to avoid integer division
    // return (float)this->_value / (float)(1 << _fraction); // (?)
}

int     Fixed::toInt( void ) const{
    std::cout << TO_INT_MSG << FIXED << "\n";

    // Shift right to discard fraction
    // return this->_value >> _fraction; // (?)
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed){
    os << fixed.toFloat();
    return (os);
}
