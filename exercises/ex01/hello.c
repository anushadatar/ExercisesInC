/* hello.c

File associated with compiler experiments for 1/29/2019 software systems
classwork and exercise01 homework.
*/ 
#include <stdio.h>

/* Main function associated with 1/29 classwork compiler exercise and 
homework01 assignment about the compiler.
Answers to Questions/Explanation of Experiments:
1. The assembly code that corresponds to the assignment of the variable x to
   the value of 5 is associated line 24 of my assembly code, where the line
   states "movl $5, -16(%rbp)". This makes sense because it is populating 
   the associated address without retaining the variable name.
2. When optimized using the -O2 flag, the assembly code associated with 
   setting this value is no longer included because it is unused. 
3. When x is printed, its value is retained during optimization. C is still
   computed because of work associated with class of 01/29 - if
   this code was not present, it would not store the value of c when optimized. 
4. Because the code will always compute the value of y and then only consider
   that value, the program only stores the value of x + 1 - the assembly
   code states "movl $6, %edx," suggesting it is just storing the total. 
   When not optimized the values are stored as expected. This implies that
   gcc is doing the operation at compile time and saving time and space
   accordingly. 
*/
int main() {
    // Note that the compiler will just precompute and store the value of y
    // because that is the only value printed. 
    int x = 5;
    int y = x + 1;
    printf("Hello, World!\n");
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("Y is %d\n", y);
    switch (c % 2) {
        case (0):
            printf("C is even.\n");
            break;
        case (1):
            printf("C is odd.\n");
            break;
    }  
    return 0;

}
/* Add function associated with 1/29/2019 classwork assignment involving 
compilers. Adds input parameters and returns their sum.

    x       : First parameter, must be an integer.
    y       : Second parameter, must be an integer.
    returns : Integer sum of parameters x and y. 
   
*/
int add(int x, int y) {
    int z = x + y;
    return z;
}
