#ifndef COMPLEX_H
#define COMPLEX_H


#include "fraction.h"


class Complex
{
public:
    Complex();
    Complex(const Fraction& fRe, const Fraction& fIm);
    Complex(const Fraction& re);
    Complex(const Complex& c);
    void operator=(const Complex& c);


    Complex getConjugate();
    long double getNormal();


    Complex operator+(const Complex& f1);
    Complex operator-(const Complex& f1);
    void operator+=(const Complex& f1);
    void operator-=(const Complex& f1);
    Complex operator*(const Complex& f1);
    Complex operator*(const Fraction& f1);
    Complex operator/(const Complex& f1);
    Complex operator/(const Fraction& f1);
    void operator*=(const Complex& f1);
    void operator*=(const Fraction& f1);
    void operator/=(const Complex& f1);
    void operator/=(const Fraction& f1);

    Fraction getRe() const;
    void setRe(const Fraction &newRe);

    Fraction getIm() const;
    void setIm(const Fraction &newIm);

private:
    Fraction re = Fraction();
    Fraction im = Fraction();

};

std::ostream &operator<<(std::ostream &out, const Complex& c);
std::istream &operator>>(std::istream &in, Complex& c);



#endif // COMPLEX_H
