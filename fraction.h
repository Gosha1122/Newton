#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <QString>

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
    Fraction operator-() const;
    void operator+=(const Fraction& f1);
    void operator-=(const Fraction& f1);
    Fraction operator*(const Fraction& f1);
    Fraction operator/(const Fraction& f1);
    void operator*=(const Fraction& f1);
    void operator/=(const Fraction& f1);
    bool operator==(const Fraction& f1);
    
    long long getUp() const;
    void setUp(long long newUp);
    
    unsigned long long getDown() const;
    void setDown(unsigned long long newDown);

    QString getText();

private:
    long long up = 0;
    unsigned long long down = 1;

    void shortValue();
};

std::ostream &operator<<(std::ostream &out, const Fraction& a);
std::istream &operator>>(std::istream &in, Fraction& a);


#endif // FRACTION_H
