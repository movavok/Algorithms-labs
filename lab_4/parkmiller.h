#ifndef PARKMILLER_H
#define PARKMILLER_H

#include "lcg.h"

class ParkMiller : public LCG {
private:
    static const long long MULT = 16807;
    static const long long MOD = 2147483647;

public:
    ParkMiller(long long seed) : LCG(seed % (MOD - 1) + 1, MULT, MOD) {}
};

#endif // PARKMILLER_H
