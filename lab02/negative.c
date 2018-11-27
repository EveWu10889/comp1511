//This is a program to check whether the number is negative or not
// Author Yuanyuan Wu (z5232108)
// Date 31/7/2018

#include <stdio.h>
int main (void) {
    int num = 0;
    
    scanf("%d",&num);
    
    if(num < 0) {
        printf("Don't be so negative!\n");
    }
    else if(num > 0) {
        printf("You have entered a positive number.\n");
    }
    else if(num == 0) {
        printf("You have entered zero.\n");
    }
    return 0;
}
