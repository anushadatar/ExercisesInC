/* tee.c

Quick utility program to implement the unix tee() function.

3. Honestly the biggest roadblock I faced was deciding what to implement - 
   there wer emany different possible directions and factors, and it was
   important to just focus on the base functionality needed.

4. Professional code uses a lot more formal error checking than I do and 
   generally considers many more possible constraints and failure modes
   such that it provides a more streamlined user experience.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int BUFFER_LENGTH = 256;


/*
Listens for command-line arguments and then executes accordingly. 
*/
int main(int argc, char *argv[]) {
    char input_buffer[BUFFER_LENGTH];
    FILE* output_file;
    char input;
    int append = 0;
    
    input = getopt(argc, argv, "a");
    switch(input) {
            case 'a' :
                append = 1;
                break;
            default :
                append = 0;
                break;
    }
    
    while (fgets(input_buffer, BUFFER_LENGTH, stdin)) {
        if (append == 1) {                                                          
            output_file = fopen(argv[1], "a");                                      
        }
        else {                                                                      
            output_file = fopen(argv[1], "w");                                      
        }    
        fputs(input_buffer, output_file);
        fprintf(stdout, "%s\n", input_buffer);
        fclose(output_file);
    }
    
}
