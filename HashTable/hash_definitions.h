
/* This is start of the header guard. 
 It can be any unique name. By convention, 
 we use the name of the header file.*/

#ifndef HASH_DEFINITIONS_H
#define HASH_DEFINITIONS_H

#include <string>

/*Constant definitions*/

#define MASK_W 0x00000000FFFFFFFF	// Mask with 32's ones in the first 64 bits
#define VALUE_A 6949403070 			// Knuth's integer representation
#define SWORD 32 					// Size of the words
 	  

/* The Node Structure of the Chain List for the Hash*/
typedef struct  Node
{
	/* The integer key*/
	int m_key;
	std::string m_payload;
	/* The Next Node */
	struct Node* m_Next;
}Node;

/* The List Structure for the Buckets*/
typedef struct Chain_List
{
	/* Size of the Chain List */
	int m_List_Size;
	/* First Node in the Chain List*/
	Node* m_First_Node;
}Chain_List;

/* HashTable Class using chain list*/
class HashTable{
protected:
		/*Data Members*/
		Chain_List** m_Table;	   		// Ptr to Array for Hash Table

		/* Variables for the multiplication method*/
		int m_m;						// Size of the Hash Table
		int m_selec;					// Selection of hash function
		int m_s;						// The right shift
		int m_p;                		// Bits to be extraccted
		int size_T;						// Numbers in the hash table

		/* Testing the Power of Two */
		bool PosPowerOfTwo(int m);
		  
	public:
		/* Constructors */
		/* A Constructior with a selection for the hash_function:	*/
		/* 1.-  Multiplication Method 								*/
		/* 2.-  Universal Hashing Based Matrix Method				*/
		HashTable(int m, int Selection);
		/* Destructor */
		~HashTable();
		/* Operations in the link lists */
		/* Insert payload string in the correct bucket */
		void h_insert(int key, std::string payload);
		/* Delete a node in the correct list by using the key*/
		std::string h_delete(int key);
		/* Search for a payload with a specific key*/
		std::string h_search(int key); 

		/* The Hash function */
		int h_function(int key);

		/* Print in file the size of each Chain List*/
		void print_size_chain(std::string name);

		/*Get the size of the hash table*/
		int size();

};

 // This is the end of the header guard
#endif