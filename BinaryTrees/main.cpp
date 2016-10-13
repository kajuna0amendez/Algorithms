/*Standard Setup*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "BinaryTree.h"

using namespace std;



int main(){
	int key1 = 100;
	float Payload1 = 1.34;

	BinaryTree<float> Tree1;
	//BinaryTree<float> Tree1(key1,Payload1);

	for (int i = 1; i<NNODES ; i++)
		Tree1.insert(i, (float)i);

	Tree1.PreOrder();
	std::cout<<"\n";
	Tree1.InOrder();
	std::cout<<"\n";

	for (int i = 1; i<RNODES ; i++)
		std::cout<< std::fixed << std::setprecision(1)<<Tree1.deleteNode(i) <<" ";

	std::cout<<"\n";

	Tree1.deleteNode(100);

	for (int i = 101; i<110 ; i++)
		std::cout<< std::fixed << std::setprecision(1)<<Tree1.deleteNode(i) <<" ";

	std::cout<<"\n";

	for (int i = 11; i<20 ; i=i+2)
		std::cout<< std::fixed << std::setprecision(1)<<Tree1.search(i) <<" ";

	std::cout<<"\n";

		Tree1.PreOrder();
		std::cout<<"\n";
		Tree1.InOrder();
		std::cout<<"\n";

	return 0;
}
