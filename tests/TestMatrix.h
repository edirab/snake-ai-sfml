#pragma once
#include <iostream>

#include "../snake-ai-sfml/ai_agent/include/Matrix.h"

using std::cout;

class TestMatrix
{
public:
    void execute();
private:
	void test_random();
	void test_activate();
	void test_mutate();

    void test_vector_ctor();
    void test_crossover();
};

void TestMatrix::execute()
{
    //test_random();
    //test_activate();
    //test_mutate();
    //test_vector_ctor();
    test_crossover();
}


void TestMatrix::test_random()
{
	Matrix m1(2, 4);
    m1.print();
    cout << "\n";

    m1.randomize();
    m1.print();
    cout << "\n";

    m1.randomize();
    m1.print();
    cout << "\n";

    m1.randomize();
    m1.print();
    cout << "\n";
    return;
}

void TestMatrix::test_activate()
{
    Matrix m2(1, 10);
    m2.randomize();
    m2.print();
    cout << "\n";

    m2.activete();
    m2.print();
    cout << "\n";
    return;
}

void TestMatrix::test_mutate()
{
    cout << "\tMatrix 5 by 10: \n";
    Matrix m3(5, 10); m3.print(); cout << "\n";
    m3.mutate(0.05); m3.print(); cout << "\n";
    m3.mutate(0.05); m3.print(); cout << "\n";
    m3.mutate(0.05); m3.print(); cout << "\n";

    // this will change the only one element
    cout << "\tMatrix 1 by 10: \n";
    Matrix m4(1, 10); m4.print(); cout << "\n";

    m4.mutate(0.05); m4.print(); cout << "\n";
    m4.mutate(0.05); m4.print(); cout << "\n";
    m4.mutate(0.05); m4.print(); cout << "\n";
        
    return;
}

void TestMatrix::test_vector_ctor()
{
    vector<float> ins = {1, 2, 3, 4, 5};
    Matrix m1(ins);

    m1.print();
}

void TestMatrix::test_crossover()
{
    cout << "Crossover:\n";
    vector<float> in1 = {1, 2, 3, 4, 5};
    Matrix m1(in1);

    vector<float> in2 = {10, 20, 30, 40, 50};
    Matrix m2(in2);

    Matrix m3 = m1.crossover(m2);
    m3.print();
    return;
}
