// Print Wondrous
// Created by
// Yuanyuan Wu (z5232108)
// Created on 2018-08-14
// Tutor's name (day05-lab)

#include <stdio.h>
#include <stdlib.h>

#define N 65536

int printWondrous(int num);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    // Get the number.
    int number;
    printf ("Enter a number: ");
    scanf("%d", &number);

    // Call printWondrous and save the count.
    int count = printWondrous(number);

    printf("The count is %d.\n", count);

    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION

int printWondrous(int num) {
    // PUT YOUR CODE HERE
    int count = 0;
    int array[50] = {0};
    array[0] = num;
    count++;
    for(int i = 0; i < 50 && array[i] > 1; i++) {
        //int j = i + 1;
        if(array[i] % 2 == 0) {        
            array[i + 1] = array[i] / 2;       
        } 
        else {
            array[i + 1] = 3 * array[i] + 1;
        }
        count++;    
    }
    for(int k = 0; k < count; k++) {
        printf("%d ",array[k]);    
    }
    printf("\n");
    
    return count; // CHANGE THIS TO YOUR RETURN VALUE
}
