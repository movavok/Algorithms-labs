#include "neuronnet.h"

int main() {
    Perceptron neuron(3, 0.1);
    neuron.modelAND();
    neuron.modelOR();
    neuron.modelNOT();

    NeuronNet net(3);
    net.modelXOR();

    vector<double> series = {
        1.88, 4.52, 1.91, 5.66, 1.23, 5.50, 1.14, 5.29,
        1.60, 4.31, 0.06, 5.33, 0.07, 4.62, 0.69
    };

    net.trainAndTestTS(series, 50000);

    vector<vector<int>> inputs = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 1}
    };

    vector<int> targets = {1, 1, 0, 1};

    cout << "Додаткове завдання: " << endl;
    neuron.train(inputs, targets);
    neuron.test(inputs, targets);

    return 0;
}
