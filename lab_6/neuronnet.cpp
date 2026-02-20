#include "neuronnet.h"

NeuronNet::NeuronNet(int inputsAmount)
    : m_learningRate(0.1), m_threshold(0.5), pNAND(2), pOR(2), pAND(2)
{
    m_weights.resize(inputsAmount, 1.0);
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
}


