# -*- coding: utf-8 -*-
#!/usr/bin/env python
__author__ = "Andres Mendez-Vazquez"
__copyright__ = "Copyright 2020"
__credits__ = ["Andres Mendez-Vazquez"]
__license__ = "MIT License"
__version__ = "1.0.0"
__maintainer__ = "Andres Mendez-Vazquez"
__email__ = "kajuna0kajuna@gmail.com"
__status__ = "Development"
__name__ = "merge_sort"

import ctypes
from numpy.ctypeslib import ndpointer 
import numpy as np
import pathlib
import sys

# Load the shared library into c types.
_merge_sort_name =  pathlib.Path().absolute() / "cmerge_sort.so"
_singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C')
_cmerge = ctypes.CDLL(_merge_sort_name)
_cmerge.merge_sort.argtypes = [_singlepp, ctypes.c_int]
_cmerge.merge_sort.restype = ctypes.c_void_p


def merge_sort(arr):
    """
    The Python Wrapper of merge_sort

    Params
    ----------------------------------------------------------------------------
    arr: numpy array of int32

    Return
    ----------------------------------------------------------------------------
    NA
    """
    # If you have 
    if type(arr) is np.ndarray and len(arr) > 0:
        # See if you have the correct dtype
        if type(arr[0]) is np.int32:
            lower = ctypes.c_int(0)
            upper = ctypes.c_int(arr.shape[0] - 1)
            #print(lower)
            #print(upper)
            _cmerge.merge_sort(arr, lower, upper)
        else:
            # Exit with error
            print('Error in the array dtype')
            sys.exit(-1)
    else:
        # Exit with error
        print('Error in the object not a ndarray or array null')
        sys.exit(-1)