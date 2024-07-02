#ifndef TREETEST_H
#define TREETEST_H
#include "Tree.h"
#include<iostream>
#include<string>
#include"UserFunctionsForMap.h"

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
            BinTree<T> tree = tree1+ tree2;
            if (!(tree.contains(5) || tree.contains(10) || tree.contains(9)  || tree.contains(15)))
            {
                throw std::length_error("OPERATOP_+_ERROR\n");
            }
            tree = tree2-tree1;
            if (tree.contains(5) || tree.contains(10) || !(tree.contains(9)))
            {
                throw std::length_error("OPERATOP_-_ERROR\n");
            }
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
        void testWhere()
        {
            auto OperationSmaller8{ [](const int& a) ->bool {return a<8? 1:0; }  };
            auto OperationBigger6 { [](const int& a) ->bool {return a>6? 1:0; }  };
            BinTree<int> tree;
            tree.insert(7);
            tree.insert(9);
            tree.insert(-6);
            tree.insert(4);
            tree.insert(-3);
            BinTree<int> result;
            auto where_function{&OperationBigger6};
            result = tree.where(where_function);
            if (result.contains(-3) || result.contains(-6) || result.contains(4))
            {
                throw std::length_error("WHERE_ERROR\n");
            }
            where_function = OperationSmaller8;
            result = result.where(where_function);
            if (tree.contains(9))
            {
                throw std::length_error("WHERE_ERROR\n");
            }
        }
        void extractTreeTest()
        {
            BinTree<int> tree;
            tree.insert(3);
            tree.insert(4);
            tree.insert(5);
            tree.insert(6);
            tree.insert(7);
            tree.insert(9);
            tree.print();
            BinTree<int> subtree, atree;
            subtree = tree.extractCopySubtree(4);
            if(!(subtree.contains(4) && atree.contains(3) && atree.contains(5)))
            {
                throw std::length_error("EXTRACT_TREE_TROUBLE\n");
            }
            atree = tree.extractSubtree(4);
            if(!(atree.contains(6) && atree.contains(7) && atree.contains(9)))
            {
                throw std::length_error("EXTRACT_TREE_TROUBLE\n");
            }
            subtree = tree.extractCopySubtree(9);
            if(!(subtree.contains(4) ))
            {
                throw std::length_error("EXTRACT_TREE_TROUBLE\n");
            }
        }
        void TestMap()
        {
            BinTree<int> tree;
            tree.insert(7);
            tree.insert(9);
            tree.insert(-6);
            tree.insert(4);
            tree.insert(-3);
            BinTree<int> result;
            tree.print();
            auto where_function=&Square;
            result = tree.map(where_function);
            if(!(result.contains(36) && result.contains(49) && result.contains(81) && result.contains(9) && result.contains(16) ))
            {
                throw std::length_error("MAP_TROUBLE\n");
            }
            auto map_function = &Constant;
            result = tree.map(map_function);
            if(result.findMin() != Constants::ClassMaxSize)
            {
                throw std::length_error("MAP_TROUBLE\n");
            }
        }
};


#endif /* TREETEST_H */