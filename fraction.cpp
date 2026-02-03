#include "fraction.h"
#include <QtMath>


Fraction::Fraction() {}

long double Fraction::getDecimalValue()
{
    return static_cast<double>(up) / down;
}

void Fraction::shortValue()
{

}
