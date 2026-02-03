#include "fraction.h"
#include <numeric>


Fraction::Fraction() {
    shortValue();
}

Fraction::Fraction(long long a, unsigned long long b):up(a), down(b){
    shortValue();
}

Fraction::Fraction(const Fraction &f)
{
    up = f.getUp();
    down = f.getDown();
    shortValue();
}

void Fraction::operator=(const Fraction &f)
{
    up = f.getUp();
    down = f.getDown();
    shortValue();
}

long double Fraction::getDecimalValue()
{
    return static_cast<double>(up) / down;
}

Fraction Fraction::operator+(const Fraction &f1)
{
    return Fraction(up * f1.getDown() + down * f1.getUp(), down * f1.getDown());
}

Fraction Fraction::operator-(const Fraction &f1)
{
    return Fraction(up * f1.getDown() - down * f1.getUp(), down * f1.getDown());
}

Fraction Fraction::operator-() const{
    return Fraction(-up, down);
}

void Fraction::operator+=(const Fraction &f1)
{
    up *= f1.getDown();
    up += down * f1.getUp();
    down *= f1.getDown();
    shortValue();
}

void Fraction::operator-=(const Fraction &f1)
{
    up *= f1.getDown();
    up -= down * f1.getUp();
    down *= f1.getDown();
    shortValue();
}

Fraction Fraction::operator*(const Fraction &f1)
{
    return Fraction(up * f1.getUp(), down * f1.getDown());
}

Fraction Fraction::operator/(const Fraction &f1)
{
    return Fraction(up * f1.getDown(), down * f1.getUp());
}

void Fraction::operator*=(const Fraction &f1)
{
    up *= f1.getUp();
    down *= f1.getDown();
    shortValue();
}

void Fraction::operator/=(const Fraction &f1)
{
    up *= f1.getDown();
    down *= f1.getUp();
    shortValue();
}

std::ostream &operator<<(std::ostream &out, const Fraction& a)
{
    return out << a.getUp() << " / " << a.getDown();
}

std::istream &operator>>(std::istream &in, Fraction& a)
{
    long long up, down;
    in >> up >> down;
    a.setUp(up);
    a.setDown(down);
}

long long Fraction::getUp() const
{
    return up;
}

void Fraction::setUp(long long newUp)
{
    up = newUp;
}

unsigned long long Fraction::getDown() const
{
    return down;
}

void Fraction::setDown(unsigned long long newDown)
{
    down = newDown;
}

void Fraction::shortValue()
{
    unsigned long long d = std::gcd(up, down);
    up /= d;
    down /= d;
}
