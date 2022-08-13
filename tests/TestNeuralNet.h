#pragma once
#include <vector>
#include "../snake-ai-sfml/ai_agent/include/NeuralNet.h"
#include "../snake-ai-sfml/ai_agent/include/EvolutionParams.h"

using std::vector;

class TestNeuralNet
{
public:
    TestNeuralNet();

	void pass();

    void copy_ctor();
private:
    EvolutionParams p;
};

TestNeuralNet::TestNeuralNet()
{
	p.mutation_rate = 0.05;
}

void TestNeuralNet::pass()
{
    vector<float> inputs;
    for (int i = 0; i < 26; ++i)
    {
        inputs.push_back(i);
    }

    NeuralNet net(p, 2, 8, 26, 4);
    auto res = net.pass(inputs);
    return;
}

void TestNeuralNet::copy_ctor()
{
    vector<float> inputs;
    for (int i = 0; i < 26; ++i)
    {
        inputs.push_back(i);
    }

    NeuralNet net_1(p, 2, 8, 26, 4);
    auto res = net_1.pass(inputs);
        
    NeuralNet net_2(p, 2, 8, 26, 4);
    net_2.pass(inputs);

    NeuralNet net_3 = net_1.crossover(net_2);
    net_3.pass(inputs);
    return;
}