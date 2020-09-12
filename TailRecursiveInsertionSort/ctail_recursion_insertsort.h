#ifndef TAIL_RECURSION_INSERTIONSORT_FILE
#define TAIL_RECURSION_INSERTIONSORT_FILE
/*Tail recursion based insertion sort definition*/

/*
 * Recursive insertion sort
 * 
 * @param arr pointer to array of int
 * 
 * @param n size of the array
 * 
 * @return void
 * 
 */
void crec_insertionsort( int *arr, int n);
/*
 * Helper function
 * 
 * @param arr pointer to array of int
 * 
 * @param i index of the key to be inserted
 * 
 * @param n size of the array
 * 
 * @return void
 * 
 */
void helper( int *arr, int i, int n);

/*
 * Tail recursive go function
 * 
 * @param arr pointer to array of int
 * 
 * @param n size of the array
 * 
 * @return void
 * 
 */
void go( int *arr, int key, int j);

#endif