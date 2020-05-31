#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <random>
#include "AVLTree.h"


/* Binary Search Tree definitions */
/*
	Do not include to avoid circular defintions when using templates
*/

using namespace std;

template<typename T>
void AVLNode<T>::setHeight(int value){
		height = value;
}

template<typename T>
int AVLNode<T>::getHeight(){
	 return height;
}

template <class T>
AVLTree<T>::AVLTree() {
	this->Root = new AVLNode<T>();
	this->T_size = 0;
}

template<typename T>
AVLTree<T>::AVLTree(int Key, T Payload){
	/* Generate Node*/
	this->Root   = new AVLNode<T>(Key,Payload);
	this->T_size = 1;
}

template<typename T>
void AVLTree<T>::insert(int key, T Payload){

	/* Create Node to be inserted */
	AVLNode<T> *NNode = new AVLNode<T>(key,Payload);

	/* The Search Pointers  */
	if (this->Root!=NULL){
				AVLNode<T> *RNode = this->Root;
				AVLNode<T> *PNode = NULL;


				if (this->T_size == 0){

						this->Root = new AVLNode<T>(key,Payload);

						this->T_size++;

				}else{

					while(RNode!=NULL){


						/* Moving downward taking decisions
							Case 1 <
							Case 2 >=
						*/
						if (RNode->getKey()>key){
							PNode = RNode;
							RNode-> setHeight(getHeight()++);
							RNode = RNode->getLeft();
						}else{
							PNode = RNode;
							RNode-> setHeight(getHeight()++);
							RNode = RNode->getRight();
						}

					}

					/* Insert the Node */
					if (PNode->getKey()>key){
							PNode->setLeft(NNode);
							PNode-> setHeight(getHeight()++);
							(PNode->getLeft())->setParent(PNode);
					}else{
							PNode->setRight(NNode);
							PNode-> setHeight(getHeight()++);
							(PNode->getRight())->setParent(PNode);
					}

					/* Increase the counter */
					this->T_size++;

				}
	}


}

template<typename T>
T AVLTree<T>::deleteNode(int key){

		return (T)0;
}

template<typename T>
AVLNode<T>* AVLTree<T>::LeftRotation(AVLNode<T> *XNode){

		/* The Rotation Operation
				Being the XNode at the top
				YNode at the Right

						XNode               YNode
          /     \              /    \
				A      YNode  ->    XNode
			/  \    /    \       /    \
			       B     	      A     B
		*/
		AVLNode<T> *YNode = XNode->Right;
		XNode->Right  = YNode->Left;
		YNode->Left   = XNode;
		/* Taking care of the pointer
		   going into XNode  */
		if ((XNode->Parent)->Left == XNode)
				(XNode->Parent)->Left = YNode;
	  else
				(XNode->Parent)->Right = YNode;
		/* Taking care of the parents for Tree_Minimum */
		YNode->Parent = XNode -> Parent;
		XNode->Parent = YNode;

		return YNode;
}

template<typename T>
AVLNode<T>* AVLTree<T>::RightRotation(AVLNode<T> *ZNode){

	/* The Rotation Operation
			Being the ZNode at the top
			YNode at the Left

					ZNode               YNode
				/     \              /    \
		YNode     B ->                ZNode
		/  \                         /   \
		   A			      	    		  A     B
	*/
	AVLNode<T> *YNode = ZNode->Left;
	ZNode->Left  = YNode->Right;
	YNode->Right   = ZNode;
	/* Taking care of the pointer
		 going into ZNode  */
	if ((ZNode->Parent)->Left == ZNode)
			(ZNode->Parent)->Left = YNode;
	else
			(ZNode->Parent)->Right = YNode;
	/* Taking care of the parents for Tree_Minimum */
	YNode->Parent = ZNode -> Parent;
	ZNode->Parent = YNode;

	return YNode;
}
