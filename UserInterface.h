#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "Set.h"
#include "students.h"
#include "MenuForRNumbers.h"
#include "MenuForStudents.h"
#include "TreeTest.h"
#include "SpeedTests.h"

void typeCreate()
{
    std::cout << "-------------------Выберите тип данных--------------------\n ";
    std::cout << "   1. Целые числа\n";
    std::cout << "   2. Вещественные числа\n";
    std::cout << "   3. Строки\n";
    std::cout << "   4. Студенты\n";
    std::cout << "   0. Назад\n";
}
void Menu()
{
    std::cout << "-----------------------ГЛАВНОЕ МЕНЮ-----------------------\n";
    std::cout << "   1. Создать структуру\n";
    std::cout << "   2. Запуск тестов\n";
    std::cout << "   3. Запуск тестов на скорость\n";
    std::cout << "   0. Выход\n";
}
void structCreate()
{
    std::cout <<"--------------------Выберите структуру--------------------\n";
    std::cout << "  1. Создать бинароное дерево\n";
    std::cout << "  2. Создать множество\n";
    std::cout << "  0. Назад\n";
}
int getUserChoice(int mn, int mx) {
    int choice; 
    while(1)
        {
            std::cin >> choice;
            if (choice < mn || choice > mx) std::cout << "Неизвестная команда\n";
            else break;
        }
    return choice;
}
void mainLoop()
{
    BinTree<int> tree1_int, tree2_int;
    BinTree<double> tree1_double, tree2_double; 
    BinTree<std::string> tree1_str, tree2_str; 
    BinTree<Student> tree1_stu; 
    TreeTest<int> test_tree;
    BinTree<int> TestS;
    SpeedTests TestSp = SpeedTests(TestS);
    test_tree.testAll();
    Set<int> set_of_int;
    Set<double> set_of_double;
    Set<std::string> set_of_string; 
    Set<Student> set_of_students; 
    int type, structseq; 

    while(1)
    {
        Menu();
        int UserChoice = getUserChoice(0, 3);
        switch (UserChoice)
        {
        case 1:
            {
                structCreate();
                UserChoice = getUserChoice(0, 2);
                if( UserChoice == 0) break;
                if( UserChoice == 2 )
                {
                    typeCreate(); 
                    type = getUserChoice(0, 4);
                    switch (type)
                    {
                    case 1:
                        std::cout << "тут должно быть меню для сета";
                        //MenuForSets();
                        break;
                    case 2: 
                        std::cout << "тут должно быть меню для сета";
                        break;
                    case 3:
                        std::cout << "тут должно быть меню для сета";
                        break;
                    case 4:
                        std::cout << "тут должно быть меню для сета";
                        break;
                    default:
                        break;
                    }
                }
                if( UserChoice == 1)
                {
                    typeCreate(); 
                    type = getUserChoice(1, 4);
                    if(type == 1)
                    {
                        MenuForNumbers IntNumbers(tree1_int, tree2_int);
                        IntNumbers.run();
                        break;
                    }
                    if(type == 2)
                    {
                        MenuForNumbers DoubleNumbers(tree1_double, tree2_double);
                        DoubleNumbers.run();
                        break;
                    }
                    if(type == 3)
                    {
                        MenuForNumbers Strings(tree1_str, tree2_str);
                        Strings.run();
                        break;
                    }
                    if(type == 4)
                    {
                        MenuForStudents Numbers(tree1_stu);
                        Numbers.run();
                        break;
                    }
                    
                }
            }
        

        case 2:
            test_tree.testAll();
            break; 
        case 3:
            TestSp.GetTime(); 
            std::cout << "That's all, folks!";
            break;
        case 4:

        default:
            break;
        }
    }
}

#endif /* USERINTERFACE_H */