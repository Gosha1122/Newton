#ifndef POLYNOM_H
#define POLYNOM_H
#include <QList>
#include <QMap>
#include "monomial.h"
class Polynom
{
public:
    Polynom();
    Polynom(QList<Monomial> monomials);
    Polynom(QList<Monomial> monomials, int power);
    Polynom(Polynom &a);
    void operator=(Polynom a);


    Polynom operator+(Polynom& m1);
    Polynom operator-(Polynom& m1);
    void operator+=(Polynom& m1);
    void operator+=(Polynom &&m1);
    void operator-=(Polynom& m1);
    Polynom operator*(Polynom &m1);
    Polynom operator*(Complex& c1);
    Polynom operator/(Complex& c1);
    void operator*=(Polynom& m1);
    void operator*=(Polynom &&m1);
    void operator*=(Complex &m1);
    void operator/=(Complex &c1);

    QList<Monomial> getMonomials() const;
    void setMonomials(const QList<Monomial> &newMonomials);

    int getPower() const;
    void setPower(int newPower);

private:
    QList<Monomial> monomials;
    int power;
};

std::ostream &operator<<(std::ostream& out, Polynom& P);
std::ostream &operator<<(std::ostream& out, Polynom&& P);

#endif // POLYNOM_H
