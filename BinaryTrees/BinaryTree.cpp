
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <random>

/* Binary Tree definitions */
/*
	Include into h file  to avoid circular defintions when using templates
*/

using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() {
	Root = new BinaryNode<T>();
	T_size = 0;
}


/* Construct Functions */
template<typename T>
BinaryTree<T>::BinaryTree(int Key, T Payload){

	/* Generate Node*/

	Root   = new BinaryNode<T>(Key,Payload);
	T_size = 1;

}


/* Destruct Functions */
template<typename T>
BinaryTree<T>::~BinaryTree(){
	if (Root!=NULL)
		DeletePostOrder(Root);
}

template<typename T>
void BinaryTree<T>::DeletePostOrder(BinaryNode<T>* RNode){


	/*Here the PostOrder walk*/
	if(RNode->getLeft()!=NULL)
		DeletePostOrder(RNode->getLeft());
	if(RNode->getRight()!=NULL)
		DeletePostOrder(RNode->getRight());

	/* Delete the last node*/
	RNode->setLeft(NULL);
	RNode->setRight(NULL);
	RNode->setParent(NULL);
	delete RNode;

}

template<typename T>
BinaryNode<T>::BinaryNode(){

	/*Setting everything to null*/
	Parent	=	NULL;
	Left	=	NULL;
	Right	=	NULL;

}


template<typename T>
BinaryNode<T>::BinaryNode(int key, T NPayload){

	/*Setting everything to null*/
	NKey  	=   key;
	Payload	=  NPayload;
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
void BinaryNode<T>::setLeft(BinaryNode<T>* NNode){

	Left = NNode;
}

template<typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* NNode){

	Right = NNode;
}

template<typename T>
void BinaryNode<T>::setParent(BinaryNode<T>* NNode){

	Parent = NNode;
}


template<typename T>
void BinaryTree<T>::PostOrder(){

		if (Root!=NULL)
			PPostOrder(Root);
}

template<typename T>
void BinaryTree<T>::PPostOrder(BinaryNode<T>* RNode){

	/*Here the inorder walk*/
	if(RNode->getLeft()!=NULL) // Going Left
			PPostOrder(RNode->getLeft());
	if(RNode->getRight()!=NULL) // Going Right
			PPostOrder(RNode->getRight());

	/*Print Key*/
	std:cout<<RNode->getKey()<<" ";

}

template<typename T>
void BinaryTree<T>::PreOrder(){
	if (Root!=NULL)
		PPreOrder(Root);
}

template<typename T>
void BinaryTree<T>::PPreOrder(BinaryNode<T>* RNode){

	/*Print Key*/
		std:cout<<RNode->getKey()<<" ";

	/*Here the inorder walk*/
	if(RNode->getLeft()!=NULL) // Going Left
			PPreOrder(RNode->getLeft());
	if(RNode->getRight()!=NULL) // Going Right
			PPreOrder(RNode->getRight());
}

template<typename T>
void BinaryTree<T>::InOrder(){
	if (Root!=NULL)
		PInOrder(Root);
}

template<typename T>
void BinaryTree<T>::PInOrder(BinaryNode<T>* RNode){

	/*Here the inorder walk*/
	if(RNode->getLeft()!=NULL) // Going Left
			PInOrder(RNode->getLeft());

	/*Print Key*/
			std:cout<<RNode->getKey()<<" ";

	if(RNode->getRight()!=NULL) // Going Right
			PInOrder(RNode->getRight());
}

template<typename T>
void BinaryTree<T>::insert(int Key, T Payload){

	BinaryNode<T>* RNode = Root;	// Start at the Root
	BinaryNode<T>* PNode;					// Trailing Behind
	BinaryNode<T>* NNode = new BinaryNode<T>(Key,Payload);					// NewNode
	std::random_device rd;
	std::mt19937 gen{rd()};
	std::bernoulli_distribution coin_flip(0.5);
	bool alpha;										// Random decision

	/*Going down the tree Randomly
		Two cases:
		1.- Empty Tree
		2.- Non Empty Tree
	*/


	if (T_size == 0){

			Root = new BinaryNode<T>(Key,Payload);

			T_size++;

	}else{

		while(RNode!=NULL){

			alpha = coin_flip(gen);

			/*Taking Random decion from left to right*/
			if (alpha){
				PNode = RNode;
				RNode = RNode->getLeft();
			}else{
				PNode = RNode;
				RNode = RNode->getRight();
			}

		}

		// Insert at the Left or Right
		if (PNode->getRight()==NULL){
				PNode->setRight(NNode);
				NNode->setParent(PNode);
			}else{
				PNode->setLeft(NNode);
				NNode->setParent(PNode);
			}

			/* Increase the counter */
			T_size++;
		}

}


/* Delete function
      - using a key
*/
template<typename T>
T BinaryTree<T>::deleteNode(int key){

	// Calling Secondary Node
	if (Root!=NULL){
			return delNodePOrder(Root, key);
	}else{
			return (T)0;
	}
}

/* The Post Order Delete Auxiliary Function */
template<typename T>
T BinaryTree<T>::delNodePOrder(BinaryNode<T>* RNode, int key){

	/* The variables for testing */
	T Temp1, Temp2;

	Temp1 = (T)0;
  Temp2 = (T)0;

	if (RNode != NULL){

		/*Here the inorder walk*/
		if(RNode->getLeft()!=NULL) // Going Left
				Temp1 = delNodePOrder(RNode->getLeft(), key);
		if(RNode->getRight()!=NULL) // Going Right
				Temp2 = delNodePOrder(RNode->getRight(),key);

		/* The Visiting using the Tree Delete */
		if (Temp1!=(T)0){
		 	return Temp1;
		}else if (Temp2!=(T)0){
		 	return Temp2;
		} else if (RNode->getKey()==key) {
				return Tree_Delete(RNode);
			}
	} else{
		return (T)0;
	}
}

/* Tree Delete Node
	 The Procedure is defined in the Cormen
*/
template<typename T>
T BinaryTree<T>::Tree_Delete(BinaryNode<T>* RNode){

	/* Pointer to the Minimum */
	BinaryNode<T>* yNode;
	/* Pointer to Parents */
	BinaryNode<T>* Parent;
	/* The value to be returned */
	T Temp;

	/*
		Case 1: There are no children
		Case 2: The Left Node is empty
		Case 3: The Right Node is empty
		case 4: Non of them are empty
	*/
			if (RNode->getLeft() == NULL && RNode->getRight() == NULL){
					   Parent = RNode->getParent();
						 if (Parent->getLeft() == RNode){
						  			Parent->setLeft(NULL);}
						 else { Parent->setRight(NULL);}
			}else if (RNode->getLeft() == NULL){ // Case 1
						Transplant(RNode, RNode->getRight());
			}else if  (RNode->getRight() == NULL) { // Case 2
						Transplant(RNode, RNode->getLeft());
			}else { // Case 3
					yNode = Tree_Minimum(RNode->getRight());

					if (yNode->getParent()!=RNode){
						 Transplant(yNode, yNode->getRight());
						 yNode->setRight(RNode->getRight());
						 (yNode->getRight())->setParent(yNode);
					}
					Transplant(RNode, yNode);
					yNode->setLeft(RNode->getLeft());
					(yNode->getLeft())->setParent(yNode);
			}

			/* Get Payload */
			Temp = RNode->getData();
			//std::cout<<Temp<<"\n";

			/* Delete Node */
			RNode->setLeft(NULL);
			RNode->setRight(NULL);
			RNode->setParent(NULL);

			delete RNode;

			/* Decrease counte T_size */
			T_size--;

			// Return Data
			return Temp;

}


/* Tree-Minimum Function*/
template<typename T>
BinaryNode<T>* BinaryTree<T>::Tree_Minimum(BinaryNode<T>* RNode){

		/* Looping Down */
		while (RNode->getLeft()!=NULL){
				RNode = RNode->getLeft();
		}
	 	return RNode;
}

/* Transplant Function */
template<typename T>
void BinaryTree<T>::Transplant(BinaryNode<T>* u, BinaryNode<T>* v){

		if (u->getParent() == NULL){
				/* Re-assign ptr Root */
				Root = v;

		} else if (u == (u->getParent())->getLeft()){

				(u->getParent())->setLeft(v);

		} else {
				(u->getParent())->setRight(v);
		}

		if (v !=NULL)
				v->setParent(u->getParent());

}

template<typename T>
T BinaryTree<T>::search(int key){

	if (Root!=NULL){
		return searchPOrder(Root, key);
	}else {
		return (T)0;
	}

}
template<typename T>
T BinaryTree<T>::searchPOrder(BinaryNode<T>* RNode, int key){

	/* The variables for testing */
	T Temp1, Temp2;

	Temp1 = (T)0;
	Temp2 = (T)0;

	/*Here the inorder walk*/
	if(RNode->getLeft()!=NULL) // Going Left
			Temp1 = searchPOrder(RNode->getLeft(), key);
	if(RNode->getRight()!=NULL) // Going Right
			Temp2 = searchPOrder(RNode->getRight(),key);

	/* The Visiting using the Tree Delete */
	if (Temp1!=(T)0){
		 return Temp1;
	}else if (Temp2!=(T)0){
		 return Temp2;
	} else {
			if (RNode->getKey()==key){
					return RNode->getData();
			} else
					return (T)0;
		}

}
