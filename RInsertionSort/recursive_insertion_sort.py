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

def RInsertionSort(array):
    """
    InsertionSort

    Params
    --------------------------------------------------------------------------- 
    Array: ndarray with integers

    Return
    --------------------------------------------------------------------------- 
    NA
    """

    if not isinstance(array, np.ndarray):
            raise TypeError('_container is not ndarray') 

    # Get array
    n = len(array)

    fhelper(array, 1, n)



def fhelper(array, i, n):
    """
    InsertionSort

    Params
    --------------------------------------------------------------------------- 
    array: ndarray with integers

    n: int high index

    Return
    --------------------------------------------------------------------------- 
    NA
    """
    if i < n:

        key = array[i]

        # Recursive Insertion
        j = rinsertion(array, key, i-1) 
        
        array[j+1] = key

        fhelper(array, i+1, n)

def rinsertion(array, key, j):

    if key < array[j] and j >= 0:
        array[j+1] = array[j]
        return rinsertion(array, key, j-1)
    else:
        return j
