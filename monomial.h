#ifndef MONOMIAL_H
#define MONOMIAL_H
#include <fraction.h>

class Monomial
{
public:
    Monomial();
    Monomial(unsigned int power, Fraction k);
    unsigned int getPower() const;
    void setPower(unsigned int newPower);
    Monomial operator+(Monomial& m1);
    Monomial operator-(Monomial& m1);
    void operator+=(Monomial& m1);
    void operator-=(Monomial &m1);


private:
    unsigned int power;
    Fraction k;
};

#endif // MONOMIAL_H
