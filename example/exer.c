#include <stdio.h>

int main(void) {
    int a[10];
    int b[10];
    
    for (int i = 0; i < 10; i++) {
        a[i] = 77;
    }

     for (int j = 0; j <= 12; j++) {
        b[j] = 58;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf ("\n");
}
