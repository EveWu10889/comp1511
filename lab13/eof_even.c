#include <stdio.h>

#define MAX_NUM  10000

int main (){
    int num;
    int even[MAX_NUM];
    int i = 0;
    while (scanf("%d", &num) == 1) {
        if(num % 2 == 0) {
            even[i++] = num;
        }
    }
    for (int j = 0; j < i; j++){
        printf("%d ", even[j]);
    }
    printf("\n");
}
