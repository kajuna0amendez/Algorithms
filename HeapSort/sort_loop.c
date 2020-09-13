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
#include "sort_loop.h"
#include "../Heaps/cheap.h"

void sort_loop( int *arr, int hs, int as){

    int new_hs = hs;

    for(int i = as; i > 1; i--){
        // Exchange variables
        arr[1] = arr[1]^arr[i];
        arr[i] = arr[1]^arr[i];
        arr[1] = arr[1]^arr[i];
        // Decrease the heap size
        new_hs--; 
        // Launch Max Heapify
        max_heapify(arr, 1, new_hs);
    } 
}
