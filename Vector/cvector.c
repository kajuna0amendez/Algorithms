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

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "cvector.h"

PyObject* new_list(PyObject *list){
    // Local Variables
    Py_ssize_t i, n;
    PyObject *new_list;

    n = PyList_Size(list);

    new_list = PyList_New(n);

    for(i = 0; i < n; i++){
        PyList_SetItem(new_list, i,Py_BuildValue("i", list[i]));
    }
    return new_list;
}

void del_list(PyObject *list){
    // Del reference
    Py_DECREF(list);
    printf("reference removed\n");

}

//PyObject* iterator(PyObject *list, int n){
    // Return Item
//    return PyList_GetItem(list, n);
//}
 
void print_list(PyObject *list){
    // local variables
    Py_ssize_t i, n;
    PyObject *item;
    PyTypeObject *type_item;

    n = PyList_Size(list);

    for(i = 0; i < n; i++){
        item = PyList_GetItem(list, i);
        type_item = item->ob_type;
        const char* p = type_item->tp_name;
        printf("%s ", p);
    }
}

