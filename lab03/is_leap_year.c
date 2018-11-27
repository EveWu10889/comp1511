//This is a simple c progranm to check whether it is a leap year
//Author: Yuanyuan Wu (z5232108)
//Date: 10/8/2018

#include <stdio.h>

int main (void) {
    int year = 0;
    printf("Enter year: ");
    scanf("%d",&year);
    
    if (year % 4 != 0) {
        printf("%d is not a leap year.\n",year);
    }
 
    else if (year % 100 != 0) {
        printf("%d is a leap year.\n",year);
    }

    else if (year % 400 != 0) {
        printf("%d is not a leap year.\n",year);
    }

    else {
        printf("%d is a leap year.\n",year);
    
    }
    
    return 0;
}
