#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <iostream>

using namespace std;

class Perceptron {
private:
    vector<double> m_weights;
    double m_threshold;

public:
    Perceptron(int inputsAmount);

    void setWeights(const vector<double>& weights) { m_weights = weights; }
    void setThreshold(double threshold) { m_threshold = threshold; }

    void modelAND();
    void modelOR();
    void modelNOT();

    int predict(const vector<int>& inputs);

private:
    void test(const vector<vector<int>>& inputs, const vector<int>& targets);
};

#endif // PERCEPTRON_H
