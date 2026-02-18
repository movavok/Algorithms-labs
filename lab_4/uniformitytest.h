#ifndef UNIFORMITYTEST_H
#define UNIFORMITYTEST_H

#include <vector>

#include "randomgenerator.h"

class UniformityTest {
private:
    int m_numbers;
    int m_intervals;

public:
    UniformityTest(int numbers, int intervals) : m_numbers(numbers), m_intervals(intervals) {}

    double runTest(RandomGenerator& generator) {
        vector<int> bucket(m_intervals, 0);

        for (int count = 0; count < m_numbers; count++) {
            double random = generator.nextDouble();
            int index = (int)(random * m_intervals);
            bucket[index]++;
        }

        double expected = (double)m_numbers / m_intervals;
        double chiSquared = 0.0;

        for (int index = 0; index < m_intervals; index++)
            chiSquared += (bucket[index] - expected) * (bucket[index] - expected) / expected;

        return chiSquared;
    }
};

#endif // UNIFORMITYTEST_H
