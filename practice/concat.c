#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int main () {
    char a1[MAX];
    char a2[MAX];
    char a3[MAX];
    
    fgets(a1, MAX, stdin);
    fgets(a2, MAX, stdin);
    
    int num1 = strlen(a1);
    int num2 = strlen(a2);
    
    for (int i = 0; i < num1-1; i++) {
        a3[i] = a1[i];    
    }
    
    for (int j = 0; j < num2-1; j++) {
        a3[j+num1-1] = a2[j];
    }
    
    //int num3 = strlen(a3);
    int num3 = num1 + num2 - 2;
    
    for(int k = 0; k < num1-1; k++) {
        printf("%c", a1[k]);
    }
    
    printf(" + ");
    
    for(int m = 0; m < num2-1; m++) {
        printf("%c", a2[m]);
    }
    
    printf(" = ");
    
    for(int n = 0; n < num3; n++) {
        printf("%c", a3[n]);
    }
    
    printf("\n");
    return 0;
}
