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


from vector import vector


if __name__ == "__main__":

    tlabel = 1

    if tlabel == 1:
        
        vobject = vector()

        vobject.read_data([1, 2, '3443'])

        vobject.print_data()


        

