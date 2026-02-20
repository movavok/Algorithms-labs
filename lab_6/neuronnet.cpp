#include "neuronnet.h"

NeuronNet::NeuronNet(int inputsAmount)
    : m_learningRate(0.004), pNAND(2, 0.1), pOR(2, 0.1), pAND(2, 0.1)
{
    m_weights.resize(inputsAmount, 1.0);
    srand(time(0));
}

void NeuronNet::initXOR() {
    pNAND.setWeights({-1, -1});
    pNAND.setThreshold(-1.5);

    pOR.setWeights({1, 1});
    pOR.setThreshold(0.5);

    pAND.setWeights({1, 1});
    pAND.setThreshold(2);
}

void NeuronNet::modelXOR() {
    initXOR();

    vector<vector<int>> inputs = {{0,0},{0,1},{1,0},{1,1}};
    vector<int> targets = {0,1,1,0};

    cout << "Моделювання логічної функції Виключне АБО:" << endl;

    for (size_t index = 0; index < inputs.size(); index++) {
        int firstResult = pNAND.predict(inputs[index]);
        int secondResult = pOR.predict(inputs[index]);
        int finalResult = pAND.predict({firstResult, secondResult});

        cout << "Вхід: " << inputs[index][0] << " " << inputs[index][1]
             << " => Вихід: " << finalResult << " (Очікуваний: " << targets[index] << ")";

        if (finalResult == targets[index])
            cout << " ВІРНО";
        else
            cout << " НЕПРАВИЛЬНО";

        cout << endl;
    }
    cout << endl;
}

double NeuronNet::predictTimeSeries(const vector<double>& input) {
    double result = input[0] * m_weights[0] + input[1] * m_weights[1] + input[2] * m_weights[2];
    return sigmoid(result);
}

void NeuronNet::trainTimeSeries(const vector<double>& series, int epochs, size_t trainCount) {
    for (double &weigth : m_weights)
        weigth = static_cast<double>(rand()) / RAND_MAX;

    for (int epoch = 0; epoch < epochs; epoch++) {
        for (size_t inputIdx = 0; inputIdx + 3 < trainCount; inputIdx++) {
            vector<double> input = { series[inputIdx], series[inputIdx+1], series[inputIdx+2] };
            double predicted = predictTimeSeries(input);
            double error = predicted - series[inputIdx+3];

            for (size_t weightIdx = 0; weightIdx < m_weights.size(); weightIdx++)
                m_weights[weightIdx] -= m_learningRate * error * input[weightIdx];
        }
    }
}

void NeuronNet::testTimeSeries(const vector<double>& series, size_t trainCount) {
    cout << "Прогнозування часового ряду:" << endl;
    for (size_t index = trainCount - 3; index + 3 < series.size(); index++) {
        vector<double> input = { series[index], series[index+1], series[index+2] };
        double predict = predictTimeSeries(input);
        double expected = series[index+3];

        double accuracy = 100.0 * (1.0 - fabs(predict - expected) / expected);
        if (accuracy < 0) accuracy = 0;

        cout << "Вхід: " << input[0] << ", " << input[1] << ", " << input[2]
             << " => Вихід: " << predict << " (Очікуваний: " << expected << ")"
             << " Точність: " << accuracy << "%" << endl;
    }
    cout << endl;
}

void NeuronNet::trainAndTestTS(vector<double>& series, int epochs) {
    trainTimeSeries(series, epochs);
    testTimeSeries(series);
}

