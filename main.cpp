#include<iostream>
#include "Tree.h"
#include "UserInterface.h"
#include "SpeedTests.h"
#include "UserFunctionsForMap.h"
#include <vector>
#include <algorithm>

int main()
{
    //mainLoop();
    
    Studentscomparator cmp(compare_by_surname);
    Student stud1("Vova", "Avdeyev", 2, "22", compare_by_surname);
    Student stud2("Rustam", "Valeev", 2, "22", compare_by_surname);
    std::cout << "Hey!";
    int a = cmp(stud2, stud1);
    std::cout << a;
    return 0; 
}