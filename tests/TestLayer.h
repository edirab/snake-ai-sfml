#pragma once
#include <iostream>

#include "../snake-ai-sfml/Matrix.h"
#include "../snake-ai-sfml/Layer.h"

class TestLayer
{
public:
	void crossover();
	void test_process();
	void copy_ctor();
private:
};



void TestLayer::test_process()
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


void TestLayer::crossover()
{
	Layer L1(8, 4);
	L1.randomize();

	Layer L2(8, 4);

	L1.print();
	L2.print();

	Matrix w1 = L1.get_weights();
	Matrix b1 = L1.get_biases();
	Matrix w2 = L2.get_weights();
	Matrix b2 = L2.get_biases();

	cout << "w3 crossovered:\n";
	Matrix w3 = w1.crossover(w2);
	w3.print();

	cout << "b3 crossovered:\n";
	Matrix b3 = b1.crossover(b2);
	b3.print();
	return;
}

void TestLayer::copy_ctor()
{
	Layer L1(8, 4);
	L1.randomize();

	Layer L2(8, 4);
	L2.randomize();

	L1.print();
	L2.print();

	Eigen::MatrixXd inputs(8,1);
    inputs << 1, 2, 3, 4, 
		5, 
		6, 
		7, 
		8;

	Layer L3(L1);
	L3.print();
		
	Matrix res =  L3.process(inputs);
    res.print(); 

	Layer L4(L2.get_weights(), L2.get_biases());
	L4.print();

	return;
}