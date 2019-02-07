/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/
void print_local_variable_address();
#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    /* Create and print the address of an arbitrary local variable to show
       that the stack grows downward. */
    print_local_variable_address(); 
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
    void *t = malloc(128);
     
    printf ("Address of main is %p\n", main);
    printf ("Address of var1, a global variable, is %p\n", &var1);
    printf ("Address of var2, a local variable, is %p\n", &var2);
    printf ("p points to some allocated memory at address  %p\n", p);
    printf ("s points to a string literal at  %p\n", s);
    /* Making a second call to malloc() and checking the address accordingly
       proves that the heap grows upwards. */
    printf ("t points to some allocated memory at %p\n", t);

    /* Allocating two equally-sized pieces of memory to see the distance 
       between each allocated chunk. */
    void *a = malloc(12);
    void *b = malloc(12);
    printf ("a points to %p\n", a);
    printf ("b points to %p\n", b);

    /* For those keeping score at home, the distance between the pointers is
       20 and each pointer is pointing to 12 allocated bytes of memory. */
    return 0;
}

/* Prints the address of an arbitrary local variable as part of exercise 02.
The goal of this exercise is to confirm that the stack grows downwards.*/

void print_local_variable_address() {
    int l = 12;
    printf ("Address of l, a local variable, is %p\n", &l);
}
