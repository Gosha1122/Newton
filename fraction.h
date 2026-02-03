#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
public:
    Fraction();
    Fraction(long long a, unsigned long long b);
    Fraction(const Fraction& f);
    void operator=(const Fraction& f);
    
    
    long double getDecimalValue();

    Fraction operator+(const Fraction& f1);
    Fraction operator-(const Fraction& f1);
    void operator+=(const Fraction& f1);
    void operator-=(const Fraction& f1);
    Fraction operator*(const Fraction& f1);
    Fraction operator/(const Fraction& f1);
    void operator*=(const Fraction& f1);
    void operator/=(const Fraction& f1);
    std::ostream& operator<<(std::ostream& out);
    std::istream& operator>>(std::istream& in);
    
    long long getUp() const;
    void setUp(long long newUp);
    
    unsigned long long getDown() const;
    void setDown(unsigned long long newDown);
    
private:
    long long up = 0;
    unsigned long long down = 0;

    void shortValue();
};

#endif // FRACTION_H
