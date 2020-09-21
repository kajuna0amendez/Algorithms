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
from numpy.ctypeslib import ndpointer 
import ctypes
import pathlib
import time
from merge_sort import merge_sort, merge_sort_inplace
import matplotlib
import matplotlib.pyplot as plt

if __name__ == "__main__":

    tlabel = 1

    if tlabel == 1:

        # Array to sort
        x = np.arange(10,1,-1, dtype = np.int32 )
        print(x)
        merge_sort_inplace(x)
        print(x)


        x = np.random.randint(100, size=50, dtype = np.int32)
        print(x)
        y =  x.copy()
        merge_sort_inplace(y)
        print(np.sort(x)-y)

        x_a = list()
        y_a = list()
        for i in range(1,1000):
            x = np.random.randint(1e8, size=10*i, dtype = np.int32)
            start_time = time.time()
            merge_sort_inplace(x)
            y_a.append(time.time()-start_time)
            x_a.append(i*10)

        x_am = list()
        y_am = list()
        for i in range(1,1000):
            x = np.random.randint(1e8, size=10*i, dtype = np.int32)
            start_time = time.time()
            merge_sort(x)
            y_am.append(time.time()-start_time)
            x_am.append(i*10)

        plt.figure()
        plt.plot(np.array(x_a),np.array(y_a),'r-')
        plt.plot(np.array(x_am),np.array(y_am),'b-')
        plt.show()

        



        

