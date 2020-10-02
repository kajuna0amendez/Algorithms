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

import ctypes
from numpy.ctypeslib import ndpointer 
import numpy as np
import pathlib
import os

_sPath = os.environ.get("AAVAR")+'/LinearSort' 
_ls_name =  pathlib.Path(_sPath).absolute() / "linear_sort.so"
_singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C')
_ls = ctypes.CDLL(_ls_name)
_ls.counting_sort.argtypes = [_singlepp, ctypes.c_int]
_ls.counting_sort.restype = ctypes.c_void_p
_ls.radix_sort_table.argtypes = [_singlepp, ctypes.c_int]
_ls.radix_sort_table.restype = ctypes.c_void_p
_ls.radix_sort_queue.argtypes = [_singlepp, ctypes.c_int]
_ls.radix_sort_queue.restype = ctypes.c_void_p
_ls.bucket_sort.argtypes = [_singlepp, ctypes.c_int]
_ls.bucket_sort.restype = ctypes.c_void_p

def counting_sort(arr):
    """
    Counting sort

    Params:
    ---------------------------------------------------------------------------
    arr a ndarray of long integers

    Return
    ---------------------------------------------------------------------------
    NA
    """

    if not isinstance(arr, np.ndarray) or not (arr.dtype == 'int32'):
        raise TypeError('_container is not ndarray of int64')

    if min(arr)<0:
        raise TypeError('Counting sort is not implemented for negative numbers')


    n = ctypes.c_int(len(arr)) 

    _ls.counting_sort(arr, n)

def radix_sort_table(arr):
    """
    Radix sort by table 

    Params:
    ---------------------------------------------------------------------------
    arr a ndarray of long integers

    Return
    ---------------------------------------------------------------------------
    NA
    """
    
    if not isinstance(arr, np.ndarray) or not (arr.dtype == 'int32'):
        raise TypeError('_container is not ndarray of int64')

    n = ctypes.c_int(len(arr)) 

    _ls.radix_sort_table(arr, n)

def radix_sort_queue(arr):
    """
    Radix sort by binary queues

    Params:
    ---------------------------------------------------------------------------
    arr a ndarray of long integers

    Return
    ---------------------------------------------------------------------------
    NA
    """
    
    if not isinstance(arr, np.ndarray) or not (arr.dtype == 'int32'):
        raise TypeError('_container is not ndarray of int64')

    n = ctypes.c_int(len(arr)) 

    _ls.radix_sort_table(arr, n)


def bucket_sort(arr):
    """
    bucket sort

    Params:
    ---------------------------------------------------------------------------
    arr a ndarray of long integers

    Return
    ---------------------------------------------------------------------------
    NA
    """
    
    if not isinstance(arr, np.ndarray) or not (arr.dtype == 'int32'):
        raise TypeError('_container is not ndarray of int64')

    n = ctypes.c_int(len(arr)) 

    _ls.radix_sort_table(arr, n)
