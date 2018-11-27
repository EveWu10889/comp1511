#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int line = (n - 1) * 2;
    for(int i = 0; i <= line; i++) {
        for (int j = 0 ; j <= line; j++) {
            if (i == 0 || i == line) {
                if (j == n-1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if ((col <= n/2 && row <= n/2 && row >= n/2-col) 
             || (col >= n/2 && row <= n/2 && row >= col - n/2)) {
                printf("*");
            } else if ((col<=n/2 && row >= n/2 && row <= n/2 + col)
            || (col >= n/2 && row >= n/2 && row <= 3*n/2 - col- 1)) {
                printf("*");   
            }else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
