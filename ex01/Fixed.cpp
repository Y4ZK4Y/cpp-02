#include "Fixed.h"
#include <iostream>

Fixed::Fixed(): fixedPointNumber(0) {
    std::cout << "Default constructor." << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called." << std::endl;
    fixedPointNumber = n << fractionalBits; // shift the int to the left by fractionalbits
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called." << std::endl;
    fixedPointNumber = roundf(f * (1 << fractionalBits)); // convert float to fixedpoint
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointNumber) / (1 << fractionalBits); // convert fixedpoint to float
}

int Fixed::toInt(void) const {
    return fixedPointNumber >> fractionalBits; //shidt fixedpoint to right by fractionalbits
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor in the house." << std::endl;
    *this = other; // ? 
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
