#include "monomial.h"

Monomial::Monomial() {

}

int Monomial::getPower() const
{
    return power;
}

void Monomial::setPower(unsigned int newPower)
{
    power = newPower;
}
Fraction Monomial::getK() const
{
    return k;
}

void Monomial::setK(const Fraction &newK)
{
    k = newK;
}
Monomial Monomial::operator+(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Ай ай ай разные степени!!!";
        return Monomial();
    }
    return Monomial(m1.getPower(), m1.getK() + k);
}
Monomial Monomial::operator-(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Ай ай ай разные степени!!!";
        return Monomial();
    }
    return Monomial(m1.getPower(), k - m1.getK());
}
void Monomial::operator+=(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Ай ай ай разные степени!!!";
        return;
    }
    k += m1.getK();
}
void Monomial::operator-=(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Ай ай ай разные степени!!!";
        return;
    }
    k -= m1.getK();
}

Monomial Monomial::operator*(Monomial &m1)
{
    return {m1.getPower() + power, m1.getK() * k};
}
Monomial Monomial::operator/(Monomial &m1)
{
    return {power - m1.getPower(), k / m1.getK()};
}
void Monomial::operator*=(Monomial &m1)
{
    power += m1.power;
    k *= m1.getK();
}
void Monomial::operator/=(Monomial &m1)
{
    power -= m1.power;
    k /= m1.getK();
}


std::ostream &operator<<(std::ostream& out, Monomial &m) {
    return out << m.getK() << "x ^ " << m.getPower();
}
std::istream &operator>>(std::istream& in, Monomial &m) {
    int newK, newPower;
    in >> newK >> newPower;
    return in;
}


