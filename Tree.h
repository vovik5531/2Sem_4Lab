#ifndef TREE_H
#define TREE_H
#include<algorithm>
#include<iostream>
#include<malloc.h>

template <class T>
class BinTree
{
    class Node
    {
        public:
        T node_data;
        Node* left_node; 
        Node* right_node;
        int height;
        explicit Node(const T& data) : node_data(data), left_node(nullptr), right_node(nullptr), height(1){}
    };
private:
    Node* root;
    int(*comparator) (const T& first, const T& second);
    void clear(Node* root) //рекурсивная функция глубокой очистки памяти
    {
        if(root)
        {   
            clear(root->left_node);
            clear(root->right_node); 
            delete root; 
        }
        
    }
    Node* copyTree(Node* copy_tree_Node) const//рекурсивное копирование дерева через корень(глубокое копирование)
    {
        if(!copy_tree_Node)
        {
            return nullptr; 
        }
        T data = copy_tree_Node->node_data;
        Node* new_node = new Node(data); 
        new_node->left_node = copyTree(copy_tree_Node->left_node);
        new_node->right_node = copyTree(copy_tree_Node->right_node);
        return new_node;
    }
public:
    BinTree() : root(nullptr){}
    ~BinTree()
    {
        clear(root);
    }
    explicit BinTree(Node* new_tree_root) : root(new_tree_root){}
    BinTree(const BinTree<T>& tree)
    {
        root = copyTree(tree.root); 
    }
    BinTree<T>& operator = (const BinTree<T>& other_assigment)
    {
        if(this == &other_assigment) return *(this);
        else
        {
            clear(root); 
            root = copyTree(other_assigment.root); 
            return *this;
        }
    }
    bool operator ==(const BinTree<T>& other_to_compare) const //TODO : make saveAsArr method 
    {
        uint64_t size_of_first = this->getSize();
        uint64_t size_of_second = other_to_compare.getSize();

        if(size_of_first != size_of_second) return false;

        T first_elements[size_of_first]; 
        T second_elements[size_of_second]; 
        this->saveAsArr(first_elements);
        other_to_compare.saveAsArr(second_elements);

        for(uint64_t i = 0; i < size_of_first; ++i)
        {
            if(first_elements[i] != second_elements[i]) return false; 
        }

        return true;
    }
    BinTree<T> operator +(const BinTree<T>& tree_to_add)
    {
        BinTree<T> result; 
        result.root = copyTree(this->root); 
        this->addTreePrivate(result.root, tree_to_add.root); 
        return result; 
    }
    BinTree<T> operator -(const BinTree<T>& tree_to_substarct)
    {
        BinTree<T> result = *(this);
        BinTree<T> copy = tree_to_substarct;
        uint64_t copy_size = this->getSize();
        T* copy_arr = new T[copy_size];
        copy.saveAsArr(copy_arr);
        for(uint64_t i = 0; i< copy_size; ++i)
        {
            if(result.contains(copy_arr[i]))
            {
                result.remove(copy_arr[i]);
            }
        }
        
        
        return result; 
    }
    friend std::ostream& operator <<(std::ostream& out_stream, const BinTree<T>& tree )
    {
        tree.printTree(tree.root);
        return out_stream;
    }
    void print() const//FOO
    {
        printTree(root); 
        std::cout<<std::endl;
    }
    void printTree( Node* root) const
    {
        printTreeView("", root, 0); 
    }
    void saveAsArr(T* arr, int type_of_traversal=4) const
    {
        saveAsArrPrivate(root, arr, 0, type_of_traversal);
        //std::cout<<"Kuku!" << std::endl;
    }
    void readFromString(const std::string input_s)
    {
        std::stringstream str_stream(input_s);
        T value; 
        while(str_stream >> value)
        {
            insert(value); 
        }
    }
    BinTree<T> where(bool (*pred)(const T&))
    {
        BinTree<T> result_tree; 
        WherePrivate(root, result_tree, pred);
        return result_tree;
    }
    void readFromStream(const std::istream stream)
    {
        T value;
        while(stream >> value)
        {
            insert(value);
        }
    }
    
    void insert(const T& value)
    {
        root = insertPrivate(root, value); 
    }


    [[nodiscard]]uint64_t getSize() const
    {
        return GetSizePrivate(root); 
    }

