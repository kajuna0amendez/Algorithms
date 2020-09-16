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
        merge_sort(arr, lower, q);
        merge_sort(arr, q+1, upper);
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
    int i, j, t;

    // init indexes defining right borders
    i = low;
    j = q+1;

    while(j < high){
        if(i < q+1){
            if (arr[i] > arr[j]) {
                // Xor Swap and increment i
                arr[i] = arr[i]^arr[j];
                arr[j] = arr[i]^arr[j];
                arr[i] = arr[i]^arr[j];
                i++;
                // An idea from insertion sort
                t = j;
                while (arr[t] > arr[t+1]){
                    // Xor Swap
                    arr[t] = arr[t]^arr[t+1];
                    arr[t+1] = arr[t]^arr[t+1];
                    arr[t] = arr[t]^arr[t+1];
                    t++;
                    if (t > high-1) break;
                }
            } else {
                // increment index i
                i++;
            }
           
        } else {
            j++;
            // Break to avoid index out of bound
            if(j>high-1) break;
            if (arr[i] > arr[j]){
                // Xor Swap
                arr[t] = arr[t]^arr[t+1];
                arr[t+1] = arr[t]^arr[t+1];
                arr[t] = arr[t]^arr[t+1];
                i++;
            } else i++;
        }
    }
}