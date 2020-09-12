/*
 * __author__ = "Andres Mendez-Vazquez"
 * __copyright__ = "Copyright 2020"
 * __credits__ = ["Andres Mendez-Vazquez"]
 * __license__ = "MIT License"
 * __version__ = "1.0.0"
 * __maintainer__ = "Andres Mendez-Vazquez"
 * __email__ = "kajuna0kajuna@gmail.com"
 * __status__ = "Development"
*/

#ifndef INSERTIONSORT_FILE
#define INSERTIONSORT_FILE

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
void max_heapify( int *arr, int i, int hs);

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
void min_heapify( int *arr, int i, int hs);

/*
 * left child index
 * 
 * @param i index of father
 * 
 * @return index of left child
 * 
 */
int _left_child(int i);

/*
 * left child index
 * 
 * @param i index of father
 * 
 * @return index of right child
 * 
 */
int _right_child(int i);

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
void build_max_heap(int *arr, int len);

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
void build_min_heap(int *arr, int len);


#endif