    T& findMin() const
    {
        if(root) return findMinPrivate(root)->node_data;
        else
        {
            throw std::runtime_error("empty_node");
        }
    }
    bool contains(const T& value)
    {
       return containsPrivate(root, value); 
    }
    bool isSubTree(const BinTree<T>& another_tree)
    {
        uint64_t another_tree_size = another_tree.getSize();
        if(another_tree_size == 0) return true;
        T* another_tree_arr = new T[another_tree_size]; 
        another_tree.saveAsArr(another_tree_arr);
        bool answer = true;
        for(uint64_t i = 0; i< another_tree_size; ++i)
        {
            if( !(this->contains(another_tree_arr[i])) ) answer = false;
        }
        delete[] another_tree_arr;
        return answer;   
    }
    void remove(const T& value)
    {
        root = removePrivate(root, value);
    }
    BinTree<T> extractSubtree(const T& value) 
    {
        Node* new_root = FindNodePrivate(root, value);
        if (new_root == nullptr) throw std::runtime_error("NO_VALUE_ERROR\n");
        BinTree<T> sub, result;
        sub = this->extractCopySubtree(value);
        result = *this- sub;
        return result;
    }

    BinTree<T> extractCopySubtree(const T& value) const 
    {
        Node* new_root = FindNodePrivate(root, value);
        if (new_root == nullptr) throw std::runtime_error("NO_VALUE_ERROR\n");
        BinTree<T> sub;
        sub.root = copyTree(new_root);
        return sub;
    }
    template <typename F>
    BinTree<T> map(F function) const
    {
        BinTree<T> result; 
        MapRecursive(root, result, function);
        return result; 
    }
    T FindMinIter()
    {
        return FindMinIterPrivate(this->root);
    }

private:
    
    void addTreePrivate(Node*& root_first, Node* root_second)
    {
        if(root_second)
        {
            root_first = insertPrivate(root_first, root_second->node_data);
            addTreePrivate(root_first, root_second->left_node);
            addTreePrivate(root_first, root_second->right_node);
        }
    }

