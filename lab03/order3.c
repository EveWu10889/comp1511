// This is a C program to order three intergers
// Author: Yuanyuan Wu (z5232108) 
// Date: 3/8/2018

#include <stdio.h>

void swap(int *a, int *b);

int main (void) {
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    
    printf("Enter integer: ");
    scanf("%d",&n1);
    printf("Enter integer: ");
    scanf("%d",&n2);
    printf("Enter integer: ");
    scanf("%d",&n3);

    // order three numbers
    if(n1 >= n2) {
        swap(&n1, &n2);
        if(n2 >= n3) {
            swap(&n2,&n3);
        }
    }     
    else if(n1 <= n2) {
        if (n2 >= n3) {
            swap(&n2,&n3);
        }
    }
    
    if(n1 >= n2) {
        swap(&n1, &n2);
        if(n2 >= n3) {
            swap(&n2,&n3);
        }
    }     
    else if(n1 <= n2) {
        if (n2 >= n3) {
            swap(&n2,&n3);
        }
    }
    
/*    int array[3] = { 0 };
    array[0] = n1;
    array[1] = n2;
    array[2] = n3;
    int changes_made = 1;
    while (changes_made) {
        changes_made = 0;
        for (int i = 0; i < 2; i++) {
            if (array[i] > array[i+1]) {
                changes_made = 1;
                swap(&array[i], &array[i+1]);
            }
        }
    }
    
    printf("The integers in order are: %d %d %d\n", array[0], array[1], array[2]);
*/
    printf("The integers in order are: %d %d %d\n",n1,n2,n3);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
