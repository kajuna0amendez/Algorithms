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

    tlabel = 1

    if tlabel == 1:
        # Load the shared library into c types.
        libname = pathlib.Path().absolute() / "input_rand.so"

        c_lib = ctypes.CDLL(libname)

        c_lib.permute_by_sorting.restype = ctypes.c_void_p

        c_lib.permute_in_place.restype = ctypes.c_void_p

        singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C') 

        c_lib.permute_by_sorting.argtypes = [singlepp, ctypes.c_int]

        c_lib.permute_in_place.argtypes = [singlepp, ctypes.c_int]

        x = np.arange(100, dtype = np.int32 )

        print(x)

        m = ctypes.c_int(x.shape[0]) 
       
        c_lib.permute_by_sorting(x, m)

        print(x)

        c_lib.permute_in_place(x, m)

        print(x)


        

