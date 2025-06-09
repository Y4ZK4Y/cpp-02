#ifndef FIXED_H
#define FIXED_H

#include <iostream>

// Extending the fixed class functionalities

class Fixed {
private:
    int fixedPointNumber;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& object);

#endif
