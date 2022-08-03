#include <iostream>

#include "../snake-ai-sfml/Matrix.h"


using std::cout;

void test_random()
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


void test_activate()
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

void test_mutate()
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


int main()
{
    //test_random();
    //test_activate();
    test_mutate();
    return 0;
}
