#include "monomial.h"

Monomial::Monomial() {

}

Monomial::Monomial(int power, Fraction k) : power(power), k(k)
{

}

int Monomial::getPower() const
{
    return power;
}

void Monomial::setPower(int newPower)
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
    return Monomial(m1.getPower() + power, m1.getK() * k);
}
Monomial Monomial::operator/(Monomial &m1)
{
    return Monomial(power - m1.getPower(), k / m1.getK());
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
    int newPower;
    Fraction newK;
    in >> newK >> newPower;
    m.setK(newK);
    m.setPower(newPower);
    return in;
}


