#ifndef FIXED_H
#define FIXED_H

#include <iostream>

// Extending the fixed class functionalities

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

    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif
