#ifndef HEAP_FILE
#define HEAP_FILE

/*
 * maxheapify
 * 
 * @param arr pointer to array of int
 * 
 * @param n size of the array
 * 
 * @return void
 * 
 */
static void max_heapify( int *arr, int i, int hs);

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
static void min_heapify( int *arr, int i, int hs);

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
static void build_max_heap(int *arr, int len);

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
static void build_min_heap(int *arr, int len);



#endif
