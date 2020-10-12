#ifndef PQUEUEHEAP_FILE
#define PQUEUEHEAP_FILE

#include "Process.h"
#include <stdbool.h>

// Structure for the node in the Queue
struct ProcessNode{
    struct Process elem;
    int key;
};


// Structure of the Priority Queue
struct PriorityQueue{
    struct ProcessNode *container;
    int hs;
    int len;
};


/*
 * swap xor function
 * 
 * @param a pointer to an integer
 * 
 * @param b pointer to an integer
 * 
 */
static void swap_xor(int *a, int *b);


/*
 * Init of the priority queue
 * 
 * @param ID pointer to array of integers
 * 
 * @param Quantas pointer to array of quantas
 * 
 */
struct PriorityQueue* init_priority_queue(int *IDs, int *Quantas, int len, int hs, bool min_max);


/*
 * maxheapify
 * 
 * @param arr pointer to array of int
 * 
 * @param hs heap size
 * 
 * @oaram len len of container
 * 
 * @return void
 * 
 */
void max_heapify(struct PriorityQueue *arr, int i);


/*
 * minheapify
 * 
 * @param arr pointer to array of int
 * 
 * @param n size of the array
 * 
 * @return void
 * 
 */
void min_heapify(struct PriorityQueue *arr, int i);



/*
 * left child index
 * 
 * @param i index of father
 * 
 * @return index of left child
 * 
 */
static int _left_child(int i);

/*
 * left child index
 * 
 * @param i index of child
 * 
 * @return index of left child
 * 
 */
static int _parent(int i);



/*
 * left child index
 * 
 * @param i index of father
 * 
 * @return index of right child
 * 
 */
static int _right_child(int i);

/*
 * Build max heap
 * 
 * @param arr array for the container
 * 
 * @param hs heap size
 * 
 * @oaram len len of container
 * 
 * @return void
 * 
 */
void build_max_heap(struct PriorityQueue *arr);

/*
 * Build min heap
 * 
 * @param arr array for the container
 * 
 * @param hs heap size
 * 
 * @oaram len len of container
 * 
 * @return void
 * 
 */
static void build_min_heap(struct PriorityQueue *arr);


/*
 * Heap Decrease Key  
 * 
 * @param arr array container
 * 
 * @param i element in the array
 * 
 * @param key on the element
 * 
 */
void heap_increase_key(struct PriorityQueue *arr, int i, int key);


/*
 * Insert key minimum
 * 
 * @param arr array for the container
 * 
 * @param hs heap size
 * 
 * @oaram len len of container
 * 
 * @return void
 * 
 */
void max_insert(struct PriorityQueue *arr, int key);

/*
 * Return minimum key
 * 
 * @param arr array for the container
 * 
 * @return void
 * 
 */
int maximum(struct PriorityQueue *arr);

/*
 * Extract minimum 
 * 
 * @param arr array for the container
 * 
 * @return void
 * 
 */
 struct ProcessNode extract_maximum(struct PriorityQueue *arr);


/*
 * Heap Decrease Key  
 * 
 * @param arr array container
 * 
 * @param i element in the array
 * 
 * @param key on the element
 * 
 */
void heap_decrease_key(struct PriorityQueue *arr, int i, int key);


/*
 * Insert key minimum
 * 
 * @param arr array for the container
 * 
 * @param hs heap size
 * 
 * @oaram len len of container
 * 
 * @return void
 * 
 */
void min_insert(struct PriorityQueue *arr, int key);

/*
 * Return minimum key
 * 
 * @param arr array for the container
 * 
 * @return void
 * 
 */
int minimum(struct PriorityQueue *arr);

/*
 * Extract minimum 
 * 
 * @param arr array for the container
 * 
 * @return void
 * 
 */
struct ProcessNode extract_minimum(struct PriorityQueue *arr);


#endif