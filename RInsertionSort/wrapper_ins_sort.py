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
import ctypes
import pathlib
from numpy.ctypeslib import ndpointer 


_heap_name =  pathlib.Path().absolute() / "ctail_recursion_insertsort.so"
_singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C')
_cheap = ctypes.CDLL(_heap_name)
_cheap.crec_insertionsort.argtypes = [_singlepp, ctypes.c_int]
_cheap.crec_insertionsort.restype = ctypes.c_void_p

def recursive_insertion_sort(arr):
    """
    Wrapper of recursive insertion sort

    Param:
    --------------------------------------------------------------------------- 
    arr: array of integers 

    Return
    ---------------------------------------------------------------------------
    NA
    """

    # Stop if ndarray is not correct
    if not isinstance(arr, np.ndarray) or not (arr.dtype == 'int32'):
        raise TypeError('_container is not ndarray of int32')

    n = ctypes.c_int(arr.shape[0])
    _cheap.crec_insertionsort(arr, n)