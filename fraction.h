#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
    Fraction();
    Fraction(long long a, unsigned long long b):up(a), down(b){}
    long double getDecimalValue();


    Fraction operator+(const Fraction& f1);

private:
    long long up = 0;
    unsigned long long down = 0;

    void shortValue();
};

#endif // FRACTION_H
