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
#include <stdlib.h>
#include <limits.h>
#include "cmerge_sort.h"

void merge_sort(int *arr, int lower, int upper){
    int q;

    // Stoping Criteria
    if(lower<upper){
        q = (lower+upper)/2;
        // Divide part
        merge_sort(arr, lower, q);
        merge_sort(arr, q+1, upper);
        // Conquer part
        merge(arr, lower, q, upper);
    }
}

void merge_sort_inplace(int *arr, int lower, int upper){
    int q;

    // Stoping Criteria
    if(lower<upper){
        q = (lower+upper)/2;
        // Divide part
        merge_sort_inplace(arr, lower, q);
        merge_sort_inplace(arr, q+1, upper);
        // Conquer part
        merge_inplace(arr, lower, q, upper);
    }
}

void merge(int *arr, int low, int q, int high){
    int *L,*R;
    int i, j , k, n1, n2; 

    n1 = q-low+1;
    n2 = high-q;

    L = (int *)malloc(sizeof(int) * (n1+1));
    R = (int *)malloc(sizeof(int) * (n2+1));

    for(i=0; i<n1; i++){
        L[i] = arr[low+i];
    }

    for(j=0; j<n2; j++){
        R[j] = arr[q+j+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i = 0;
    j = 0;

    for(k=low; k<high+1; k++){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}

void merge_inplace(int *arr, int low, int q, int high){
    // variables merge in place
    int mid, mfront, temp;

    // init indexes defining right borders
    mid = q+1;

    // Everything is sorted
    if (arr[q] < arr[mid]) return;

    // In the case they are not sorted
    // ---------------------------- 
    // | low ... p | p+1 ... high |
    // ----------------------------
    //    i           j
    // Case 1
    // if  A[i] <= A[j] Then ?
    // Case 2 
    // if  A[j] <= A[i] Then we are less 
    // than anybody else between low and p 
    // Use this to obtain explanation and 
    // the other stuff
    while( low <= q && mid <= high){
        if (arr[low] <= arr[mid]) {
            low++;
        }
        else {
            temp = arr[mid];
            mfront = mid; 
            while( mfront != low){
                arr[mfront] = arr[mfront-1];
                mfront--;
            }
            arr[low] = temp;
            low++;
            mid++;
            q++;
        }
    }
}

