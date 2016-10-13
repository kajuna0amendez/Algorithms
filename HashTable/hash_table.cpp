
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
/* Hahs Table definitions */ 
#include "hash_definitions.h"

using std::cout;

/* The Methods of HahsTable */

/* Construct Function */
HashTable::HashTable(int m, int Selection){


	/* Variables for the multiplication method*/
    int tm;

	/*Look if the user has provided a power of two size*/
	if (!PosPowerOfTwo(m)){
		std:cout<< "You have not provide a power of two size";
		return;
	}

    /* Init the storage */
	m_Table = new Chain_List*[m];
	m_m = m;
	size_T =0;
	
	
	for(int i=0; i < m; i++){
		m_Table[i] = new Chain_List; 
		m_Table[i]-> m_List_Size = 0;
		m_Table[i]-> m_First_Node = NULL;
	}

	/* Selecting the hash function */
	switch(Selection){
			case 1: // The Multiplication Method
				/* the choice */
				m_selec = Selection;	
			
				/*Find p*/
				tm = m;
				m_p=0;
				while(tm!=0){
					tm = tm>>1;
					m_p++;
				}
				m_p = m_p-1;
				
				std::cout<< "Multiplication Method\n";
				break;
			case 2: // The Unviversal Matrix Method
				std::cout<< "Matrix Method";
				break;
			default: // Default Execution
				std::cout<< "Incorrect Hash Function\n";
				break;

	} 

}

/* Destruct Function */ 
HashTable::~HashTable(){
	/* Pointer for destroying */
	Node* temp;
	/* Destroys every chain */
	for(int i=0; i<m_m; i++){
		while (m_Table[i]->  m_First_Node!=NULL){
			temp = m_Table[i]-> m_First_Node;
			m_Table[i]-> m_First_Node = (m_Table[i]-> m_First_Node) -> m_Next;
			delete temp;
		} 
	}
	/* Delete array of chains */
	delete[] m_Table;
}

/* Function to test if something is power of two */
bool HashTable::PosPowerOfTwo(int m){

	/* This is a simple idea 
	   Example
	   		1000 -> 1000-1 = 0111 Thus
	   		1000 & 0111 = 0000	*/

	return (m!=0) && ((m&(m-1))==0);
}

/* The Hash Function */
int HashTable::h_function(int key){

	unsigned long long result;
	unsigned int index ;

	switch(m_selec){
		case 1:
			/*
			1.- Get the two word multiplication
			2.- remove the upper 32 bits 
			3.- shift to the right to get the p bits				
			*/
			result = key*VALUE_A;
			index = (int) ( (result & MASK_W) >> (SWORD-m_p));
			return index;
			break;
		case 2:
			break;
		default: // Default Execution
				std::cout<< "Incorrect Hash Function\n";
				break; 
	}

	
}

/* The Insertion in the hash function */
void HashTable::h_insert(int key, std::string payload){

	int index;
	Node* NNode;

	index = h_function(key);

	/* Two Cases empty chain non empty chain*/
	if (m_Table[index]-> m_First_Node==NULL){
		/* Generate space in the heap and assign values*/
		m_Table[index]-> m_First_Node = new Node;
		(m_Table[index]->m_First_Node)->m_key = key;
		(m_Table[index]->m_First_Node)->m_payload = payload;
		(m_Table[index]->m_First_Node)->m_Next = NULL;
		m_Table[index]-> m_List_Size = 1;
		size_T++;
	} else{
		/* Generate space in the heap and assign values*/
		NNode = new Node;
		NNode-> m_key = key;
		NNode-> m_payload = payload;
		NNode->m_Next = m_Table[index]->m_First_Node;
		/*Move the first node*/
		m_Table[index]->m_First_Node = NNode;
		m_Table[index]-> m_List_Size++;
		size_T++;
	}

}

/* Search Function */
std::string  HashTable::h_search(int key){

	/* Variable for Search*/
	int index;
	Node* NNode;

	/* Get the hash*/
	index = h_function(key);

	/* Go to the first node of the chain list*/
	NNode = m_Table[index]->m_First_Node;

	/* Scan  through the list*/
	while (NNode!=NULL){

		if (NNode->m_key == key){
			return NNode-> m_payload;
		}else{
			NNode = NNode->m_Next;
		}
		
	}

	/*If the key does not exist*/
	//std::cout<<"The Key does not exist";
	return std::string();
}

std::string HashTable::h_delete(int key){

	/* Variable for Deletion*/
	int index;
	Node* NNode;
	Node* PNode;
	std::string rtemp; 

	/* For the two cases delete the front node
	   or deleting in the middle
	*/
	PNode = NULL;

	/* Get the hash*/
	index = h_function(key);

	/* Go to the first node of the chain list*/
	NNode = m_Table[index]->m_First_Node;

	/* Scan  through the list*/
	while (NNode!=NULL){

		if (NNode->m_key == key){
			/*The Different Cases*/
			if (PNode==NULL){
				/*
				Here, we are at the beginnign of the chain list
				Thus remove First -> Second ->... the first node
				*/
				rtemp = NNode->m_payload; // Get the payload
				PNode = NNode;			  // Node to be removed
				m_Table[index]->m_First_Node = NNode->m_Next; //move pointer
				/* Remove the first node */
				PNode->m_Next = NULL;     
				delete PNode;
				/*Decrease the sizes*/
				m_Table[index]-> m_List_Size--;
				size_T--;
				return rtemp;
			} else{
				/*
				Here, we are at the beginnign of the chain list
				Thus remove the intermediate node using the previous
				node and the current node
				*/
				rtemp = NNode->m_payload;		// Get the payload
				PNode->m_Next = NNode->m_Next;	// Point the prev.next to curr.next
				/* Remove the first node */
				NNode->m_Next = NULL; 
				delete NNode;
				m_Table[index]-> m_List_Size--;
				size_T--;
				return rtemp;
			}
		}else{

			PNode = NNode;
			NNode = NNode->m_Next;
		}
		
	}

	/*If the key does not exist*/
	// std::cout<<"The Key does not exist";
	return std::string();
}

// Return the size
int HashTable::size(){
	return size_T;
}

void HashTable::print_size_chain(std::string name){
	
	std::fstream myfile;
	myfile.open(name.c_str(),std::fstream::out);

	for(int i=0; i < m_m; i++){
		myfile<<i<<" "<<m_Table[i]-> m_List_Size<<",";  
	}
	myfile.close();
	
}