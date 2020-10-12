// priority_queue_heap.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "priority_queue_heaps.h"
#include "Process.h"

// Here, we only implement the max priority queue

static void swap_xor(int *a, int *b){
    // In place macros given static
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

struct PriorityQueue* init_priority_queue(int *IDs, int *Quantas, int len, int hs, bool min_max){
    struct PriorityQueue *PQueue;
    int i;
    
    // Init Structure Pointer
    PQueue = &( struct PriorityQueue) {
        .container = (struct ProcessNode*) malloc(sizeof(struct ProcessNode)*len),
        .hs = hs,
        .len = len
    };
    
    for( i = 0; i < hs ; i++ ){
        PQueue->container[i].elem.IDs = IDs[i];
        PQueue->container[i].elem.Quanta = Quantas[i];
        PQueue->container[i].key = Quantas[i];
    }

    // True for min heap False for max heap
    if (min_max == true){
        build_min_heap(PQueue);
    } else {
        build_max_heap(PQueue);
    } 

    return PQueue;
}


void free_priority_queue(struct PriorityQueue* PQueue){
    free(PQueue->container);
}

void max_heapify(struct PriorityQueue *arr, int i){

    int l, r, largest;

    // get indexes
    l = _left_child(i);
    r = _right_child(i);

    // Test largest left
    if (l <= arr->hs && arr->container[l].key > arr->container[i].key) largest = l;
    else largest = i;

    // Test largest right
    if (r <= arr->hs && arr->container[r].key > arr->container[largest].key) largest = r;

    // Call recursion
    if (largest != i){
        // Xor Swap
        swap_xor(&(arr->container[i].key), &(arr->container[largest].key));
        max_heapify(arr, largest);  
    }
}

void min_heapify(struct PriorityQueue *arr, int i){
       int l, r, smallest;

    // get indexes
    l = _left_child(i);
    r = _right_child(i);

    // Test min left
    if (l <= arr->hs && arr->container[l].key < arr->container[i].key) smallest = l; else smallest = i;

    // Test largest right
    if (r <= arr->hs && arr->container[r].key < arr->container[smallest].key) smallest = r;

    // Call recursion
    if (smallest != i){
        // Xor Swap
        swap_xor(&(arr->container[i].key), &(arr->container[smallest].key));
        min_heapify(arr, smallest);  
    }
}

static int _left_child(int i){
    return 2*i;
}

static int _right_child(int i){
    return 2*i + 1;
}

static int _parent(int i){
    return i>>1;
}

void build_max_heap(struct PriorityQueue *arr){
    int i;
    // heapify 
    for(i = arr->len>>1; i>0; i--)
        max_heapify(arr, i);
}

void build_min_heap(struct PriorityQueue *arr){
    int i;
    // heapify 
    for(i = arr->len>>1; i>0; i--)
        min_heapify(arr, i);
    
}

void heap_increase_key(struct PriorityQueue *arr, int i, int key){

    if (key < arr->container[i].key){
        exit(EXIT_FAILURE);
    }

    arr->container[i].key = key;

    while (i>1 && arr->container[_parent(i)].key < arr->container[i].key){
        // Xor Swap
        swap_xor(&(arr->container[i].key), &(arr->container[_parent(i)].key));
        i = _parent(i);
    }
}

void heap_decrease_key(struct PriorityQueue *arr, int i, int key){

    if (key > arr->container[i].key){
        exit(EXIT_FAILURE);
    }

    arr->container[i].key = key;

    while (i>1 && arr->container[_parent(i)].key < arr->container[i].key){
        // Xor Swap
        swap_xor(&(arr->container[i].key), &(arr->container[_parent(i)].key));
        i = _parent(i);
    }
}

void max_insert(struct PriorityQueue *arr, int key){
    int i;

    if (arr->hs == arr->len){
        // generate new array 
        struct PriorityQueue *temp;

        temp = &(struct PriorityQueue){
            .container = (struct ProcessNode*) malloc(sizeof(struct ProcessNode*)*2*arr->len),
            .hs = arr->hs,
            .len = 2*arr->len
        };
        

        // Copy elements to it 
        for( i = 0; i < arr->len ; i++){
            temp->container[i].elem =  arr->container[i].elem;
            temp->container[i].key = arr->container[i].key;
        }        
        // free arr
        free(arr->container);
        // connect new one
        arr = temp;
    }

    arr->hs ++;
    arr->container[arr->hs].key = INT_MIN;

    heap_increase_key(arr, arr->hs, key);
}

void min_insert(struct PriorityQueue *arr, int key){
    int i;

    if (arr->hs == arr->len){
        // generate new array 
        struct PriorityQueue *temp;

        temp = &(struct PriorityQueue){
            .container = (struct ProcessNode*) malloc(sizeof(struct ProcessNode*)*2*arr->len),
            .hs = arr->hs,
            .len = 2*arr->len
        };
        
        // Copy elements to it 
        for( i = 0; i < arr->len ; i++){
            temp->container[i].elem =  arr->container[i].elem;
            temp->container[i].key = arr->container[i].key;
        }        
        // free arr
        free(arr->container);
        // connect new one
        arr = temp;
    }

    arr->hs ++;
    arr->container[arr->hs].key = INT_MIN;

    heap_decrease_key(arr, arr->hs, key);

}

int maximum(struct PriorityQueue *arr){
    return arr->container[1].key;
}

int minimum(struct PriorityQueue *arr){
    return arr->container[1].key;
}

struct ProcessNode extract_maximum(struct PriorityQueue *arr){

    if (arr->hs<1)
        exit(EXIT_FAILURE);

    struct ProcessNode max;
    max.elem.IDs = arr->container[1].elem.IDs;
    max.elem.Quanta = arr->container[1].elem.Quanta;
    max.key = arr->container[1].key;
    arr->container[1]= arr->container[arr->hs];
    arr->hs --;
    max_heapify(arr,1);
    return max;
}

struct ProcessNode extract_minimum(struct PriorityQueue *arr){

    if (arr->hs<1)
        exit(EXIT_FAILURE);

    struct ProcessNode min;
    min.elem.IDs = arr->container[1].elem.IDs;
    min.elem.Quanta = arr->container[1].elem.Quanta;
    min.key = arr->container[1].key;
    arr->container[1]= arr->container[arr->hs];
    arr->hs --;
    min_heapify(arr,1);
    return min;
}


