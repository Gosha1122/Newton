#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>

class Fraction
{
public:
    Fraction();
    Fraction(long long a, long long b);
    Fraction(const Fraction& f);
    void operator=(const Fraction& f);


    
    
    long double getDecimalValue();

    Fraction operator+(const Fraction& f1);
    Fraction operator-(const Fraction& f1);
    Fraction operator-() const;
    void operator+=(const Fraction& f1);
    void operator-=(const Fraction& f1);
    Fraction operator*(const Fraction& f1);
    Fraction operator/(const Fraction& f1);
    void operator*=(const Fraction& f1);
    void operator/=(const Fraction& f1);
    
    long long getUp() const;
    void setUp(long long newUp);
    
    long long getDown() const;
    void setDown(long long newDown);

private:
    long long up = 0;
    long long down = 1;

    void shortValue();
};

std::ostream &operator<<(std::ostream &out, const Fraction& a);
std::istream &operator>>(std::istream &in, Fraction& a);


#endif // FRACTION_H
