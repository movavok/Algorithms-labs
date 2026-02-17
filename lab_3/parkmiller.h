#ifndef PARKMILLER_H
#define PARKMILLER_H

#include "lcg.h"

class ParkMiller : public RandomGenerator {
private:
    static const long long MULT = 16807;
    static const long long MOD = 2147483647;

    LCG m_lcg;

public:
    ParkMiller(long long seed)
        : RandomGenerator(seed), m_lcg(seed, MULT, MOD) {}

    long long next() override { return m_lcg.next(); }
};

#endif // PARKMILLER_H
