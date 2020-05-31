#ifndef AVL_TREE_H
#define AVL_TREE_H

using namespace std;

#include "BinarySearchTree.h"

template <typename T>
class AVLTree: public BinarySearchTree<T>{

    public:
        AVLTree(): AVLSearchTree<T>(){}
        AVLTree(int key, T Payload): AVLTree<T>(key,Payload){}

        virtual void insert(int key, T Payload);
        virtual T search(int key);
        virtual T deleteNode(int key);

};



#include "AVLTree.cpp"

#endif	/* AVL_TREE_H */
