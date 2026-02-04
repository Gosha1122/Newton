#include "complex.h"

Complex::Complex() {}

Complex::Complex(const Fraction &fRe, const Fraction &fIm)
{
    re = fRe;
    im = fIm;
}

Complex::Complex(const Fraction &re)
{
    this->re = re;
    im = Fraction(0, 1);
}

Complex::Complex(const Complex &c)
{
    re = c.getRe();
    im = c.getIm();
}

void Complex::operator=(const Complex &c)
{
    re = c.getRe();
    im = c.getIm();
}

Complex Complex::getConjugate()
{
    return Complex(re, -im);
}

long double Complex::getNormal()
{
    return sqrt((re * re).getDecimalValue() + (im * im).getDecimalValue());
}

Complex Complex::operator+(const Complex &f1)
{
    return Complex(re + f1.getRe(), im + f1.getIm());
}

Complex Complex::operator-(const Complex &f1)
{
    return Complex(re - f1.getRe(), im - f1.getIm());
}

Complex Complex::operator-() const {
    return Complex(-re, -im);
}

void Complex::operator+=(const Complex &f1)
{
    re += f1.getRe();
    im += f1.getIm();
}

void Complex::operator-=(const Complex &f1)
{
    re -= f1.getRe();
    im -= f1.getIm();
}

Complex Complex::operator*(const Complex &f1)
{
    return Complex(re * f1.getRe() - im * f1.getIm(), re * f1.getIm() + im * f1.getRe());
}

Complex Complex::operator*(const Fraction& f1){
    return Complex(re * f1, im * f1);
}

Complex Complex::operator/(const Complex &f1)
{
    return Complex((re * f1.getRe() + im * f1.getIm()) / (f1.getRe() * f1.getRe() + f1.getIm() * f1.getIm()), (im * f1.getRe() - re * f1.getIm()) / (f1.getRe() * f1.getRe() + f1.getIm() * f1.getIm()));
}

Complex Complex::operator/(const Fraction& f1){
    return Complex(re / f1, im / f1);
}

void Complex::operator*=(const Complex &f1)
{
    Fraction n_re = re * f1.getRe() - im * f1.getIm();
    Fraction n_im = re * f1.getIm() + im * f1.getRe();
    re = n_re;
    im = n_im;
}

void Complex::operator*=(const Fraction& f1){
    re *= f1;
    im *= f1;
}

void Complex::operator/=(const Complex &f1)
{
    Fraction n_re = (re * f1.getRe() + im * f1.getIm()) / (f1.getRe() * f1.getRe() + f1.getIm() * f1.getIm());
    Fraction n_im = (im * f1.getRe() - re * f1.getIm()) / (f1.getRe() * f1.getRe() + f1.getIm() * f1.getIm());
    re = n_re;
    im = n_im;
}

bool Complex::operator==(const Complex &c1)
{
    return (re == c1.getRe() && im == c1.getIm());
}

void Complex::operator/=(const Fraction& f1){
    re /= f1;
    im /= f1;
}

std::ostream &operator<<(std::ostream &out, const Complex& c)
{
    if(c.getIm().getUp() == 0) return out << c.getRe();
    out << '(' << c.getRe();
    return out << " + i * " << c.getIm() << ')';
}

std::istream &operator>>(std::istream &in, Complex& c)
{
    Fraction nRe, nIm;
    in >> nRe >> nIm;
    c.setRe(nRe);
    c.setIm(nIm);
    return in;
}

Fraction Complex::getRe() const
{
    return re;
}

void Complex::setRe(const Fraction &newRe)
{
    re = newRe;
}

Fraction Complex::getIm() const
{
    return im;
}

void Complex::setIm(const Fraction &newIm)
{
    im = newIm;
}
