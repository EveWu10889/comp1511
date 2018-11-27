// This is a program to count the money enough to buy icecream or not
// Author Yunayuan Wu (z5232108)
// Date 31/7/2018

#include <stdio.h>
int main (void) {
    int num = 0;
    int money = 0;
    int total = 0;

    printf("How many scoops? ");
    scanf("%d",&num);
    printf("How many dollars does each scoop cost? ");
    scanf("%d",&money);
    
    // count the total money needed
    total = num * money;
    
    // check whether money is enough
    if(total > 10) {
        printf("Oh no, you don't have enough money :(\n");
    }
    else {
        printf("You have enough money!\n");
    }
    return 0;   
}
