// heap.c

#include <stdio.h>
#include "cheap.h"


void max_heapify( int *arr, int i, int hs){

    int l, r, largest;

    // get indexes
    l = _left_child(i);
    r = _right_child(i);

    // Test largest left
    if (l <= hs && arr[l] > arr[i]) largest = l; else largest = i;

    // Test largest right
    if (r <= hs && arr[r] > arr[largest]) largest = r;

    // Call recursion
    if (largest != i){
        // Xor Swap
        arr[i] = arr[i]^arr[largest];
        arr[largest] = arr[i]^arr[largest];
        arr[i] = arr[i]^arr[largest];
        max_heapify(arr, largest, hs);  
    }
}

void min_heapify( int *arr, int i, int hs){
       int l, r, smallest;

    // get indexes
    l = _left_child(i);
    r = _right_child(i);

    // Test min left
    if (l <= hs && arr[l] < arr[i]) smallest = l; else smallest = i;

    // Test largest right
    if (r <= hs && arr[r] < arr[smallest]) smallest = r;

    // Call recursion
    if (smallest != i){
        // Xor Swap
        arr[i] = arr[i]^arr[smallest];
        arr[smallest] = arr[i]^arr[smallest];
        arr[i] = arr[i]^arr[smallest];
        min_heapify(arr, smallest, hs);  
    }

}

int _left_child(int i){
    return 2*i;
}

int _right_child(int i){
    return 2*i + 1;
}


void build_max_heap(int *arr, int len){
    int i;
    // heapify 
    for(i = len/2; i>0; i--)
        max_heapify(arr, i, len);
}

void build_min_heap(int *arr, int len){
    int i;
    // heapify 
    for(i = len/2; i>0; i--)
        min_heapify(arr, i, len);
    
}
