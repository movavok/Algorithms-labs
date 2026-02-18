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
        if (seed <= 0 || seed >= m_modulus || gcd(seed, m_modulus) != 1) {
            cerr << "Seed має бути в {0, n} і взаємно простим з n. Використано seed = 3" << endl;
            m_seed = 3;
        } else
            m_seed = seed;

        m_seed = (m_seed * m_seed) % m_modulus;
    }

    long long next() override {
        m_seed = (m_seed * m_seed) % m_modulus;
        return m_seed % 2;
    }

    unsigned nextByte(int bits = 8) {
        unsigned byte = 0;
        for (int count = 0; count < bits; ++count)
            byte = (byte << 1) | static_cast<unsigned>(next());

        return byte;
    }

    double nextDouble() override {
        return static_cast<double>(nextByte(32)) / 4294967295.0;
    }
};

#endif // BBS_H
