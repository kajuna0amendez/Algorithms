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
import sys

class TailRecurseException:
  def __init__(self, args, kwargs):
    self.args = args
    self.kwargs = kwargs

def tail_call_optimized(g):
  """
  This function decorates a function with an interpreted version of
  tail recursion
  """
  def func(*args, **kwargs):
    f = sys._getframe() # Top frame
    # if two and three depth frames exist and  if the code at the top
    # recursion and the three depth frame use the same code 
    if f.f_back and f.f_back.f_back and f.f_back.f_back.f_back  \
        and f.f_back.f_back.f_back.f_code == f.f_code:
      # Break the recursion
      raise TailRecurseException(args, kwargs)
    else:
      # Here you run the frame in a try catch setup
      while 1:
        try:
          return g(*args, **kwargs)
        except TailRecurseException as e:
          args = e.args
          kwargs = e.kwargs
  func.__doc__ = g.__doc__
  return func


def RInsertionSort(array):
    """
    Recursive insertion sort

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

@tail_call_optimized
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

        # Tail Recursive Insertion
        go(array, key, i-1) 
        # Calling the next level of insertion
        fhelper(array, i+1, n)

@tail_call_optimized
def go(array, key, j):
    """
    Tail based recursion 
    """
    if key >= array[j] or j < 0:
        array[j+1] = key
    else:
        array[j+1] = array[j]
        go(array, key, j-1)
