/* This is a simple program that uses a loop to print a countdown from 10 to 0 */
// Author: Yuanyuan Wu (z5232108)
// Date: 10/8/2018

#include <stdio.h>

int main (void) {   

    int counter = 10; //initialise counter to 10
    
    while (counter >= 0) { // loop until >= 0
        printf("%d\n", counter); // print counter
        counter = counter - 1; // increment counter
    }
    
    return 0;
}

