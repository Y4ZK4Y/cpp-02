#include "Fixed.h"
#include <iostream>

Fixed::Fixed(): fixedPointNumber(0) {
    std::cout << "Default constructor." << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor in the house." << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator." << std::endl;
    if (this != &other) {
        fixedPointNumber = other.fixedPointNumber;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructorrrr." << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getter called." << std::endl;
    return fixedPointNumber;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setter fucntions." << std::endl;
    fixedPointNumber = raw;
}
