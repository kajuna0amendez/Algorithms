#ifndef AVL_TREE_H
#define AVL_TREE_H

using namespace std;

#include "BinaryTree.h"
#include "BinarySearchTree.h"

template <typename T>
class AVLNode: public BinaryNode<T>{

    protected:
        /*The New height Structure*/
        int height;
        void Balance(AVLNode<T> *NNode);

    public:
        /*The New Constructors*/
        AVLNode(): BinaryNode<T>(), height(0){}
        AVLNode(int key, T Payload): BinaryNode<T>(key, Payload), height(1){}
        void setHeight(int value);
        int  getHeight();

};

template <typename T>
class AVLTree: public BinarySearchTree<T>{

    protected:
        AVLNode<T>* LeftRotation(AVLNode<T> *XNode);
        AVLNode<T>* RightRotation(AVLNode<T> *XNode);

    public:
        AVLTree();
        AVLTree(int key, T Payload);

        virtual void insert(int key, T Payload);
        virtual T deleteNode(int key);

};

#include "AVLTree.cpp"

#endif	/* AVL_TREE_H */
