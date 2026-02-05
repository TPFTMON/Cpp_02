#include "Fixed.hpp"

// ================================================================
//                         ORTHODOX BASE
// ================================================================

const int Fixed::_fraction = 8;

Fixed::Fixed(){

    std::cout << DEF_CONSTR_MSG << FIXED << "\n";

    this->_value = 0;
}

Fixed::Fixed( const Fixed &to_copy ){

    std::cout << COPY_CONSTR_MSG << FIXED << "\n";

    this->_value = to_copy._value;
}

Fixed::Fixed( const float num ){

    std::cout << FLOAT_CONSTR_MSG << FIXED <<"\n";

    // Multiply by 256 (1 << 8) and round to nearest integer
    this->_value = roundf(num * (1 << _fraction));
}

Fixed::Fixed( const int num ){

    std::cout << INT_CONSTR_MSG << FIXED <<"\n";

    // Shift bits left to make room for fraction
    this->_value = num << _fraction;
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



// ================================================================
//                       MEMBER METHODS
// ================================================================

int Fixed::getRawBits( void ) const{

    std::cout << GET_RAW_BITS_MSG << FIXED << "\n";

    return (this->_value);
}

void Fixed::setRawBits( int const raw ){

    std::cout << SET_RAW_BITS_MSG << FIXED << "\n";

    this->_value = raw;
}

float   Fixed::toFloat( void ) const{

    // std::cout << TO_FLOAT_MSG << FIXED << "\n";

    // Divide the raw integer by 256.0
    // Cast to float to avoid integer division
    return (float)this->_value / (float)(1 << _fraction);
}

int     Fixed::toInt( void ) const{

    // std::cout << TO_INT_MSG << FIXED << "\n";

    // Shift right to discard fraction
    return this->_value >> _fraction;
}



// ================================================================
//                           OPERATORS
// ================================================================

bool Fixed::operator>(const Fixed& other) const{

    return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const{

    return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const{

    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const{

    return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const{

    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const{

    return (_value != other._value);
}


Fixed Fixed::operator+(const Fixed &other) const{

    Fixed result;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const{

    Fixed result;
    result.setRawBits(this->_value - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const{

    Fixed result;
    // 1. Casting to long long to prevent overflow
    // 2. Multiplying raw values
    // 3. We shift Right by 8 (divide by 256) to fix the scale
    result.setRawBits((long long)this->_value * other.getRawBits() >> _fraction);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const{

    Fixed result;
    // 1. We shift Left by 8 (multiply by 256) FIRST to keep precision
    // 2. Dividing by denominator
    result.setRawBits(((long long)this->_value << _fraction) / other.getRawBits());
    return result;
}


Fixed& Fixed::operator++(){

    this->_value++;
    return (*this);
}

Fixed  Fixed::operator++(int){

    Fixed temp = *this;
    this->_value++;
    return (temp);
}

Fixed& Fixed::operator--(){

    this->_value--;
    return (*this);
}

Fixed  Fixed::operator--(int){

    Fixed temp = *this;
    this->_value--;
    return (temp);
}


// ================================================================
//                        OTHER MATH MEMBERS
// ================================================================

Fixed& Fixed::min(Fixed &a, Fixed &b){

    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b){

    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b){

    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){

    if (a > b)
        return (a);
    return (b);
}



// ================================================================
//                      OTHER FIXED FUNCTIONS
// ================================================================

std::ostream& operator<<( std::ostream &os, const Fixed &fixed){

    // std::cout << INSERT_OP_MSG << FIXED << "\n";

    os << fixed.toFloat();
    return (os);
}
