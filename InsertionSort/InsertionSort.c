// InsertioSort.c

#include <stdio.h>
#include "InsertionSort.h"


void InsertionSort( int *arr, int n){
    int i, j, key;

    // External loop for the sorted part
    for(i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        // Making space for insertion
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        // inserting the element
        arr[j+1] = key;

        for(j=0; j<n; j++){
            printf("%i ", arr[j]);
        }
        printf("\n");
    }
}