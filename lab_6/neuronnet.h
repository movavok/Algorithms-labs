#ifndef NEURONNET_H
#define NEURONNET_H

#include <ctime>

#include "perceptron.h"

class NeuronNet {
public:
    NeuronNet(int inputsAmount);

    void modelXOR();

    void trainAndTestTS(vector<double>& series, int epochs = 50000);


private:
    vector<double> m_weights;
    double m_learningRate;

    // XOR members/helper
    Perceptron pNAND;
    Perceptron pOR;
    Perceptron pAND;
    void initXOR();

    // Time series helper
    double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)) * 10; }
    double predictTimeSeries(const vector<double>& input);
    void trainTimeSeries(const vector<double>& series, int epochs, size_t trainCount = 13);
    void testTimeSeries(const vector<double>& series, size_t trainCount = 13);
};

#endif // NEURONNET_H
