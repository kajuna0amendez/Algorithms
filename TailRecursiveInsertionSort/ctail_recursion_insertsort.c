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

#include <stdio.h>
#include "ctail_recursion_insertsort.h"

void crec_insertionsort(int *arr, int n){
    // Calling a helper
    helper(arr, 1, n);
}

void helper( int *arr, int i, int n){
    int key;
    // if i is less than n
    if(i < n){
        key = arr[i];
        //Tail Recursive Insertion
        go(arr, key, i-1);
        //Calling next level of insertion
        helper(arr, i+1, n);
    }
}

void go( int *arr, int key, int j){
    if(key >= arr[j] && j < 0){
        arr[j+1] = key;
    } else {
        arr[j+1] = arr[j];
        go(arr, key, j-1);
    }  
}
