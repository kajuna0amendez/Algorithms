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
from ctypes import c_int 
import pathlib

if __name__ == "__main__":

    tlabel = 2

    if tlabel == 1:
        # Load the shared library into c types.
        libname = pathlib.Path().absolute() / "libcprint_array.so"
        c_lib = ctypes.CDLL(libname)

        # Define return void pointer
        c_lib.cprint_array.restype = ctypes.c_void_p

        # Define arguments
        singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C') 
        c_lib.cprint_array.argtypes = [singlepp, ctypes.c_int]

        # Define ndarray
        x = np.arange(9, dtype = np.int32 ).reshape((3, 3))

        print(x)

        # Define the m parameter for the array len 
        m = ctypes.c_int(x.shape[0]) 

        print(m)
        
        c_lib.cprint_array(x, m)

        print(x)

    elif tlabel == 2:
        # Load the shared library into c types.
        libname = pathlib.Path().absolute() / "libcprint_matrix.so"
        c_lib = ctypes.CDLL(libname)
        
        # Define return void pointer
        c_lib.cprint_array.restype = ctypes.c_void_p
        
        # Define arguments
        doublepp = ndpointer(dtype = np.int32, ndim = 2, flags = 'C') 
        c_lib.cprint_matrix.argtypes = [doublepp, c_int, c_int]

        # Define ndarray
        x = np.arange(9, dtype = np.int32).reshape((3,3))

        # Get Parameters
        m = ctypes.c_int(x.shape[0]) 
        n = ctypes.c_int(x.shape[1]) 

        #print(x)

        c_lib.cprint_matrix(x, m, n)

        #print(x)
        

