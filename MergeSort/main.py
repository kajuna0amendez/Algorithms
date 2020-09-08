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
__name__ = "__main__"


import numpy as np 
from numpy.ctypeslib import ndpointer 
import ctypes
import pathlib
from merge_sort import merge_sort

if __name__ == "__main__":

    tlabel = 1

    if tlabel == 1:

        # Array to sort
        x = np.arange(100,1,-1, dtype = np.int32 )
        print(x)

        merge_sort(x)

        print(x)


        

