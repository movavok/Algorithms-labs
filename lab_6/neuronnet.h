#ifndef NEURONNET_H
#define NEURONNET_H

#include "perceptron.h"

class NeuronNet {
public:
    NeuronNet(int inputsAmount);

    void modelXOR();

    // double sigmoid(double x) {
    //     return 1.0 / (1.0 + exp(-x));
    // }

    // // прогнозування часових рядів
    // double predictTimeSeries(const vector<double>& input) {
    //     double sum = 0;
    //     for(size_t i=0;i<w.size();i++)
    //         sum += input[i]*w[i];
    //     return sigmoid(sum)*10; // масштабування
    // }

private:
    vector<double> m_weights;
    double m_learningRate;
    double m_threshold;

    // XOR members/helper
    Perceptron pNAND;
    Perceptron pOR;
    Perceptron pAND;
    void initXOR();
};

#endif // NEURONNET_H
