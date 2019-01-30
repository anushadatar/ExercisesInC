/* cards.c

This file contains code associated with a simple card-counting program.
A user inputs the name of the card and the program tracks the card
count automatically. 
*/

#include <stdio.h>
#include <stdlib.h>

void get_card_name(char *card_name);
int get_card_value(char *card_name);
int compute_count_update(int val);

/* Executes user interface and card counting functionality by calling
   additional functions to obtain user input, determine card valuation,
   and update and report a global count.

   The program is terminated by a user input of the character 'x'.
*/

int main()
{
    char card_name[3];
    int count = 0;
    int val = 0;
    while (card_name[0] != 'x') {
        get_card_name(card_name);
        val = get_card_value(card_name);
        count += compute_count_update(val);
        printf("Current count: %i\n", count); 
    }
    return 0;
}

/* Prompts user to name the card and populates the provided buffer with the 
   card name accordingly.

   The program automatically only considers the first two input characters.
    
   card_name : Buffer associated with the name of the card.
*/ 
void get_card_name(char *card_name)
{
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
}

/*  Determines the numerical value of the card (specified by the first 
    character of the string containing its name) and returns it as an 
    integer value for further processing.
    
    Note this follows a scheme where all face cards are value 10, 
    the Ace card is value 11, and each other card retains its numerical score.

    card_name : Buffer associated with the name of the card. Only the first
                character of the buffer is considered.  
    returns   : Returns the value of the card as an integer.
*/
int get_card_value(char *card_name)
{
     switch (card_name[0]) {                                                 
            case 'K':                                                           
            case 'Q':                                                           
            case 'J':                                                           
                return 10;  
            case 'A':                                                          
                return 11;
            case 'x': 
            default:                                                            
                return atoi(card_name);                                          
        } 
}

/*  Computes the change to the card count dictated by a certain card value
    and returns the value of that change.

    Note that this follows a scheme where all cards between 2 and 7 result
    in an increase in the count, all cards with a value of 10 result in 
    a decrease of a count, and all other values result in no update.

    val     : The value with which to determine the change in the count.
    returns : The amount to add to or subtract from the current count.
*/
int compute_count_update(int val) 
{                             
    if ((val < 1) || (val > 11)) {                                              
        puts("I don't understand that value!");                                 
    }                                                                           
    if ((val > 2) && (val < 7)) {                                               
        return 1;                                                                
    } else if (val == 10) {                                                     
        return -1;                                                       
    }                                                                           
    return 0;
}  
