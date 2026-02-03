#ifndef MONOMIAL_H
#define MONOMIAL_H
#include "complex.h"
#include <iostream>

class Monomial
{
public:
    Monomial();
    Monomial(int power, Complex k);
    Monomial(const Monomial &m);
    void operator=(Monomial m);

    int getPower() const;
    void setPower(int newPower);
    Complex getK() const;
    void setK(const Complex& newK);
    Monomial operator+(Monomial& m1);
    Monomial operator-(Monomial& m1);
    void operator+=(Monomial& m1);
    void operator-=(Monomial &m1);
    Monomial operator*(Monomial& m1);
    Monomial operator*(Complex& c1);
    Monomial operator/(Monomial& m1);
    Monomial operator/(Complex& m1);
    void operator*=(Monomial& m1);
    void operator*=(Complex &c1);
    void operator/=(Monomial& m1);
    void operator/=(Complex &c1);

private:
    int power;
    Complex k;
};

std::ostream &operator<<(std::ostream& out, const Monomial &m);
std::ostream &operator<<(std::ostream& out, const Monomial &&m);


#endif // MONOMIAL_H
