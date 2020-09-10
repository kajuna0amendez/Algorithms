""" Task definitions for invoke command line utility for python bindings
    overview article. """
#import cffi
import invoke
#import pathlib


@invoke.task
def clean(c):
    """ Remove any built objects """
    for pattern in ["*.o", "*.so"]:
        c.run("rm -rf {}".format(pattern))


def print_banner(msg):
    print("==================================================")
    print("= {} ".format(msg))


@invoke.task
def build_cmult(c):
    """ Build the shared library for the sample C code """
    print_banner("Building C Library")
    invoke.run("gcc -c -Wall -Werror -fpic cmult.c -I /usr/include/python3.8")
    invoke.run("gcc -shared -o libcmult.so cmult.o")
    print("* Complete")


@invoke.task
def build_cprint_array(c):
    """ Build the shared library for the sample C code """
    print_banner("Building C Library")
    invoke.run("gcc -c -Wall -Werror -fpic cprint_array.c -I /usr/include/python3.8")
    invoke.run("gcc -shared -o libcprint_array.so cprint_array.o")
    print("* Complete")


@invoke.task
def build_cprint_matrix(c):
    """ Build the shared library for the sample C code """
    print_banner("Building C Library")
    invoke.run("gcc -c -Wall -Werror -fpic cprint_matrix.c -I /usr/include/python3.8")
    invoke.run("gcc -shared -o libcprint_matrix.so cprint_matrix.o")
    print("* Complete")