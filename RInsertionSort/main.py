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
from r_imp_insertion_sort import RInsertionSort
from wrapper_ins_sort import recursive_insertion_sort


if __name__ == "__main__":

    tlabel = 1

    if tlabel == 0:

        x = np.arange(10, 0, -1, dtype = np.int32 )

        print('recursive insertion sort using tail recursion Python')

        print(x)

        RInsertionSort(x)

        print(x)
    
    elif tlabel == 1:
        
        x = np.arange(10, 0, -1, dtype = np.int32 )

        print('recursive insertion sort using tail recursion C')


        print(x)

        RInsertionSort(x)

        print(x)