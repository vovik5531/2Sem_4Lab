#pragma once
namespace Constants
{
    inline constexpr int ClassMaxSize {2147483647}; 
    inline constexpr int AmountOfFunctionsCompareStud {3};
}

int Square(const int& a){return a*a;}

int Constant(const int &a=0) {return Constants::ClassMaxSize;}


