#include "monomial.h"

Monomial::Monomial() {

}

unsigned int Monomial::getPower() const
{
    return power;
}

void Monomial::setPower(unsigned int newPower)
{
    power = newPower;
}
