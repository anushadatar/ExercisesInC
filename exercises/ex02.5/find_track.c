/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_TRACKS 5

// List of tracks associated with given example.
char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/* Finds all tracks that contain the given string.

    search_for[] : Character array of specific characters/sequences.
    returns :      void

    Prints track number and title of tracks that contain the value.
    Note : This leverages the strstr method to find specified sequences 
           presented in an array.
*/  
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

/* Finds all tracks that contain characters specified by the given regex.
    
    pattern : character array of regular expression to search for.
    returns : void
    
    Prints track number and title of tracks that contain the value.
    Note : This leverages the regex library to search for patterns.
*/
void find_track_regex(char pattern[])
{
    regex_t reg;
    int value;

    value = regcomp(&reg, pattern, 0);
    if (value != 0) {
        printf("Regex compilation failed.");
        exit(1);
    }
    int i;
    for (int i=0; i < NUM_TRACKS; i++) {
        value = regexec(&reg, tracks[i], 0, NULL, 0);
        // If the value is zero
        if (value == 0) {
                printf("Track %i: %s\n", i, tracks[i]);
            }
        // Uncomment the lines below for more verbose output.
        //else {
            // printf("Regex search failed to find pattern. Trying next...");
        //}
    }
    regfree(&reg);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
