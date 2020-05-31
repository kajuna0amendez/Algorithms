/*Standard Setup*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "AVLTree.h"

using namespace std;



int main(){

	/* Basic Variables for inserting the first node */
	int key1 = 100;
	float Payload1 = 1.34;


	/* Generate the Binary Search Tree */
	AVLTree<float> Tree1(key1,Payload1);


	return 0;
}
