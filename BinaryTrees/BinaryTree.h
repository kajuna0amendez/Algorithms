#ifndef BINARY_TREE_H
#define BINARY_TREE_H

using namespace std;

#define NNODES 20
#define RNODES 10

template <typename T>
class BinaryNode{

protected:
	int NKey;
	T Payload;
	BinaryNode* Right;
	BinaryNode* Left;
	BinaryNode* Parent;

public:
	// Constructor
	BinaryNode();
	BinaryNode(int key, T Payload);

	// Destructor
	~BinaryNode();

	// Get Operations
	int getKey();
	T getData();

	BinaryNode<T>* getLeft();

	BinaryNode<T>* getRight();

	BinaryNode<T>* getParent();


	// Set Operations
	void setKey(int key);

	void setData(T Payload);

	void setLeft(BinaryNode<T> *NNode);

	void setRight(BinaryNode<T> *NNode);

	void setParent(BinaryNode<T> *NNode);

};


template <typename T>
class BinaryTree{

protected:
		/*Data Members*/
		BinaryNode<T>* Root;
		int T_size;

		/* Protected Delete Function Using a Post Order Walk*/
		void DeletePostOrder(BinaryNode<T>* RNode); // Delete using PostOrder Walk

		/* The Recursive Walks Passing the Nodes for the Walk */
		void PPostOrder(BinaryNode<T>* RNode);
		void PPreOrder(BinaryNode<T>* RNode);
		void PInOrder(BinaryNode<T>* RNode);

		/* Delete a Node by Post Walking around to find the key */
		T delNodePOrder(BinaryNode<T>* RNode, int key);
		/*Using a transplant function for moving tree nodes around
			Look at Cormen Binary Trees for more on it*/
		void Transplant(BinaryNode<T>* u, BinaryNode<T>* v);

		/* Deletion in a Tree */
		T Tree_Delete(BinaryNode<T>* RNode);

		/* Tree-Minimum Function*/
		BinaryNode<T>* Tree_Minimum(BinaryNode<T>* RNode);

		/* Search Using Post Order Walk */
		T searchPOrder(BinaryNode<T>* RNode, int key);

public:
		/* Constructors */
		BinaryTree();
		BinaryTree(int key, T Payload);	// Default

		~BinaryTree();					// Destructor using Post Order Walk*/


		/* Walking Operations */

		void PostOrder();

		void PreOrder();

		void InOrder();

		/* Insert and Delete Operations */
		virtual void insert(int key, T Payload); // at the bottom of the tree randomly

		virtual T deleteNode(int key); // Search Using Preorder Walk

		virtual T search(int key);

};

#include "BinaryTree.cpp"

#endif	/* BINARY_TREE_H */
