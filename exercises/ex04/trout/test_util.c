/* test_util.c

Minunit test code that runs with the util.c function.
*/

#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <assert.h>                                                             
#include "util.h"                                                           
#include "minunit.h"                                                            
                                                                                
int tests_run = 0;                                                              

/* These tests all involved the functionality of the icmpcode_v4 function. */                       
static char *test1() {                                                          
    char *res = icmpcode_v4(0);
    char *message = "Test failed on error code 0.";
    mu_assert(message, strcmp(res, "network unreachable") == 0);
    return NULL;                                                                
}

static char *test2() {                                                          
    char *res = icmpcode_v4(5);                                                  
    char *message = "Test failed on error code 5.";                             
    mu_assert(message, strcmp(res, "source route failed") == 0);                
    return NULL;                                                                
}                                                     

static char *test3() {                                                          
    char *res = icmpcode_v4(7);                                                  
    char *message = "Test failed on error code 7.";                             
    mu_assert(message, strcmp(res, "destination host unknown") == 0);                
    return NULL;                                                                
}                                                                               

static char * all_tests() {                                                     
    mu_run_test(test1);                                                         
    mu_run_test(test2);                                                         
    mu_run_test(test3);                                                         
    return NULL;                                                                
}                                                                               

/* When compiled alongside util.c itself, all tests should pass! */ 
int main(int argc, char **argv) {                                               
    char *result = all_tests();                                                 
    if (result != NULL) {                                                       
        printf("%s\n", result);                                                 
    } else {                                                                    
        printf("ALL TESTS PASSED\n");
    }                                                                           
    printf("Tests run: %d\n", tests_run);                                       

    return result != 0;
}
