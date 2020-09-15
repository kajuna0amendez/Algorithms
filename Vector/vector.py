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
__name__ = "vector"

import ctypes
from numpy.ctypeslib import ndpointer 
import numpy as np
import pathlib
import sys
import os


class vector:
    """
    Generic List using C
    """
    def __init__(self):
        """
        Init the Vector Class
        """
        self._container = ctypes.py_object([1,2,3])
        sPath = os.environ.get("AAVAR")+'/Vector' 
        self._vector_name =  pathlib.Path(sPath).absolute() / "libcvector.so"
        self._vector = ctypes.CDLL(self._vector_name)
        self._vector.new_list.restype = ctypes.py_object 
        self._vector.new_list.argtypes = [ ctypes.py_object ]
        self._vector.del_list.restype = ctypes.c_void_p
        self._vector.del_list.argtypes = [ ctypes.py_object ]
        self._vector.print_list.restype = ctypes.c_void_p
        self._vector.print_list.argtypes = [ ctypes.py_object ]


    def __del__(self):
        """
        Del for the vector class
        """
        self._vector.del_list(self._container)

    def read_data(self, list):
        """
        Convert list to objects elements
        """
        self._container = self._vector.new_list(ctypes.py_object(list))

    def print_data(self): 
        """
        Print Pointer
        """
        self._vector.print_list(self._container)        
