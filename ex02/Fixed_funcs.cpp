#include "Fixed.hpp"

std::ostream& operator<<( std::ostream &os, const Fixed &fixed){
    // std::cout << INSERT_OP_MSG << FIXED << "\n";

    os << fixed.toFloat();
    return (os);
}
