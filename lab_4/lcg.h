#ifndef LCG_H
#define LCG_H

#include "randomgenerator.h"

class LCG : public RandomGenerator {
private:
    long long m_multiplier;
    long long m_modulus;
    long long m_increment;

public:
    LCG(long long seed, long long multiplier, long long modulus, long long increment = 0)
        : RandomGenerator(seed), m_multiplier(multiplier), m_modulus(modulus), m_increment(increment) {}

    long long next() override {
        m_seed = (m_multiplier * m_seed + m_increment) % m_modulus;
        return m_seed;
    }

    double nextDouble() override {
        return static_cast<double>(next()) / static_cast<double>(m_modulus);
    }
};

#endif // LCG_H
