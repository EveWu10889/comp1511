/* It is a C program that reads a year and then uses a function to calculate whether that year is a leap year. */
//Author: Yuanyuan Wu (z5232108)
//Date: 10/8/2018

#include <stdio.h>

int isLeapYear (int year);

int main (void) {
    int year = 0;
    printf("Enter year: ");
    scanf("%d",&year);
    
    if(!isLeapYear(year)) {
        printf("%d is not a leap year.\n",year);       
    }
    else {
        printf("%d is a leap year.\n",year);
    }
  
    return 0;
}

int isLeapYear (int year) {   
     if (year % 4 != 0) {
        return 0;        
    }
 
    else if (year % 100 != 0) {
        return 1;
    }

    else if (year % 400 != 0) {
        return 0;
    }

    else {
        return 1;
    }
}

