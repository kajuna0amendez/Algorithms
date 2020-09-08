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
#ifndef MERGE_SORT_FILE
#define MERGE_SORT_FILE

/* Mergesort Defintions */

/*
 * The recursive part of the mergesort 
 * 
 * @param arr array of integers with the data of 
 * 
 * @param lower index of arr
 * 
 * @param upper index of arr
 * 
 * @return NA
 * 
*/
void merge_sort(int *arr, int lower, int upper);



/*
 * The merge part of the mergesort 
 * 
 * @param arr array of integers with the data of 
 * 
 * @param low index of arr
 * 
 * @param high index of arr
 * 
 * @return NA
 * 
*/
void merge(int *arr, int low, int q, int high);

/*
 * The merge in place 
 * 
 * @param arr array of integers with the data of 
 * 
 * @param low index of arr
 * 
 * @param high index of arr
 * 
 */
void merge_inplace(int *arr, int low, int q, int high);


#endif