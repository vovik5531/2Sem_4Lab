#ifndef SET_H
#define SET_H
#include<iostream>
#include<string>
#include"Tree.h"

template <typename T>
class Set
{
    private:
        BinTree<T> tree;

    public:
        Set() : tree() {}
        Set(const Set<T>& another_set) : tree(another_set) {}
        bool operator ==(const Set<T>& another_set) const
        {
            if(this->tree == another_set.tree) return true;
            return false;
        }
        Set<T> operator + (const Set<T>& another_set)
        {
            Set<T> result; 
            result.tree = this->tree + another_set.tree;
            return result;
        }
        Set<T> operator - (const Set<T>& set)
        {
            Set<T> result;
            result = this->tree - set.tree;
            return result;
        }
        void print() 
        {
            tree.print();
        }
        void insert(const T& value) 
        {
            if(!tree.contains(value)) tree.insert(value);
        }
        void remove(const T& value)
        {
            if(tree.contains(value)) tree.remove(value);
        }
        bool contains(const T& value) 
        {
            return tree.contains(value);
        }
        bool isIncluded (const Set<T> set)
        {
            return tree.isSubTree(set);
        }
        Set<T> where(bool (*pred)(const T&))
        {
            Set<T> result = this->tree.where(pred);
            return result; 
        }
        template <typename F>
        Set<T> map(F function) const 
        {
            Set<T> result; 
            result.tree = this->map(function);
            return result;
        }
        void ReadFromStr(const std::string& string_input)
        {
            std::stringstream str_stream(string_input);
            T value;
            while (str_stream >> value)
            {
                tree.insert(value);
            }
        }
};  

#endif /* SET_H */
