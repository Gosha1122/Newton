#include "monomial.h"

Monomial::Monomial() {

}

Monomial::Monomial(int power, Complex k) : power(power), k(k)
{

}

Monomial::Monomial(const Monomial &a) {
    power = a.getPower();
    k = a.getK();
}

void Monomial::operator=(Monomial m)
{
    power = m.getPower();
    k = m.getK();
}

int Monomial::getPower() const
{
    return power;
}

void Monomial::setPower(int newPower)
{
    power = newPower;
}
Complex Monomial::getK() const
{
    return k;
}

void Monomial::setK(const Complex &newK)
{
    k = newK;
}
Monomial Monomial::operator+(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Impossible to get a sum of monomials with diffrent powers";
        return Monomial();
    }
    return Monomial(m1.getPower(), m1.getK() + k);
}
Monomial Monomial::operator-(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Impossible to get a sub of monomials with diffrent powers";
        return Monomial();
    }
    return Monomial(m1.getPower(), k - m1.getK());
}
void Monomial::operator+=(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Impossible to get a sum of monomials with diffrent powers";
        return;
    }
    k += m1.getK();
}
void Monomial::operator-=(Monomial &m1)
{
    if (m1.getPower() != power) {
        throw "Impossible to get a sub of monomials with diffrent powers";
        return;
    }
    k -= m1.getK();
}

Monomial Monomial::operator*(Monomial &m1)
{
    if (m1.k.getRe().getUp() == 0 && m1.k.getIm().getUp() == 0) {
        return Monomial();
    }
    if (k.getRe().getUp() == 0 && k.getIm().getUp() == 0) {
        return Monomial();
    }
    return Monomial(m1.getPower() + power, m1.getK() * k);
}
Monomial Monomial::operator*(Complex &c1)
{
    if (c1.getRe().getUp() == 0 && c1.getIm().getUp() == 0) {
        return Monomial();
    }
    if (k.getRe().getUp() == 0 && k.getIm().getUp() == 0) {
        return Monomial();
    }
    return Monomial(power, k * c1);
}
Monomial Monomial::operator/(Monomial &m1)
{
    return Monomial(power - m1.getPower(), k / m1.getK());
}
Monomial Monomial::operator/(Complex &c1)
{
    return Monomial(power, k / c1);
}
void Monomial::operator*=(Monomial &m1)
{
    power += m1.power;
    k *= m1.getK();
}
void Monomial::operator*=(const Complex &c1)
{
    k *= c1;
}

void Monomial::operator/=(Monomial &m1)
{
    power -= m1.power;
    k /= m1.getK();
}
void Monomial::operator/=(Complex &c1)
{
    k /= c1;
}

std::ostream &operator<<(std::ostream& out, const Monomial &m) {
    if (m.getPower() == 0) {
        return out << m.getK();
    }
    else if (m.getPower() == 1) {
        return out << m.getK() << " * x";
    }
    else {
        return out << m.getK() << " * x ^ " << m.getPower();
    }
}
std::ostream &operator<<(std::ostream& out, const Monomial &&m) {
    if (m.getPower() == 0) {
        return out << m.getK();
    }
    else if (m.getPower() == 1) {
        return out << m.getK() << " * x";
    }
    else {
        return out << m.getK() << " * x ^ " << m.getPower();
    }
}
std::istream &operator>>(std::istream& in, Monomial &m) {
    int newPower;
    Complex newK;
    in >> newK >> newPower;
    m.setK(newK);
    m.setPower(newPower);
    return in;
}


