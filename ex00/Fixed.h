#ifndef FIXED_H
#define FIXED_H


// Create a class in Orthodox Canonical Form that represents a fixed-point number
class Fixed {
private:
    int fixedPointNumber;
    static const int fractionalBits = 8;

public:
    Fixed(); // default constructor - initialization - ??
    Fixed(const Fixed& other);  // copy constructor - creates a new fixed object as a copy of an existing fixed object
    Fixed& operator=(const Fixed& other); // assignment operator overload - overloads the assignment operator to allow assigning one fixed object to another
    ~Fixed();// destructor 

    int getRawBits(void) const; // getter
    void setRawBits(int const raw); // setter
};

#endif
