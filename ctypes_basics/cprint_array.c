// cprint_array.c

#include <stdio.h>
#include "cprint_array.h"

void cprint_array(int *arr, int m){
    int i;
    for(i=0; i < m; i++){
        //arr[i] = 2*arr[i];
        printf("%i ", arr[i]);
    }
    printf("\n");
    
}