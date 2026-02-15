#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c(4.2f);
    Fixed d(9);

    std::cout << a << std::endl;

    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << a << std::endl;
    a = a + 7.77f;
    std::cout << a << std::endl;

    std::cout << (a - 2.255f) << std::endl;

    std::cout << (a * 0.5f) << std::endl;

    std::cout << (a / 2) << std::endl;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << (c > d) << std::endl;
    std::cout << (c < d) << std::endl;
    std::cout << (c >= d) << std::endl;
    std::cout << (c <= d) << std::endl;
    std::cout << (c == d) << std::endl;
    std::cout << (c != d) << std::endl;

    std::cout << Fixed::max( a, d ) << std::endl;
    std::cout << Fixed::max( b, c ) << std::endl;
    std::cout << Fixed::min( a, d ) << std::endl;
    std::cout << Fixed::min( b, c ) << std::endl;

    return 0;
}

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;

//     std::cout << b << std::endl;

//     std::cout << Fixed::max( a, b ) << std::endl;

//     return 0;
// }
