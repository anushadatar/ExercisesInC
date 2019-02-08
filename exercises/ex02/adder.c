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

/* The maximum quantity of numbers that a user can input. */
int MAX_AMOUNT=100;
/* The maximum length of an individual integer a user can input. */
int MAX_LENGTH=10;

int * get_user_input(int numbers[], int *current_index) {
    char input[MAX_LENGTH];
    int complete = 0;
    printf("Please enter the next number. Use Ctrl + D to quit. \n");
    while (!complete) {
        printf("Starting");
        if (*current_index < MAX_AMOUNT) {
            if (fgets(input, MAX_LENGTH,stdin) == NULL) {
                printf("Input complete. Computing sum of numbers.");
                return numbers;
            }
            int current_value = atoi(input);  
            printf("current value is %d", current_value);
            if (current_value != 0) {    
                numbers[*current_index] = current_value;
                printf("The number at the current index %d is %d\n", *current_index, numbers[*current_index]);
                *current_index += 1;    
            }
        }
    }
    return numbers;
}


int main() {
    int nums[MAX_AMOUNT];
    int* numbers = nums;
    int current_index = 0;
    int sum = 0;

    printf("Getting user input.");
    numbers = get_user_input(numbers, &current_index);
    for (int i = 0; i < current_index; i++) {
        printf("%d\n", numbers[i]);
        sum += numbers[i];
    }
    printf("The sum of the numbers is %d", sum); 
}
