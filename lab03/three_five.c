/* This is a simple program that reads a positive integer n and print all the positive integers < n divisible by 3 or 5. */
// Author: Yuanyuan Wu (z5232108)
// Date: 10/8/2018

#include <stdio.h>
int main (void) {
    int num = 0;
    printf("Enter number: ");
    scanf("%d",&num);
    
    //print all the positive integer i (i<n) which are divisible by 3 or 5.
    for (int i = 1; i < num; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            printf("%d\n",i);        
        }
    }
    
    return 0;
}
