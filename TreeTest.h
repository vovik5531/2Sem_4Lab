#ifndef TREETEST_H
#define TREETEST_H
#include "Tree.h"
#include<iostream>
#include<string>

template<typename T>
class TreeTest
{

    public:
        void testAll()
        {
            testInsert();
            testContains();
            testRemove();
            testOperators();
            testReadFromString();
            std::cout<< "TREE WORK CORRECTLY!\n";
        }

        
    private:
        void testInsert()
        {
            BinTree<T> tree;
            tree.insert(15);
            tree.insert(21);
            tree.insert(3);
            tree.insert(19);
            tree.insert(20);
            tree.insert(34);
        }
        void testContains()
        {
            BinTree<T> tree;
            tree.insert(15);
            tree.insert(21);
            tree.insert(3);
            tree.insert(19);
            tree.insert(20);
            tree.insert(34);
            if (!(tree.contains(15) && tree.contains(21) && tree.contains(3)))
            {
                throw std::length_error("CONTAIN ERROR\n");
            }
        }
        void testRemove()
        {
            BinTree<T> tree;
            tree.insert(15);
            tree.insert(21);
            tree.insert(3);

            tree.remove(21);
            if (tree.contains(21)) 
            {
                throw std::logic_error("INSERT_ERROR\n");
            }
        }
        void testOperators()
        {
            BinTree<T> tree1;
            tree1.insert(5);
            tree1.insert(10);

            BinTree<T> tree2;
            tree2.insert(10);
            tree2.insert(9);
            tree2.insert(15);
            BinTree<T> result_tree = tree1+ tree2;
        }
        void testReadFromString()
        {
            BinTree<T> tree;
            std::string input_str = "5 10 3 7 8"; 
            tree.readFromString(input_str);

            if (!(tree.contains(5) && tree.contains(10) && tree.contains(3)  && tree.contains(7) && tree.contains(8)))
            {
                throw std::length_error("CONTAINS_ERROR\n");
            }

        }
};


#endif /* TREETEST_H */