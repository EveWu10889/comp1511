/* This is a simple program that finds number of values that are outside the range of 5 to 25. */
// Author: Yuanyuan Wu (z5232108)
// Date: 10/8/2018

#include <stdio.h>

int main (void) {
    int num = 0;
    int count = 0;

    printf("Enter number: ");
        
    while(scanf("%d", &num) == 1) {
        if(!(num >= 5 && num <= 25)) {
            count ++;                     
        }
        printf("Enter number: ");
    }
  
    printf("\n");
    printf("Outliers: %d\n", count);
    return 0;
}
