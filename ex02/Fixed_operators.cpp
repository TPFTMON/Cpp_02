#include "Fixed.hpp"

bool Fixed::operator>(const Fixed& other) const {
    return (_value > other._value);
}


bool Fixed::operator<(const Fixed& other) const {
    return (_value < other._value);
}


bool Fixed::operator>=(const Fixed& other) const {
    return (_value >= other._value);
}


bool Fixed::operator<=(const Fixed& other) const {
    return (_value <= other._value);
}


bool Fixed::operator==(const Fixed& other) const {
    return (_value == other._value);
}


bool Fixed::operator!=(const Fixed& other) const {
    return (_value != other._value);
}


