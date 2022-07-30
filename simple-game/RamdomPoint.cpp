#include "RamdomPoint.h"

RandomPoint::RandomPoint()
{

}

RandomPoint::RandomPoint(int n_rows, int n_cols, bool debug)
{
    if (!debug)
    {
        std::random_device rd; // obtain a random number from hardware
        gen_for_cols = new std::mt19937(rd());// seed the generator
        gen_for_rows = new std::mt19937(rd());
    }
    else
    {
        gen_for_cols = new std::mt19937(37);
        gen_for_rows = new std::mt19937(531);
    }

    distr_rows = new std::uniform_int_distribution<>(0, n_rows - 1);
    distr_cols = new std::uniform_int_distribution<>(0, n_cols - 1);
}


Point RandomPoint::generate()
{
    Point result{ 
        distr_cols->operator()(*gen_for_cols), 
        distr_rows->operator()(*gen_for_rows), 
    };
    return result;
}
