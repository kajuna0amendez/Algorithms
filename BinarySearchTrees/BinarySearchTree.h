#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

using namespace std;

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree: public BinaryTree<T>{

    public:
        BinarySearchTree(): BinaryTree<T>(){}
        BinarySearchTree(int key, T Payload): BinaryTree<T>(key,Payload){}

        virtual void insert(int key, T Payload);
        virtual T search(int key);
        virtual T deleteNode(int key);

};



#include "BinarySearchTree.cpp"

#endif	/* BINARY_SEARCH_TREE_H */
