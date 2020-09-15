/*
 * __author__ = "Andres Mendez-Vazquez"
 * __copyright__ = "Copyright 2020"
 * __credits__ = ["Andres Mendez-Vazquez"]
 * __license__ = "MIT License"
 * __version__ = "1.0.0"
 * __maintainer__ = "Andres Mendez-Vazquez"
 * __email__ = "kajuna0kajuna@gmail.com"
 * __status__ = "Development"
*/
#ifndef CVECTOR_FILE
#define CVECTOR_FILE

/*
 * Defintion of methods to load lists
 */

#include <Python.h>


/*
 * Generate list at heap level
 * 
 * @param  pointer to a list of elements
 * 
 * @return pointer to a new list container
 * 
 */
PyObject* new_list(PyObject *list);

/*
 * Destructor for the list
 * 
 * @param  pointer to a list of elements
 * 
 */
void del_list(PyObject *list);

/*
 * Generate Iterator
 * 
 * @param  pointer to a list of elements
 * 
 * @return pointer to a new element
 * 
 */
//PyObject* iterator(PyObject *list, int n);
 
/*
 * Print elements in the list
 * 
 * @param  pointer to a list of elements
 * 
 * @return pointer to a new list container
 * 
 */
void print_list(PyObject *list);

#endif
