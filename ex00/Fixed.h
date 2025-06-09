#ifndef FIXED_H
#define FIXED_H

// Class in Orthodox Canonical Form that represents a fixed-point number
class Fixed {
private:
    int fixedPointNumber;
    static const int fractionalBits = 8;

public:
    Fixed(); // Default constructor
    Fixed(const Fixed& other);  // Copy constructor - creates a new fixed object as a copy of an existing fixed object
    Fixed& operator=(const Fixed& other); // assignment operator overload - overloads the assignment operator to allow assigning one fixed object to another
    ~Fixed();// Destructor 

    int getRawBits(void) const; // Getter
    void setRawBits(int const raw); // Setter
};

#endif
