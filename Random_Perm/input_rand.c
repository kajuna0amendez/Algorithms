#include <time.h>
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include "input_rand.h"


void permute_by_sorting( int *arr, int n){

    /* Local Variables */
    int i, key1, key2;
    time_t t;
    int *perm;

    // Get space in heap space
    perm = (int *)malloc(sizeof(int) * n);

    /* Init the random seed for rng*/
    srand((unsigned) time(&t));

    /* Ge the random permutation*/
    for(i=0; i<n; i++){
        perm[i] = rand() % n ; // Use module to avoid getting out of the index
    }

    // Here calculate the sum of 0+1+...+n-1

    /* Sorting by the permutation*/
    for(i=0; i<n; i++){
        key1 = arr[i];
        key2 = arr[perm[i]];

        arr[perm[i]] = key1;
        arr[i] = key2;
    }

    // Look at the sum of the number to compare with 0+1+...+n-1

    // Delete the memory used in malloc
    free(perm);
}


void permute_in_place( int *arr, int n){
    // implement the Randomize in place
    /* Local variables */
    int i;
    time_t t;
    int *perm;

    // Get space in heap space
    perm = (int *)malloc(sizeof(int) * n);

    /* Init the random seed for rng*/
    srand((unsigned) time(&t));

    for(i=0; i<n; i++){
        // How do you do it?
    }

    // Delete the memory used in malloc
    free(perm);

}