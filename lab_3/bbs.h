#ifndef BBS_H
#define BBS_H

#include <numeric>

#include "randomgenerator.h"

class BBS : public RandomGenerator {
private:
    long long m_modulus;

public:
    BBS(long long seed, long long firstPrime, long long secondPrime)
        : RandomGenerator(seed)
    {
        m_modulus = firstPrime * secondPrime;
        if (seed <= 0 || seed >= m_modulus || std::gcd(seed, m_modulus) != 1) {
            std::cerr << "Seed має бути в {0, n} і взаємно простим з n. Використано seed = 3" << std::endl;
            m_seed = 3;
        }

        m_seed = (m_seed * m_seed) % m_modulus;
    }

    long long next() override {
        m_seed = (m_seed * m_seed) % m_modulus;
        return m_seed % 2;
    }

    int nextByte(int bits = 8) {
        int byte = 0;
        for (int count = 0; count < bits; ++count)
            byte = (byte << 1) | next();

        return byte;
    }
};

#endif // BBS_H
