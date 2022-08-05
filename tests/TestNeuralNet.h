#pragma once
#include <vector>
#include "../snake-ai-sfml//NeuralNet.h"

using std::vector;

class TestNeuralNet
{
public:
	void pass();
private:

};


void TestNeuralNet::pass()
{
    vector<int> inputs;
    for (int i = 0; i < 26; ++i)
    {
        inputs.push_back(i);
    }

    NeuralNet net(2, 8, 26, 4);
    auto res = net.pass(inputs);
    return;
}
