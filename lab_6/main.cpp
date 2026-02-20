#include "neuronnet.h"

int main()
{
    Perceptron neuron(2);
    neuron.modelAND();
    neuron.modelOR();
    neuron.modelNOT();

    NeuronNet net(3);
    net.modelXOR();

    return 0;
}
