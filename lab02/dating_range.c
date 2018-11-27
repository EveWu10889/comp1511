// This is a program that calculates the age of someone you can date with
// Author: Yuanyuan Wu (z5232108)
// Date: 31/7/2018

#include <stdio.h>
int main (void) {
    int num = 0;
    int min_num = 0;
    int max_num = 0;
    
    printf("Enter your age: ");
    scanf("%d",&num);
    // The minimum age you can date
    min_num = num / 2 + 7;
    // The maxmum age you can date
    max_num = (num - 7) * 2;
    
    if(min_num > num) {
        printf("You are too young to be dating.\n");
    }
    else {
        printf("Your dating range is %d to %d years old.\n", min_num, max_num);
    }
    return 0;
}
