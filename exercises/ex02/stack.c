/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/*
Experiment 1 : This code should theoretically create an array of length SIZE,
               print its address, populate each index with the number 42,
               create another array, print its address, populate that array
               with the numbers 0 through SIZE-1, and print out those values
               line-by-line. In this case, that looks like the two addresses
               followed by the numbers 0 through 4 with new lines in between
               each individual printout.

Experiment 2 : When attempting compilation, the program reports that the 
               function returns the address of a local variable. 
               This implies that the return type of foo (an integer pointer)
               is the address of a local variable - something destroyed
               when the function is terminated that no longer has any
               significance to the program itself.

Experiment 3 : I got a segmentation fault! This makes a lot of sense because
               I tried to access memory that should no longe exist - so
               when trying to print the value, it could not execute. 
               Before I got the segmentation fault, it printed the addresses
               of both arrays, and the addresses are identical. 

Experiment 4 : I commented out hte print statements in both of the functions.
               Nothing really changed, except that it no longer printed the
               addresses. This makes sense.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

   // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
