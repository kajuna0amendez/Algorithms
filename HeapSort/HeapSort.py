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
__name__ = "HeapSort"

import sys
import os
import pathlib
import numpy as np
import ctypes
from numpy.ctypeslib import ndpointer 
sys.path.append(os.environ.get("AAVAR")+'/Heaps')
from heap import heap

class HeapSort(heap):
    """
    Heap Sort Basic Implementation
    """
    def __init__(self):
        super(HeapSort, self).__init__(htype = 'max')
        hPath = os.environ.get("AAVAR")+'/Heaps/cheap.so'
        sPath = os.environ.get("AAVAR")+'/HeapSort'
        ctypes.CDLL(hPath, mode=ctypes.RTLD_GLOBAL) 
        self._loop_name =  pathlib.Path(sPath).absolute() / "sort_loop.so"
        self._singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C')
        self._loop_name  = ctypes.CDLL(self._loop_name)
        self._loop_name.sort_loop.argtypes = [self._singlepp, ctypes.c_int, ctypes.c_int]
        self._loop_name.sort_loop.restype = ctypes.c_void_p


    def __del__(self):
        print('HeapSort destroyed')

    def Sort(self, arr):
        self.read_data(arr)
        self.build_heap()
        self._loop_name.sort_loop(self._container, self._hsize, self._length)
    