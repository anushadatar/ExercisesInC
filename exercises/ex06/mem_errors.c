/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main()
{
    // We don't use this, let's comment it out.
    //int never_allocated;
    int *free_twice = malloc(sizeof (int));
    int *use_after_free = malloc(sizeof (int));
    int *never_free = malloc(sizeof (int));
    int array1[100];

    // Comment out this array.
    // int *array2 = malloc(100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    read_element(array1, 1); // Made this positive one (not negative).
    read_element(array1, 1); // Made this 1 as well  (within bounds).

    // Commented out this whole section.
    // but it does bounds-check dynamic arrays
    // read_element(array2, -1);
    // read_element(array2, 100);


    // and it catches use after free
    *use_after_free = 17;
    // never_free is definitely lost
    *never_free = 17;

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // Commented out this line.
    // free_anything(&never_allocated);

    free(free_twice);
    // Added all of these frees for our friend valgrind.
    free(use_after_free);
    free(never_free);
    // Commented out this line.
    // free(free_twice);

    return 0;
}