    uint64_t GetSizePrivate (Node* root) const 
    {
        if(!root) return 0; 
        else
        {
            return 1+GetSizePrivate(root->left_node)+GetSizePrivate(root->right_node);
        }
    }
    Node* insertPrivate(Node* node, const T& value)
    {
        if (!node)
        {
            return new Node(value);
        }

        if (value < node->node_data)
        {
            node->left_node = insertPrivate(node->left_node, value);
        }
        else if (value > node->node_data)
        {
            node->right_node = insertPrivate(node->right_node, value);
        }
        updateHeigth(node);
        return balance(node);
    }
    bool containsPrivate(Node* node, const T& value)
    {
        if(!node) return false; 
        if(value == node->node_data) return true; 
        else if(value < node->node_data)
        {
            containsPrivate(node->left_node, value );
        }
        else if(value > node->node_data)
        {
            containsPrivate(node->right_node, value );
        }
    }
    int height (Node* node) const
    {
        if(node) return node->height;
        return 0; 
    }
    int balanceFactor(Node* node) const
    {
        return height(node->left_node) - height(node->right_node);
    }
    void updateHeigth( Node* node) const
    {
        node->height = 1 + std::max(height(node->left_node), height(node->right_node));
    }
    Node* rotateRight(Node* node) const
    {
        Node* new_root = node->left_node;
        node->left_node = new_root->right_node;
        new_root->right_node = node;
        updateHeigth(node);
        updateHeigth(new_root);
        return new_root;
    }
    Node* rotateLeft(Node* node) const
    {
        Node* new_root = node->right_node;
        node->right_node = new_root->left_node;
        new_root->left_node = node;
        updateHeigth(node);
        updateHeigth(new_root);
        return new_root;
    }
    Node* balance(Node* node) const
    {
        if (balanceFactor(node) > 1)
        {
            if (balanceFactor(node->left_node) < 0)
            {
                node->left_node = rotateLeft(node->left_node);
            }
            return rotateRight(node);
        }
        else if (balanceFactor(node) < -1)
        {
            if (balanceFactor(node->right_node) > 0)
            {
                node->right_node = rotateRight(node->right_node);
            }
            return rotateLeft(node);
        }
        return node;
    }
    Node* findMinPrivate(Node* node) const
    {
        if(!node->left_node) return node; 
        else
        {
            return findMinPrivate(node->left_node); //уходим дальше влево рекурсивно если есть возможность
        }
    }
    T FindMinIterPrivate( Node* root_in) const 
    {
        Node* ptr = root_in;
        if (ptr == nullptr) {
            throw std::out_of_range("Can't find maximum key in empty tree");
        }
        while (ptr->left_node) {
            ptr = ptr->left_node;
        }
        return ptr->node_data;
    }
    Node* removePrivate(Node* node, const T& value)
    {
        if (!node) return nullptr;
        if (value < node->node_data) //уходим в левого ребенка, тк только там может находится необходимое значение
        {
            node->left_node = removePrivate(node->left_node, value); //уходим в левого ребенка рекурсивно
        }
        else if (value > node->node_data)
        {
            node->right_node = removePrivate(node->right_node, value); //уходим в правого ребенка рекурсивно
        }
        else
        {
            if ( !(node->left_node) && !(node->right_node) )
            {
                return nullptr;
            }
            if (!(node->left_node))
            {
                return node->right_node;
            }
            else if (!(node->right_node))
            {
                return node->left_node;
            }
            Node* new_node = findMinPrivate(node->right_node);
            node->node_data = new_node->node_data;
            node->right_node = removePrivate(node->right_node, new_node->node_data);
        }

        return balance(node);
    }
    Node* FindNodePrivate(Node* node, const T& value) const
    {
        if(!node) return nullptr;
        if(value == node->node_data) return node; 
        else if(value < node->node_data)
        {
            return FindNodePrivate(node->left_node, value);
        }
        else if(value > node->node_data)
        {
            return FindNodePrivate(node->right_node, value);
        }
    }
    void printTreeView(const std::string& prefix, Node* node, bool isLeft) const 
    {
        if( node )
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├──" : "└──" );
            std::cout << node->node_data << std::endl;
            printTreeView( prefix + (isLeft ? "│   " : "    "), node->left_node, true);
            printTreeView( prefix + (isLeft ? "│   " : "    "), node->right_node, false);
        }
    }
    void removeSubtreePrivate(Node* current, Node* target)
    {
        if (!current) return;
        if (current == target) current = nullptr;
        else
        {
            removeSubtreePrivate(current->left_node, target);
            removeSubtreePrivate(current->right_node, target);
        }
    }

    uint64_t saveAsArrPrivate(Node* node, T* arr, uint64_t index, int walk=4) const
    {
        if(walk == 1) //Root-Left-Right
        {
            if (!node) return index;
            arr[index++] = node->node_data; // К
            index = saveAsArrPrivate(node->left_node, arr, index); 
            index = saveAsArrPrivate(node->right_node, arr, index);
            return index;
        }
        if(walk == 2) //Root-Right-Left
        {
            if (!node) return index;
            arr[index++] = node->node_data; // К
            index = saveAsArrPrivate(node->right_node, arr, index); 
            index = saveAsArrPrivate(node->left_node, arr, index);
            return index;
        }
        if(walk == 3) //Left-Right-Root
        {
            if (!node) return index;
            index = saveAsArrPrivate(node->left_node, arr, index);
            index = saveAsArrPrivate(node->right_node, arr, index); 
            arr[index++] = node->node_data; // К
            return index;
        }
        if(walk == 4) //Left-Root-Right
        {
            if (!node) return index;
            
            index = saveAsArrPrivate(node->left_node, arr, index);
            arr[index++] = node->node_data; // К
            index = saveAsArrPrivate(node->right_node, arr, index); 
            return index;
        }
        if(walk == 5) //Right-Left-Root
        {
            if (!node) return index;
            index = saveAsArrPrivate(node->right_node, arr, index); 
            index = saveAsArrPrivate(node->left_node, arr, index);
            arr[index++] = node->node_data; // К
            return index;
        }
        if(walk == 6) //Right-Left-Root
        {
            if (!node) return index;
            index = saveAsArrPrivate(node->right_node, arr, index); 
            arr[index++] = node->node_data; // К
            index = saveAsArrPrivate(node->left_node, arr, index);
            return index;
        }

    }
    void WherePrivate(Node* currentNode, BinTree<T>& newTree, bool (*pred)(const T &))
    {
        if (currentNode)
        {
            WherePrivate(currentNode->left_node, newTree, pred);
            if (pred(currentNode->node_data))
            {
                newTree.insert(currentNode->node_data);
            }
            WherePrivate(currentNode->right_node, newTree, pred);
        }
    }
    template <typename F>
    void MapRecursive(Node* node, BinTree<T>& result, F func) const
    {
        if (node != nullptr)
        {
            T value = func(node->node_data);
            result.insert(value);
            MapRecursive(node->left_node, result, func);
            MapRecursive(node->right_node, result, func);
        }
    }

};



#endif /* TREE_H */