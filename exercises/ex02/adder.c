/* adder.c
A program that takes in integer values from a user and then finds and 
displays their sum.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declarations. Function-specific documentation is located above
the individual implementation. */
int* get_user_input(int numbers[], int* current_index);
int process_user_input(char input[]);

/* The maximum quantity of numbers that a user can input. */
int MAX_AMOUNT=100;
/* The maximum length of an individual integer a user can input. */
int MAX_LENGTH=5;
/* The maximum size of the input buffer. */
int MAX_BUFFER_SIZE=20;


/* Parses user input. 
   
   Returns integer value of the user input. Returns 0 and prints an error 
   message if the length of the user input exceeds the value of the 
   MAX_LENGTH specified in the constants. 

   input[] : A list of characters input by the users.
   returns : Integer parsed from input list or 0. 
*/
int process_user_input(char input[]) {
    if (strlen(input) > MAX_LENGTH) {
        printf("Input received is greater than maximum value. ");
        return 0;
    }
    return atoi(input);
    
}

/* Gets user input.
   
   Prompts user for input values for adding function until EOF received.
   
   numbers[] : An array to populate with values.
   *current_index : A reference to a shared counter for the current index.
   returns : A pointer to the first element of a populated array of integers
             
   This function will print an error message when the number's length exceeds
   the perscribed number of digits or if the input is otherwise invalid.
   However, it will continue going through and asking for input until the 
   user triggers the EOF flag with Ctrl + D.
    
*/
int * get_user_input(int numbers[], int *current_index) {
    char input[MAX_BUFFER_SIZE];
    int complete = 0;
    printf("Please enter the next number. Use Ctrl + D to quit. \n");
    while (!complete) {
        if (*current_index < MAX_AMOUNT) {
            if (fgets(input, MAX_BUFFER_SIZE,stdin) == NULL) {
                printf("Input complete. Computing sum of numbers.");
                return numbers;
            }
            int current_value = process_user_input(input); 
            if (current_value != 0) {    
                numbers[*current_index] = current_value;
                printf("The number at the current index %d is %d\n", \
                       *current_index, numbers[*current_index]);
                *current_index += 1;    
            }
            else {
                printf("Input is invalid! Try another value.\n");
            }
        }
        else {
            printf("Maximum amount of inputs reached. Computing sum.");
        }
    }
    return numbers;
}

int main() {
    int nums[MAX_AMOUNT];
    int* numbers = nums;
    int current_index = 0;
    int sum = 0;

    numbers = get_user_input(numbers, &current_index);
    /* Compute the sum of the numbers with a quick for loop.*/
    for (int i = 0; i < current_index; i++) {
        sum += numbers[i];
    }
    printf("The sum of the numbers is %d\n", sum); 
}
