#include <iostream>

#include "../snake-ai-sfml/ai_agent/include/Matrix.h"
#include "../snake-ai-sfml/ai_agent/include/Layer.h"
#include "../snake-ai-sfml/ai_agent/include/NeuralNet.h"
#include "TestMatrix.h"
#include "TestLayer.h"
#include "TestNeuralNet.h"
#include "TestSnakeAI.h"
#include "TestPopulation.h"
#include "TestEvolution.h"

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

int main()
{
    //test_eigen_copy_ctor();

    //TestMatrix tm;
    //tm.execute();
    //test_process();
    
    //test_Net();

    //TestLayer tl;
    //tl.crossover();
    //tl.copy_ctor();

    //TestNeuralNet tn;
    //tn.pass();
    //tn.copy_ctor();

    //TestSnakeAI snake_agent;
    //snake_agent.run();
    //snake_agent.copy_ctor();
    //snake_agent.breed();

    //TestPopulation pop;
    //pop.run_simulation();
    //pop.prior_queue();

    TestEvolution te;
    te.start();

    return 0;
}
