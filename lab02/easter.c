/* This is a program to calculates the date of Easter Sunday for the entered year */
// Author: Yuanyuan Wu (z5232108)
// Date: 31/7/2018

#include <stdio.h>
int main (void) {
    int year = 0;
    
    printf("Enter Year: ");
    scanf("%d", &year);
   
    // Do some operations to get some parameters
    int a = year%19;
    int b = year/100;
    int c = year%100;
    int d = b/4;
    int e = b%4;
    int f = (b+8)/25;
    int g = (b-f+1)/3;
    int h = (19*a+b-d-g+15)%30;
    int i = c/4;
    int k = c%4;
    int l = (32+2*e+2*i-h-k)%7;
    int m = (a+11*h+22*l)/451;
    // Get the month of Easter in the entered year
    int Easter_Month = (h+l-7*m+114)/31; 
    int p = (h+l-7*m+114)%31;
    // Get the date of Easter in the entered year
    int Easter_Date = p+1;
   
    printf("Easter is ");
    
    /*  if Easter_Date==3,it is in March; if Easter_Date==4,it is in April */
    if(Easter_Month == 3) {
        printf("March %d in %d.\n",Easter_Date,year);
    }
    else if(Easter_Month == 4) {
        printf("April %d in %d.\n",Easter_Date,year);
    }
    return 0;   
}

