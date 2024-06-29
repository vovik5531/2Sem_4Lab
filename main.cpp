#include<iostream>
#include "Tree.h"
#include "UserInterface.h"

int main()
{
    BinTree<int> t1, t2;
    MenuForNumbers Numbers(t1, t2);
    mainLoop();
    
    // int_tree.insert(4);
    // int_tree.insert(1);
    // int_tree.insert(8);
    // int_tree.insert(89);
    // int_tree.insert(4);
    // int_tree.insert(17);
    // int_tree.insert(2);
    // int_tree.insert(3);
    // int_tree.insert(11);
    //std::string input = "6 7 12 34 888 124 4 -45";
    // //int_tree2.readFromString(input);
    // //int_tree.print();
    // // int_tree2.print();
    // //std::cout << int_tree.findMin();
    // int arr[int_tree2.getSize()]; 
    // std::cout << int_tree2.getSize() <<"\n";
    // std:: cout<< "hello" << '\n';
    // int_tree2.saveAsArr(arr);
    // std:: cout<< "ola" << '\n';
    // for(uint64_t i=0; i<int_tree2.getSize(); ++i)
    // {
    //     std::cout << arr[i] << " ";
    // }
    return 0; 
}