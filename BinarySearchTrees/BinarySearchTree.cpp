#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <random>
#include "BinaryTree.h"


/* Binary Search Tree definitions */
/*
	Do not include to avoid circular defintions when using templates
*/

using namespace std;

/* Inserting in a Binary Search Tree */
template<typename T>
void BinarySearchTree<T>::insert(int key, T Payload){

		/* Create Node to be inserted */
		BinaryNode<T> *NNode = new BinaryNode<T>(key,Payload);

		/* The Search Pointers  */
		if (this->Root!=NULL){
					BinaryNode<T> *RNode = this->Root;
					BinaryNode<T> *PNode = NULL;


					if (this->T_size == 0){

							this->Root = new BinaryNode<T>(key,Payload);

							this->T_size++;

					}else{

						while(RNode!=NULL){


							/* Moving downward taking decisions
							 	Case 1 <
								Case 2 >=
							*/
							if (RNode->getKey()>key){
								PNode = RNode;
								RNode = RNode->getLeft();
							}else{
								PNode = RNode;
								RNode = RNode->getRight();
							}

						}

						/* Insert the Node */
						if (PNode->getKey()>key){
								PNode->setLeft(NNode);
								(PNode->getLeft())->setParent(PNode);
						}else{
								PNode->setRight(NNode);
								(PNode->getRight())->setParent(PNode);
						}

						/* Increase the counter */
						this->T_size++;

					}
		}

}

/* Search in a Binary Search Trees using a binary like search */
template<typename T>
T BinarySearchTree<T>::search(int key){

	/* The Search Pointers  */
	if (this->Root!=NULL){
				BinaryNode<T> *RNode = this->Root;
				BinaryNode<T> *PNode = NULL;

				while(RNode!=NULL){
							/* Moving taking decisions
								Case 1 =
								Case 2 >
								Case 3 <
							*/
							if (RNode->getKey()==key){
								return RNode->getData();
							}else if (RNode->getKey()>key){
								PNode = RNode;
								RNode = RNode->getLeft();
							}else{
								PNode = RNode;
								RNode = RNode->getRight();
							}

				}
	}

	return (T)0;

}

/* Find and Delete a Node in a Binary Search Tree */
template<typename T>
T BinarySearchTree<T>::deleteNode(int key){

	/* The Search Pointers  */
	if (this->Root!=NULL){
				BinaryNode<T> *RNode = this->Root;

				while(RNode!=NULL){
							/* Moving taking decisions
								Case 1 =
								Case 2 >
								Case 3 <
							*/
							if ( RNode->getKey()==key){
								return this->Tree_Delete(RNode);
							} else if (RNode->getKey()>key){
									RNode = RNode->getLeft();
							}	else {
									RNode = RNode->getRight();
							}

				}
	}

	return (T)0;

}
