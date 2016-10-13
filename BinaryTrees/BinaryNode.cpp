#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>

/* Binary Node definitions */
/*
	Do not include to avoid circular defintions when using templates
*/

template<typename T>
BinaryNode<T>::BinaryNode(){}

template<typename T>
BinaryNode<T>::BinaryNode(int key, T Payload){

	/*Setting everything to null*/
	NKey  	=   key;
	Payload	=   Payload;
	Parent	=	NULL;
	Left	=	NULL;
	Right	=	NULL;

}

template<typename T>
BinaryNode<T>::~BinaryNode(){

	}

// Get Operations
template<typename T>
int BinaryNode<T>::getKey(){

	return NKey;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getLeft(){

	return Left;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getRight(){

	return Right;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getParent(){

	return Parent;
}

template<typename T>
T BinaryNode<T>::getData(){

	return Payload;
}


// Set Operations
template<typename T>
void BinaryNode<T>::setKey(int key){

	NKey = key;
}

template<typename T>
void BinaryNode<T>::setLeft(BinaryNode<T> *NNode){

	Left = NNode;
}

template<typename T>
void BinaryNode<T>::setRight(BinaryNode<T> *NNode){

	Right = NNode;
}

template<typename T>
void BinaryNode<T>::setRight(BinaryNode<T> *NNode){

	Parent = NNode;
}
