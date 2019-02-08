/* adder.c
A program that takes in integer values from a user and then finds and 
displays their sum.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_user_input(int* numbers, int* current_index);
int compute_sum(int* numbers, int* current_index);


/* The maximum quantity of numbers that a user can input. */
int MAX_AMOUNT=100;
/* The maximum length of an individual integer a user can input. */
int MAX_LENGTH=10;

void get_user_input(int* numbers, int *current_index) {
    char input[MAX_LENGTH];
    int complete = 0;
    printf("Please enter the next number. Use Ctrl + D to quit. \n");
    while (!complete) {
        if (*current_index < MAX_AMOUNT) {
            scanf("%2s", input);
           // fgets(*input, MAX_LENGTH,stdin);
            int current_value = atoi(input);  
            if (current_value != EOF) {
                numbers[*current_index] = current_value;
                *current_index += 1;
            }
            else {
                printf("Input complete. Computing sum of numbers");
                complete = 1;
            }
        }
    }
}
int compute_sum(int* numbers, int* current_index) {
    int sum = 0;
    for (int i = 0; i < *current_index; i++) {
        sum += numbers[*current_index];
    }
    return sum;
}

int main() {
    int numbers[MAX_AMOUNT];
    int current_index;
    printf("Getting user input.");
    get_user_input(numbers, &current_index);
    int sum = compute_sum(numbers, &current_index);
    printf("The sum of the numbers is %d", sum); 
} 
