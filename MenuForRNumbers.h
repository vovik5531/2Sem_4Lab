#ifndef MENUFORRNUMBERS_H
#define MENUFORRNUMBERS_H
#include "Tree.h"
#include <iostream>
#include <limits>
#include <sstream>
#include "Set.h"

template <class T>
class MenuForNumbers
{
private:
    BinTree<T> tree1; 
    BinTree<T> tree2; 
    T number; 
    T another_number;
public:
    
    MenuForNumbers(BinTree<T>& tree_f, BinTree<T>& tree_s) : tree1(tree_f), tree2(tree_s){}
    void run()
    {
        int choice;
        do{
            printMenuForStudents();
            choice = safeInputInteger("Выбирете действие:");
            processChoice(choice);

        }while(choice != 0);
    }
    private:
    void printMenuForStudents() const
    {
        std::cout << "\n-----------------------ГЛАВНОЕ МЕНЮ-----------------------\n";
        std::cout << " 1. Добавить число в первое дерево\n";
        std::cout << " 2. Удалить число из первого дерева\n";
        std::cout << " 3. Проверить наличие числа в первом дереве\n";
        std::cout << " 4. Вывести первое дерево\n";
        std::cout << " 5. Ввод нескольких чисел для первого дерева\n";
        std::cout << " 6. Добавить число во второе дерево\n";
        std::cout << " 7. Удалить число из второго дерева\n";
        std::cout << " 8. Проверить наличие числа во втором дереве\n";
        std::cout << " 9. Вывести второе дерево\n";
        std::cout << "10. Ввод нескольких чисел для второго дерева\n";
        std::cout << "11. Объединить первое со вторым деревом\n";
        std::cout << "12. Объединить второе с первым деревом\n";
        std::cout << "13. Удалить первое из второго дерева\n";
        std::cout << "14. Удалить второе из первого дерева\n";
        std::cout << "15. Сравнить первое со вторым деревом\n";
        std::cout << "16. Проверить, является ли первое поддеревом второго\n";
        std::cout << "17. Проверить, является ли второе поддеревом первого\n";
        std::cout << "18. Обход первого дерева\n";
        std::cout << "19. Обход второго дерева\n";
        std::cout << "0. Выход\n";
    }
    void processChoice(int choice)
    {
        switch (choice)
        {
        case 1:
            addNumber1(); 
            break;
        case 2:
            removeNumber1();
            break;
        case 3:
            checkNumber1(); 
            break;
        case 4:
            printNumbers1();
            break;
        case 5:
            inputNumbers1(); 
            break;
        case 6:
            addNumber2(); 
            break;
        case 7:
            removeNumber2();
            break;
        case 8: 
            checkNumber2(); 
            break; 
        case 9:
            printNumbers2(); 
            break; 
        case 10:
            inputNumbers2(); 
            break;
        case 11:
            merge1WithAnotherNumberTree();
            break;
        case 12:
            merge2WithAnotherNumberTree();
            break;
        case 13:
            delete1from2();
            break;
        case 14:
            delete2from1(); 
            break;
        case 15:
            compare1WithAnotherNumberTree();
            break;
        case 16:
            check1IsSubNumberTree2(); 
            break;
        case 17: 
            check2IsSubNumberTree1(); 
            break; 
        case 18:
            TreeWalk(tree1);
            break;
        case 19:
            TreeWalk(tree2);
            break;
        default:
            break;
        }
    }
    void addNumber1()
    {
        T number; 
        number = safeInputNumber("Введите число: ");
        tree1.insert(number);
        std::cout << "Число добавлено!\n";
    }
    void addNumber2()
    {
        T number; 
        number = safeInputNumber("Введите число: ");
        tree2.insert(number);
        std::cout << "Число добавлено!\n";
    }
    void removeNumber1()
    {
        T number; 
        number = safeInputNumber("Введите число: ");
        tree1.remove(number);
        std::cout << "Число удалено!\n";
    }
    void removeNumber2()
    {
        T number; 
        number = safeInputNumber("Введите число: ");
        tree2.remove(number);
        std::cout << "Число удалено!\n";
    }
    void checkNumber1()
    {
        T number; 
        number = safeInputNumber("Введите число: ");
        if (tree1.contains(number))
        {
            std::cout <<std::endl << "Число найдено!\n";
        }
        else 
        {
            std::cout << std::endl << " Число не найдено!\n";
        }
    }
    void checkNumber2()
    {
        T number; 
        number = safeInputNumber("Введите число: ");
        if (tree1.contains(number))
        {
            std::cout <<std::endl << "Число найдено!\n";
        }
        else 
        {
            std::cout << std::endl << " Число не найдено!\n";
        }
    }
    void printNumbers1()
    {
        std::cout << "Дерево чисел №1:\n";
        std::cout << tree1; 
    }
    void printNumbers2()
    {
        std::cout << "Дерево чисел №2:\n";
        tree2.print();
    }
    void inputNumbers1()
    {
        int number_of_students;
        std::cout << "Введите количество чисел: ";
        std::cin >> number_of_students; 
        for (int i=0; i< number_of_students; ++i)
        {
            T number; 
            number = safeInputNumber("Введите число: ");
            tree1.insert(number);
            std::cout << "Число добавлено!\n";
        }
        std::cout << "Числа добавлены!\n";
    }
    void inputNumbers2()
    {
        int number_of_students;
        std::cout << "Введите количество чисел: ";
        std::cin >> number_of_students; 
        for (int i=0; i< number_of_students; ++i)
        {
            T number; 
            number = safeInputNumber("Введите число: ");
            tree2.insert(number);
            std::cout << "Число добавлено!\n";
        }
        std::cout << "Числа добавлены!\n";
    }
    void merge1WithAnotherNumberTree() 
    {
       tree1 = tree1+tree2;
        std::cout<< "Деревья объединены!\n";   
    }
    void merge2WithAnotherNumberTree() 
    {
       tree2 = tree2+tree1;
        std::cout<< "Деревья объединены!\n";   
    }
    void delete2from1()
    {
        if(tree1.isSubTree(tree2))
        {
            tree1 = tree1-tree2;
            std::cout << "Второе удалено из первого!\n";   
        }
        else
        {
            std::cout << "Второго нет в первом!";
        }
    }
    void delete1from2()
    {
        if(tree2.isSubTree(tree1))
        {
            tree2 = tree2-tree1;
            std::cout << "Первое удалено из второго!\n";
        }
        else
        {
            std::cout << "Первого нет во втором!";
        }
    }
    void compare1WithAnotherNumberTree()
    {
        if(tree1 == tree2) 
        {
            std::cout << "Деревья равны!\n";
        }
        else 
        {
            std::cout << "Деревья различны!\n";
        }
    }
    void check1IsSubNumberTree2()
    {
        if(tree1.isSubTree(tree2)) 
        {
            std::cout << "Первое дерево содержится во втором!\n";
        }
        else 
        {
            std::cout << "Первое дерево не содержится во втором!\n";
        }   
    }
    void check2IsSubNumberTree1()
    {
        if(tree2.isSubTree(tree1)) 
        {
            std::cout << "Второе дерево содержится в первом!\n";
        }
        else 
        {
            std::cout << "Второе дерево не содерижтся в первом!\n";
        }   
    }
    T safeInputNumber(const std::string& prompt)
    {
        T value;
        while(true)
        {
            std::cout<< prompt;
            std::cin>>value;
            if(std::cin.fail() || std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода! Введите число!\n";
                
            }
            else 
            {
                return value;
            }
        }
    }
    int safeInputInteger(const std::string& prompt)
    {
        int value;
        while(true)
        {
            std::cout<< prompt;
            std::cin>>value;
            if(std::cin.fail() || std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода! Введите число!\n";
                
            }
            else 
            {
                return value;
            }
        }
    }
    void TreeWalk(const BinTree<T>& tree )
    {
        std::cout << "Выберете тип обхода: \n";
        std::cout << " 1.КЛП\n";
        std::cout << " 2.КПЛ\n";
        std::cout << " 3.ЛПК\n";
        std::cout << " 4.ЛКП\n";
        std::cout << " 5.ПЛК\n";
        std::cout << " 6.ПКЛ\n";
        std::cout << " 0.Выход\n";
        int choice = safeInputInteger("Введите число: ");
        int size = tree.getSize();
        T* arr = new T[size];
        if(choice==1)
        {
            tree.saveAsArr(arr, 1);
            std::cout<<"[ ";
            for (int i=0; i<size; ++i)
            {
                std::cout << arr[i]<< " "; 
            }
            std::cout<< "] - КЛП\n";
        }
        if(choice==2)
        {
            tree.saveAsArr(arr, 2);
            std::cout<<"[ ";
            for (int i=0; i<size; ++i)
            {
                std::cout << arr[i]<< " "; 
            }
            std::cout<< "] - КПЛ\n";
        }
        if(choice==3)
        {
            tree.saveAsArr(arr, 3);
            std::cout<<"[ ";
            for (int i=0; i<size; ++i)
            {
                std::cout << arr[i]<< " "; 
            }
            std::cout<< "] - ЛПК\n";
        }
        if(choice==4)
        {
            tree.saveAsArr(arr, 4);
            std::cout<<"[ ";
            for (int i=0; i<size; ++i)
            {
                std::cout << arr[i]<< " "; 
            }
            std::cout<< "] - ЛКП\n";
        }
        if(choice==5)
        {
            tree.saveAsArr(arr, 5);
            std::cout<<"[ ";
            for (int i=0; i<size; ++i)
            {
                std::cout << arr[i]<< " "; 
            }
            std::cout<< "] - ПЛК\n";
        }
        if(choice==6)
        {
            tree.saveAsArr(arr, 6);
            std::cout<<"[ ";
            for (int i=0; i<size; ++i)
            {
                std::cout << arr[i]<< " "; 
            }
            std::cout<< "] - ПКЛ\n";
        }
        delete[]arr;
    }
};




#endif /* MENUFORRNUMBERS_H */