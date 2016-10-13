/*Standard Setup*/

#include <iostream>
#include <string> 
#include <cstdlib>
#include <sstream>
#include "hash_definitions.h"


int main(){

	int m = 64;
	int nkey = 1000;
	int key;
	std::ostringstream os;
	std::string name("Exp1.txt");

	HashTable Table1(m,1);
	
	for (int i=0; i< nkey; i++){
		key = rand()%nkey;
		os<<key;
		//std::cout<< os.str() <<"\n";
		Table1.h_insert(key, std::string(os.str()));
		os.str("");	
	}
	std::cout<<"\n"<<"Size of the Hash_Table After Insertions= "<<Table1.size()<<"\n \n";

	/*for (int i=0; i< nkey; i++){
		key = rand()%nkey;
		Table1.h_delete(key);
		//std::cout<<Table1.h_search(key)<<"\n";
	}
	
	std::cout<<"Size of the Hash_Table After Deletions= "<<Table1.size()<<"\n \n";

	for (int i=0; i< nkey; i++){
		key = rand()%nkey;
		Table1.h_delete(key);
		//std::cout<<Table1.h_search(key)<<"\n";
	}*/
	
	Table1.print_size_chain(name);

	return 0;
}