#include "perceptron.h"

Perceptron::Perceptron(int inputsAmount)
    : m_threshold(0.5)
{
    m_weights.resize(inputsAmount, 1.0);
}

int Perceptron::predict(const vector<int>& inputs) {
    double sum = 0.0;
    for (size_t index = 0; index < inputs.size(); index++)
        sum += inputs[index] * m_weights[index];
    return sum >= m_threshold ? 1 : 0;
}

// void Perceptron::train(const vector<vector<int>>& inputs, const vector<int>& targets, int epochs) {
//     for (int epoch = 0; epoch < epochs; epoch++)
//         for (size_t inputIdx = 0; inputIdx < inputs.size(); inputIdx++) {
//             int resultPred = predict(inputs[inputIdx]);
//             int error = targets[inputIdx] - resultPred;
//             for (size_t weightIdx = 0; weightIdx < m_weights.size(); weightIdx++)
//                 m_weights[weightIdx] += m_learningRate * error * inputs[inputIdx][weightIdx];
//         }
// }

void Perceptron::test(const vector<vector<int>>& inputs, const vector<int>& targets) {
    for (size_t index = 0; index < inputs.size(); index++) {
        int output = predict(inputs[index]);
        cout << "Вхід: ";
        for (int value : inputs[index]) cout << value << " ";
        cout << "=> Вихід: " << output << " (Очікуваний: " << targets[index] << ")";

        if (output == targets[index])
            cout << " ВІРНО";
        else
            cout << " НЕПРАВИЛЬНО";

        cout << endl;
    }
    cout << endl;
}

void Perceptron::modelAND() {
    m_weights = {1, 1};
    m_threshold = 1.5;

    cout << "Моделювання логічної функції І:" << endl;
    test({{0,0}, {0,1}, {1,0}, {1,1}}, {0,0,0,1});
}

void Perceptron::modelOR() {
    m_weights = {1, 1};
    m_threshold = 0.5;

    cout << "Моделювання логічної функції АБО:" << endl;
    test({{0,0}, {0,1}, {1,0}, {1,1}}, {0,1,1,1});
}

void Perceptron::modelNOT() {
    m_weights = {-1};
    m_threshold = -0.5;

    cout << "Моделювання логічної функції НЕ:" << endl;
    test({{0}, {1}}, {1,0});
}
