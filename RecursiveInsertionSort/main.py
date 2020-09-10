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
from recursive_insertion_sort import RInsertionSort


if __name__ == "__main__":

    x = np.arange(10, 0, -1, dtype = np.int32 )

    print(x)

    RInsertionSort(x)

    print(x)