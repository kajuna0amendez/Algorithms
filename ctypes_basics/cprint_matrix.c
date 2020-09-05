// cprint_matrix.c

#include <stdio.h>
#include "cprint_array.h"

void cprint_matrix(int *arr, int m, int n){
    int i;
    for(i=0; i < m*n; i++){
        printf("%i ", arr[i]);
        if ((i+1)%m == 0){
            printf("\n");
        }
    }   
}