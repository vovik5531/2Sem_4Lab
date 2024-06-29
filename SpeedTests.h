#ifndef SPEEDTESTS_H
#define SPEEDTESTS_H
#include <iostream>
#include <ctime>
#include "Tree.h"
const uint64_t AMOUNT_OF_ELEMENTS_SMALL = 100'000;
const uint64_t AMOUNT_OF_ELEMENTS_BIG = 100;

template<class T>
class SpeedTests
{
private:
    BinTree<T> tree; 
    void GenerateArray(uint64_t size)
    {
        std::cout<<"Here!\n";
        srand(time(0));
        int start = 10;
        int end = AMOUNT_OF_ELEMENTS_SMALL;
        //T* arr = new T[size]; 
        for(uint64_t i=0; i<size; ++i)
        {
            tree.insert(rand() % (end - start + 1) + start);
            std::cout << "!";
        }

    }
    
public:

    explicit SpeedTests(BinTree<T>& tree_input ) : tree(tree_input) {}
    ~SpeedTests() {}
    void GetTime()
    {
        std::cout<<"I'm here!\n";
        float sorter_timers[1000];
        unsigned long sort_start_time, sort_end_time = 0;
        std::cout<<"Here!\n";
        srand(time(0));
        int start = 10;
        int end = AMOUNT_OF_ELEMENTS_SMALL;
        //T* arr = new T[size]; 
        sort_end_time = clock();
        sort_start_time = sort_end_time;
        std::cout<<"Start it!\n";
        for(uint64_t i=0; i<AMOUNT_OF_ELEMENTS_BIG; ++i)
        {
            [[unlikely]]if(i%10'000'000==0){
            sort_end_time = clock();
    
            std::cout << "data: " << i << " time: " << (((float)sort_end_time - (float)sort_start_time) / CLOCKS_PER_SEC) << '\n';
            }
            tree.insert(rand() % (end - start + 1) + start);
        }
        
        std::cout<<"End it!\n";
        
        sort_end_time = clock();
        std::cout << (((float)sort_end_time - (float)sort_start_time) / CLOCKS_PER_SEC) <<'\n';
        tree.print();

    }
};

#endif /* SPEEDTESTS_H */