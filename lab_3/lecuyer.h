#ifndef LECUYER_H
#define LECUYER_H

#include "lcg.h"

class LEcuyer : public RandomGenerator {
private:
    static const long long MULT_1 = 40014;
    static const long long MOD_1 = 2147483563;

    static const long long MULT_2 = 40692;
    static const long long MOD_2 = 2147483399;

    LCG m_gen1;
    LCG m_gen2;

public:
    LEcuyer(long long seed1, long long seed2)
        : RandomGenerator(seed1),
        m_gen1(seed1, MULT_1, MOD_1),
        m_gen2(seed2, MULT_2, MOD_2) {}

    long long next() override {
        long long firstNum = m_gen1.next();
        long long secondNum = m_gen2.next();

        long long result = firstNum - secondNum;
        if (result < 0) result += MOD_1;

        return result;
    }
};

#endif // LECUYER_H
