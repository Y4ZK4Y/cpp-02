#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed(): fixedPointNumber(0) {
    std::cout << "Default constructor." << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor." << std::endl;
    fixedPointNumber = n << fractionalBits; // shift the int to the left by fractionalbits
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor." << std::endl;
    fixedPointNumber = roundf(f * (1 << fractionalBits)); // convert float to fixedpoint
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointNumber) / (1 << fractionalBits); // convert fixedpoint to float
}

int Fixed::toInt(void) const {
    return fixedPointNumber >> fractionalBits; //shift fixedpoint to right by fractionalbits
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor." << std::endl;
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
    std::cout << "getter." << std::endl;
    return fixedPointNumber;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setter." << std::endl;
    fixedPointNumber = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

// Comparison ops
bool Fixed::operator>(const Fixed& other) const {
    return fixedPointNumber > other.fixedPointNumber;
}

bool Fixed::operator<(const Fixed& other) const {
    return fixedPointNumber < other.fixedPointNumber;
}

bool Fixed::operator>=(const Fixed& other) const {
    return fixedPointNumber >= other.fixedPointNumber;
}

bool Fixed::operator<=(const Fixed& other) const {
    return fixedPointNumber <= other.fixedPointNumber;
}

bool Fixed::operator==(const Fixed& other) const {
    return fixedPointNumber == other.fixedPointNumber;
}

bool Fixed::operator!=(const Fixed& other) const {
    return fixedPointNumber != other.fixedPointNumber;
}

// Arithmetic ops
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(toFloat() / other.toFloat());
}

// Increment/decrement
Fixed& Fixed::operator++() {
    fixedPointNumber++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp (*this);
    ++(*this);
    return temp; // return by value
}


Fixed& Fixed::operator--() {
    fixedPointNumber--;
    return *this;
}


Fixed Fixed::operator--(int) {
    Fixed temp (*this);
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a > b) ? b: a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a > b)? b: a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a: b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b)? a: b;
}
