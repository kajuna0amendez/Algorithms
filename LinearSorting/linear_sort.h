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
#ifndef LINEAR_SORT_FILE
#define LINEAR_SORT_FILE

struct NodeQ{
    int number;
    struct NodeQ *next;
};



/*
 * counting sort 
 * Note: You are limited by the range k
 * 
 * @param arr array of integers to be sorted limited by a range k
 * 
 * @param n number of elements on arr
 * 
 * @return NA
 * 
*/
void counting_sort(int *arr, int n);



/*
 * radix sort table 
 * 
 * @param arr array of integers to be sorted limited by a range k
 * 
 * @param n number of elements on arr
 * 
 * @return NA
 * 
*/
void radix_sort_table(int *arr, int n);

/*
 * radix sort queues 
 * 
 * @param arr array of integers to be sorted limited by a range k
 * 
 * @param n number of elements on arr
 * 
 * @return NA
 * 
*/
void radix_sort_queue(int *arr, int n);


/*
 * bucket sort 
 * 
 * @param arr array of integers to be sorted limited by a range k
 * 
 * @param n number of elements on arr
 * 
 * @return NA
 * 
*/
void bucket_sort(int *arr, int n);


#endif