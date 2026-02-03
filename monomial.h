#ifndef MONOMIAL_H
#define MONOMIAL_H
#include <fraction.h>
#include <iostream>

class Monomial
{
public:
    Monomial();
    Monomial(int power, Fraction k);
    int getPower() const;
    void setPower(unsigned int newPower);
    Monomial operator+(Monomial& m1);
    Monomial operator-(Monomial& m1);
    void operator+=(Monomial& m1);
    void operator-=(Monomial &m1);
    Monomial operator*(Monomial& m1);
    Monomial operator/(Monomial& m1);
    void operator*=(Monomial& m1);
    void operator/=(Monomial& m1);

private:
    int power;
    Fraction k;
};

std::ostream &operator<<(ostream& out, Monomial &m);


#endif // MONOMIAL_H
