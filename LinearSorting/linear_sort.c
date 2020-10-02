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
#include <math.h>
#include <limits.h>
#include "linear_sort.h"
 

void counting_sort(int *arr, int n){

    // Local Variables
    int i;
    int k;
    int *B, *C;

    // Generate the sorted array
    C = (int*) malloc(sizeof(int)*(n));

    // Get the range of the values in arr
    k = arr[0];
    for (i = 1; i < n; i++){
        if (k < arr[i]){
            k = arr[i];
        }
    }

    // Generate the array from 0 to k
    B = (int*) malloc(sizeof(int)*(k+1));

    // init to zeros B
    for(i = 0; i < k+1; i++){
        B[i] = 0;
    }

    // Add the counter of each repeated elements
    for (i = 0; i < n; i++){
        B[arr[i]]++;
    }

    // Generate Histogram
    for(i = 1; i < k+1; i++){
        B[i] = B[i]+B[i-1];
    }

    // Generate the sorted array
    for(i = n-1; i > -1; i--){
        C[B[arr[i]]-1] = arr[i];
        B[arr[i]]--;
    }

    for (i = 0 ; i < n ; i++){
        arr[i] = C[i];
    }

    free(B);
    free(C);
}


void radix_sort_table(int *arr, int n){

    int i, j;
    int p1, p2;
    int maxv, brval;
    unsigned int mask;
    // Only two bits
    int order[2];
    int *temp;

    // indexation for the binary sorting
    temp = (int*) malloc(n*sizeof(int));

    order[0] = 0;
    order[1] = 0;
    p1 = 0;
    p2 = 1;
    
    
    maxv = arr[0];
    for (i = 1; i < n; i++){
        if (maxv < arr[i]){
            maxv = arr[i];
        }
    }

    brval = (int)ceil(log2((double)maxv));
    

    //column by column
    for (i = 0; i < sizeof(int)*CHAR_BIT; i++){

        if (i>brval){
            i = sizeof(int)*CHAR_BIT - 1;
        }

        //Example 1 << 2 = 0100 Then 0100 & 1111 = 0100  
        mask = 1 << i;
        
        // Get a 1 or 0 bit
        for (j = 0; j < n ; j++){
            if (mask & arr[j]){
                order[p2]++;
            } else{
                order[p1]++;
            } 
        }
        // The accumulative part
        if ( i != sizeof(int)*CHAR_BIT-1){
            order[p2] += order[p1] ;
        } else {
            order[p1] += order[p2] ;
        }

        for (j = n-1; j >  -1; j--){
            if (mask & arr[j]){
                temp[order[p2]-1] = arr[j];
                order[p2]--;
            } else {
                temp[order[p1]-1] = arr[j];
                order[p1]--;
            }
        }
        for (j = 0; j < n; j++){
            arr[j] = temp[j];
        }
        // Clean the buffers
        order[0] = 0;
        order[1] = 0;
    }
    

    free(temp);
}


void radix_sort_queue(int *arr, int n){
    int i;
    int p1, p2;
    unsigned int mask;
    struct NodeQ *Temp, *order[2], *top, *bottom[2];
    
    // Init the queues
    order[0] = NULL;
    order[1] = NULL;
    top = NULL;

    for ( i = n-1 ; i > -1 ; i--){
        Temp = (struct NodeQ*) malloc(sizeof(struct NodeQ));
        Temp->next = NULL;
        Temp->number = arr[i];
        if (top == NULL){
            top = Temp;
        } else {
            Temp->next = top;
            top = Temp;
        }
    }

    p1 = 0;
    p2 = 1;

    //column by column
    for (i = 0; i < sizeof(int)*CHAR_BIT ; i++){
        mask = 1 << i;

        // Queue Section
        while (top != NULL){
            if (mask & top->number){
                if (order[p2] == NULL){
                    order[p2] = top;
                    top = top->next;
                    order[p2]->next = NULL;
                    bottom[p2] = order[p2];
                } else {
                    bottom[p2]->next = top;
                    top = top->next;
                    bottom[p2] = bottom[p2]->next;
                    bottom[p2]->next = NULL; 
                }
            } else {
                if (order[p1] == NULL){
                    order[p1] = top;
                    top = top->next;
                    order[p1]->next = NULL;
                    bottom[p1] = order[p1];
                } else {
                    order[p1]->next = top;
                    top->next = order[p1]; 
                    bottom[p2]->next = top;
                    top = top->next;
                    bottom[p2] = bottom[p2]->next;
                    bottom[p2]->next = NULL; 
                }

            }
        }
        // The accumulative part
        if ( i != sizeof(int)*CHAR_BIT-1){
            top = order[p1];
            bottom[p1]->next = order[p2]; 
        } else {
            top = order[p2];
            bottom[p2]->next = order[p1]; 
        }

        order[p1] = NULL;
        order[p2] = NULL;
        
    }

    i = 0;
    // free sorted list
    while (top != NULL){
        arr[i] = top->number;
        i++;
        Temp = top;
        top = top->next;
        free(Temp);
    }


    free(Temp);
    free(bottom[2]);

}


void bucket_sort(int *arr, int n){

    //This needs to be implemented by student
    
}
