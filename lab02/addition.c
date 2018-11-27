// This is a program that does addition operation
// Author Yuanyuan Wu (z5232108)
// Date 31/7/2018

#include <stdio.h>
int main (void) {
    int num_1 = 0;
    int num_2 = 0;
    int sum = 0;
    
    printf("Please enter two integers: ");
    scanf("%d %d", &num_1,&num_2);
    
    // Do the addition operation
    sum = num_1 + num_2;
    printf("%d + %d = %d\n",num_1,num_2,sum);
    return 0;
}
