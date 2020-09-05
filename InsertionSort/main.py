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


import numpy as np 
from numpy.ctypeslib import ndpointer 
import ctypes
from ctypes import POINTER, ARRAY, c_float, c_int 
import pathlib

if __name__ == "__main__":

    tlabel = 1

    if tlabel == 1:
        # Load the shared library into c types.
        libname = pathlib.Path().absolute() / "InsertionSort.so"

        c_lib = ctypes.CDLL(libname)

        singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C') 

        c_lib.InsertionSort.argtypes = [singlepp, ctypes.c_int]

        x = np.arange(9, 0, -1 , dtype = np.int32 )

        print(x)

        m = ctypes.c_int(x.shape[0]) 
       
        c_lib.InsertionSort(x, m)

        print(x)


        

