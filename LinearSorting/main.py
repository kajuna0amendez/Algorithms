# -*- coding: utf-8 -*-
#!/usr/bin/env python
__author__ = "Andres Mendez-Vazquez"
__copyright__ = "Copyright 2017 Sampler Project"
__credits__ = ["Andres Mendez-Vazquez"]
__license__ = "GPL"
__version__ = "1.0.0"
__maintainer__ = "Andres Mendez-Vazquez"
__email__ = "amendez@gdl.cinvestav.mx"
__status__ = "Development"
__name__ = "__main__"

import numpy as np 
import time
import os
import sys
import matplotlib.pyplot as plt
from LinearSort import counting_sort, radix_sort_table, radix_sort_queue

_sPath = os.environ.get("AAVAR")+'/MergeSort'
sys.path.append(_sPath)
_sPath = os.environ.get("AAVAR")+'/RInsertionSort'
sys.path.append(_sPath)

from merge_sort import merge_sort, merge_sort_inplace 
from wrapper_ins_sort import recursive_insertion_sort



if __name__ == "__main__":


    # Basic test
    x = np.arange(10, -1, -1, dtype = np.int32 )

    print('test counting sort')

    print(x)
    counting_sort(x)
    print(x)

    A = np.random.randint(0, 200, 10, dtype = np.int32)
    print(A)
    counting_sort(A)
    print(A)

    print('test radix sort table')

    A = np.arange(10, -10, -1, dtype = np.int32)

    print(A)
    radix_sort_table(A)
    print(A)

    A = np.random.randint(0, 100, 30, dtype = np.int32)
    print(A)
    radix_sort_table(A)
    print(A)

    print('test radix sort queue')

    x = np.arange(10, -10, -1, dtype = np.int32 )

    print(x)
    radix_sort_queue(x)
    print(x)

    A = np.random.randint(0, 200, 40, dtype = np.int32)
    print(A)
    radix_sort_table(A)
    print(A)    


    # Performance Test
    slowsort = False
    testsize = 2000000
    step = 10000
    range_randint = 1e8

    if slowsort == True:
        #print('test recursive insertion sort')
        #
        #plt.figure()

        #resultt = list()
        #resultn = list()
        #for i in range(1, testsize, step):
        #    x = np.random.randint(0, range_randint, i, dtype = np.int32)
        #    first = time.time()
        #    recursive_insertion_sort(x)
        #    resultt.append(time.time()-first)
        #    resultn.append(i)
        #x = np.array(resultn)
        #y = np.array(resultt)
        #plt.plot(x, y, 'g-', label='Recursive Insertion Sort')

        print('test in place mergesort')

        resultt = list()
        resultn = list()
        for i in range(1, testsize, step):

            x = np.random.randint(0, range_randint, i, dtype = np.int32)

            first = time.time()

            merge_sort_inplace(x)

            resultt.append(time.time()-first)

            resultn.append(i)
        
        x = np.array(resultn)
        y = np.array(resultt)

        plt.plot(x, y, 'b-', label='InPlace Merge Sort')

    print('test mergesort')

    resultt = list()
    resultn = list()
    for i in range(1, testsize, step):

        x = np.random.randint(0, range_randint, i, dtype = np.int32)

        first = time.time()

        merge_sort(x)

        resultt.append(time.time()-first)

        resultn.append(i)
        
    x = np.array(resultn)
    y = np.array(resultt)

    plt.plot(x, y, 'm-', label='Merge Sort')

    print('test counting_sort')

    resultt = list()
    resultn = list()
    for i in range(1, testsize, step):

        x = np.random.randint(0, range_randint, i, dtype = np.int32)

        first = time.time()

        counting_sort(x)

        resultt.append(time.time()-first)

        resultn.append(i)
        
    x = np.array(resultn)
    y = np.array(resultt)

    plt.plot(x, y, 'r-', label='Counting Sort')

    print('test radix_sort_table')

    resultt = list()
    resultn = list()
    for i in range(1, testsize, step):

        x = np.random.randint(0, range_randint, i, dtype = np.int32)

        first = time.time()

        radix_sort_queue(x)

        resultt.append(time.time()-first)

        resultn.append(i)
        
    x = np.array(resultn)
    y = np.array(resultt)

    plt.plot(x, y, 'k-', label='Radix Sort')

    print('test NP Sort Table')

    resultt = list()
    resultn = list()
    for i in range(1, testsize, step):

        x = np.random.randint(0, range_randint, i, dtype = np.int32)

        first = time.time()

        np.sort(x)

        resultt.append(time.time()-first)

        resultn.append(i)
        
    x = np.array(resultn)
    y = np.array(resultt)

    plt.plot(x, y, 'y-', label='Sort np')
    plt.xlim((0, testsize))

    plt.legend()

    plt.show()


