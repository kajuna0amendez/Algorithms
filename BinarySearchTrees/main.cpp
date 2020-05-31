/*Standard Setup*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;



int main(){
	/* Temp variables for swap */
	int swap, rand1;

	/* Basic Variables for inserting the first node */
	int key1 = 100;
	float Payload1 = 1.34;

	/* The Randomized integer */
	int RN[NNODES+1];

	/* Generate the Binary Search Tree */
	BinarySearchTree<float> Tree1;
	//BinarySearchTree<float> Tree1(key1,Payload1);

	/*initialize random seed: */
  srand (time(NULL));

	for(int i=1;i<=NNODES;i++)
			RN[i] = i;

	/* Inserting randomly in the tree */
	for (int i = 1; i<=NNODES ; i++){
			rand1 = rand()%(NNODES-i+1)+i;
			swap = RN[rand1];
			RN[rand1] = RN[i];
			RN[i] = swap;
	}


	for (int i = 1; i<=NNODES ; i++)
		Tree1.insert(RN[i], (float)i);

	Tree1.PreOrder();
	std::cout<<"\n";
	Tree1.InOrder();
	std::cout<<"\n";

	for (int i = 1; i<=10 ; i++)
		std::cout<< std::fixed << std::setprecision(1)<<Tree1.deleteNode(i) <<" ";

	std::cout<<"\n";

	Tree1.PreOrder();
	std::cout<<"\n";
	Tree1.InOrder();
	std::cout<<"\n";

	Tree1.PreOrder();

	std::cout<<"\n";

	for (int i = 11; i<20 ; i++)
			std::cout<< std::fixed << std::setprecision(1)<<Tree1.search(i) <<" ";

	std::cout<<"\n";


	Tree1.PreOrder();
	std::cout<<"\n";
	Tree1.InOrder();
	std::cout<<"\n";

	return 0;
}
