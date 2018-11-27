#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);
    for(int i = 0; i < num; i++) {
        if (i == 0 || i == num / 2) {
            for(int j = 0; j < num; j++) {
                printf("#");
            }
        } else {
            for(int j = 0; j < num; j++) {
                if (j == 0 || j == num-1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");       
    }
    return 0;
}
