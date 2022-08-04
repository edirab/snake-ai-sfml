#include <iostream>

#include "../snake-ai-sfml/Matrix.h"
#include "../snake-ai-sfml/Layer.h"
#include "../snake-ai-sfml/NeuralNet.h"
#include "TestMatrix.h"

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

void test_process()
{
    int nInputs = 3;
    int nNuerons = 2;

    Layer layer0(3, 2);
    layer0.randomize();

    Eigen::MatrixXd inputs(3,1);
    inputs << 1,
              2, 
              3;

    layer0.print();

    cout << "\n res: \n"; 
    Matrix res =  layer0.process(inputs);
    res.print(); 
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

    TestMatrix tm;
    //tm.execute();
    //test_process();
    //test_process();
    
    test_Net();

    return 0;
}
