// This is a program to translate number to word (1~5)
// Author: Yuanyuan Wu (z5232108)
// Date: 31/7/2018

#include <stdio.h>
int main (void) {
    int num = 0;
   
    printf("Please enter an integer: ");
    scanf("%d",&num);
    
    if(num < 1) {
        printf("You entered a number less than one.\n");    
    }
    else if(num > 5) {
        printf("You entered a number greater than five.\n");
    }
    else if(num >= 1 && num <= 5) {
        if(num == 1) {
            printf("You entered one.\n");
        }
        else if(num == 2) {
            printf("You entered two.\n");
        }
        else if(num == 3) {
            printf("You entered three.\n");
        }
        else if(num == 4) {
            printf("You entered four.\n");
        }
        else if(num == 5) {
            printf("You entered five.\n");
        }
    
    }       
    return 0;
}
