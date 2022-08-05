#include <iostream>

#include "../snake-ai-sfml/Matrix.h"
#include "../snake-ai-sfml/Layer.h"
#include "../snake-ai-sfml/NeuralNet.h"
#include "TestMatrix.h"
#include "TestLayer.h"

using std::cout;

void test_eigen_copy_ctor()
{
    Eigen::MatrixXd* m1 = new Eigen::MatrixXd(3, 3);
    *m1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    cout << std::hex << m1 << "\n"  << *m1 << "\n\n";

    Eigen::MatrixXd* m2 = new Eigen::MatrixXd();
    *m2 = *m1;
    delete m1;

    cout << std::hex << m2 << "\n" <<  *m2 << "\n";
    delete m2;
    return;
}



void test_Net()
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

int main()
{
    //test_eigen_copy_ctor();

    //TestMatrix tm;
    //tm.execute();
    //test_process();
    
    //test_Net();

    TestLayer tl;
    tl.crossover();

    return 0;
}
