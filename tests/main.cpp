#include <iostream>

#include "../snake-ai-sfml/Matrix.h"
#include "../snake-ai-sfml/Layer.h"
#include "TestMatrix.h"

using std::cout;


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
    Eigen::MatrixXd res =  layer0.process(inputs);
    cout << res << "\n"; 
    return;
}

int main()
{
    TestMatrix tm;
    //tm.execute();

    test_process();
    return 0;
}
