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
    void setPower(int newPower);
    Fraction getK() const;
    void setK(const Fraction& newK);
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

std::ostream &operator<<(std::ostream& out, Monomial &m);


#endif // MONOMIAL_H
