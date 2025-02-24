#ifndef FIXED_H
#define FIXED_H

#include <iostream>

// Extending the fixed class functionalities - operators

class Fixed {
private:
    int fixedPointNumber;
    static const int fractionalBits = 8;

public:
    Fixed(); // default constructor - initialization - ??
    Fixed(const int n); // int constructor
    Fixed(const float f); // float constructor
    Fixed(const Fixed& other);  // copy constructor - creates a new fixed object as a copy of an existing fixed object
    Fixed& operator=(const Fixed& other); // assignment operator overload - overloads the assignment operator to allow assigning one fixed object to another
    ~Fixed();// destructor 

    int getRawBits(void) const; // getter
    void setRawBits(int const raw); // setter

    // add toFloat
    float toFloat(void) const;
    // add toInt
    int toInt(void) const;

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/decrement operators
    Fixed& operator++(); // pre increment
    Fixed operator++(int); // post increment
    Fixed& operator--(); //pre decrement
    Fixed operator--(int); // post decrement

    // min/max functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed); // ?
};

#endif
