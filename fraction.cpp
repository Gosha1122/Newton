#include "fraction.h"
#include <numeric>


Fraction::Fraction() {

}

Fraction::Fraction(long long a, unsigned long long b) : up(a), down(b){
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
    if (f1.getUp() < 0) {
        return Fraction(up * -f1.getDown(), down * (-f1.getUp()));
    }
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
    if (f1.getUp() < 0) {
        up *= (-f1.getDown());
        down *= (-f1.getUp());
    } else {
        up *= f1.getDown();
        down *= f1.getUp();
    }
    shortValue();
}

bool Fraction::operator==(const Fraction &f1)
{
    return (up == f1.getUp() && down == f1.getDown());
}

std::ostream &operator<<(std::ostream &out, const Fraction& a)
{
    if(a.getDown() == 1) return out << a.getUp();
    if(a.getUp() == 0) return out << 0;
    return out << a.getUp() << " / " << a.getDown();
}

std::istream &operator>>(std::istream &in, Fraction& a)
{
    long long up, down;
    in >> up >> down;
    a.setUp(up);
    a.setDown(down);
    return in;
}

long long Fraction::getUp() const
{
    return up;
}

void Fraction::setUp(long long newUp)
{
    up = newUp;
    shortValue();
}

unsigned long long Fraction::getDown() const
{
    return down;
}

void Fraction::setDown(unsigned long long newDown)
{
    down = newDown;
    shortValue();
}

QString Fraction::getText()
{
    if(down == 1) return QString::number(up);
    return QString::number(up) + "/" + QString::number(down);
}

void Fraction::shortValue()
{
    long long d = std::gcd(std::abs(up), down);
    up /= d;
    down /= d;
}
