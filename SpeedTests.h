#ifndef SPEEDTESTS_H
#define SPEEDTESTS_H
#include <iostream>
#include <ctime>
#include <fstream>
#include "Tree.h"
const uint64_t AMOUNT_OF_ELEMENTS_SMALL = 10'000'000;
const uint64_t AMOUNT_OF_ELEMENTS_BIG = 100'000'000;


void TestSpeed()
{
    std::ofstream out;
    out.open("hello.txt");
    srand(time(0)+2);
    BinTree<int> Treei;
    std::cout<<"I'm here!\n";
    unsigned long sort_start_time, sort_end_time = 0;
    double result_timers[100];
    int start = AMOUNT_OF_ELEMENTS_BIG; 
    int end = AMOUNT_OF_ELEMENTS_SMALL+AMOUNT_OF_ELEMENTS_BIG; 
    sort_end_time = clock();
    sort_start_time = sort_end_time;
    std::cout<<"Start it!\n";
    for(uint64_t i=0; i<AMOUNT_OF_ELEMENTS_BIG; ++i)
    {
        int count=0;
        Treei.insert(rand() % (end - start + 1) + start);
        if(i%AMOUNT_OF_ELEMENTS_SMALL==0)
        {
            sort_start_time = sort_end_time;
            int t =  Treei.FindMinIter();
            sort_end_time = clock();

            if(out.is_open())
            {
            //out <<(((float)sort_end_time - (float)sort_start_time) / CLOCKS_PER_SEC);
            out << (((float)sort_end_time - (float)sort_start_time) / CLOCKS_PER_SEC) << ", ";
            }
        }
        
    }
    out << std::endl;
    out.close();
    std::cout<<"File has been written!\n";
    
}

#endif /* SPEEDTESTS_H */