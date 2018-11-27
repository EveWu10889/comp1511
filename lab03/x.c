/* This is a simple program that reads an integer n from standard input. and prints an nxn pattern of asterisks and dashes in the shape of an "X". */
// Author: Yuanyuan Wu (z5232108)
// Date: 10/8/2018

#include <stdio.h>

int main (void) {
    int i = 0;
    int j = 0;
    int n = 0;
    int num = 0;
    
    printf("Enter size: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j == i || j == n-i-1) {
                printf("*");
            }
            else {      
                printf("-");
            }
        }
    printf("\n");
    }
/*   for(i = n-1; i > n/2 ; i--) {
        for(j = n-1; j > 0; j--) {
            if(j == i || j == n-j-1) {
                printf("*");
            }
            else {      
                printf("-");
            }
        }
    printf("\n");
    }
*/

    return 0;
}
