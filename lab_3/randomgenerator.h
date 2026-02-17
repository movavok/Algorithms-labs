#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

class RandomGenerator {
protected:
    long long m_seed;

public:
    RandomGenerator(long long seed) : m_seed(seed) {}
    virtual long long next() = 0;
    virtual ~RandomGenerator() {}
};

#endif // RANDOMGENERATOR_H
