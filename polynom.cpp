#include "polynom.h"

Polynom::Polynom() {}
Polynom::Polynom(QList<Monomial> monomials) : monomials(monomials)
{
    for (Monomial &m : monomials) {
        power = std::max(m.getPower(), power);
    }
}
Polynom::Polynom(QList<Monomial> monomials, int power) : monomials(monomials), power(power)
{

}
Polynom::Polynom(Polynom &a)
{
    monomials = a.getMonomials();
    power = a.getPower();
}

void Polynom::operator=(Polynom a)
{
    monomials = a.getMonomials();
    power = a.getPower();
}

Polynom Polynom::operator+(Polynom &m1)
{
    QMap<int, Complex> monomial_map;
    for (Monomial& m : monomials) {
        monomial_map[m.getPower()] += m.getK();
    }
    for (Monomial& m : m1.getMonomials()) {
        monomial_map[m.getPower()] += m.getK();
    }
    QList<Monomial> monomials;
    for (auto iterator = monomial_map.cbegin(); iterator != monomial_map.cend(); iterator++) {
        monomials.append(Monomial(iterator.key(), iterator.value()));
    }
    return Polynom(monomials);
}

Polynom Polynom::operator-(Polynom &m1)
{
    QMap<int, Complex> monomial_map;
    for (Monomial& m : monomials) {
        monomial_map[m.getPower()] += m.getK();
    }
    for (Monomial& m : m1.getMonomials()) {
        monomial_map[m.getPower()] -= m.getK();
    }
    QList<Monomial> monomials;
    for (auto iterator = monomial_map.cbegin(); iterator != monomial_map.cend(); iterator++) {
        monomials.append(Monomial(iterator.key(), iterator.value()));
    }
    return Polynom(monomials);
}

void Polynom::operator+=(Polynom &m1)
{
    QMap<int, Complex> monomial_map;
    for (Monomial& m : monomials) {
        monomial_map[m.getPower()] += m.getK();
    }
    for (Monomial& m : m1.getMonomials()) {
        monomial_map[m.getPower()] += m.getK();
    }
    QList<Monomial> monomials;
    for (auto iterator = monomial_map.cbegin(); iterator != monomial_map.cend(); iterator++) {
        monomials.append(Monomial(iterator.key(), iterator.value()));
    }
    *this = Polynom(monomials);
}

void Polynom::operator-=(Polynom &m1)
{
    QMap<int, Complex> monomial_map;
    for (Monomial& m : monomials) {
        monomial_map[m.getPower()] += m.getK();
    }
    for (Monomial& m : m1.getMonomials()) {
        monomial_map[m.getPower()] -= m.getK();
    }
    QList<Monomial> monomials;
    for (auto iterator = monomial_map.cbegin(); iterator != monomial_map.cend(); iterator++) {
        monomials.append(Monomial(iterator.key(), iterator.value()));
    }

}

Polynom Polynom::operator*(Polynom &m1)
{
    QMap<int, Complex> monomial_map;
    for (Monomial& m2 : monomials) {
        for (Monomial& m3 : m1.getMonomials()) {
            monomial_map[m2.getPower() + m3.getPower()] += m2.getK() * m3.getK();
        }
    }

    QList<Monomial> monomials;
    for (auto iterator = monomial_map.cbegin(); iterator != monomial_map.cend(); iterator++) {
        monomials.append(Monomial(iterator.key(), iterator.value()));
    }
    return Polynom(monomials);
}

void Polynom::operator*=(Polynom &m1)
{
    QMap<int, Complex> monomial_map;
    for (Monomial& m2 : monomials) {
        for (Monomial& m3 : m1.getMonomials()) {
            monomial_map[m2.getPower() + m3.getPower()] += m2.getK() * m3.getK();
        }
    }

    QList<Monomial> monomials;
    for (auto iterator = monomial_map.cbegin(); iterator != monomial_map.cend(); iterator++) {
        monomials.append(Monomial(iterator.key(), iterator.value()));
    }
    *this = Polynom(monomials);
}


QList<Monomial> Polynom::getMonomials() const
{
    return monomials;
}

void Polynom::setMonomials(const QList<Monomial> &newMonomials)
{
    monomials = newMonomials;
}

int Polynom::getPower() const
{
    return power;
}

void Polynom::setPower(int newPower)
{
    power = newPower;
}

std::ostream &operator<<(std::ostream& out, Polynom& P) {
    for (int ind = 0; ind < P.getMonomials().size() - 1; ind++) {
        out << P.getMonomials().at(ind) << " + ";
    }
    out << P.getMonomials().at(P.getMonomials().size() - 1);
    return out;
}


std::ostream &operator<<(std::ostream& out, Polynom&& P) {
    for (int ind = 0; ind < P.getMonomials().size() - 1; ind++) {
        out << P.getMonomials().at(ind) << " + ";
    }
    out << P.getMonomials().at(P.getMonomials().size() - 1);
    return out;
}

