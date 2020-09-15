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

""" Task definitions for invoke command line utility for python bindings """
import invoke


@invoke.task
def clean(c):
    """ Remove any built objects """
    for pattern in ["*.o", "*.so", "cffi_example* cython_wrapper.cpp"]:
        c.run("rm -rf {}".format(pattern))


def print_banner(msg):
    print("==================================================")
    print("= {} ".format(msg))


@invoke.task
def build_cvector(c):
    """ Build the shared library for the sample C code """
    print_banner("Building C Library")
    invoke.run("gcc -c -Wall -Werror -fpic cvector.c -I /usr/include/python3.8")
    invoke.run("gcc -shared -o libcvector.so cvector.o")
    print("* Complete")

