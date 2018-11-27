#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int main (void) {
    char line[MAX];
    while (fgets(line, MAX, stdin)) {
        int num = strlen(line);
        if(num >0 && line[num-1] == '\n') {
            for(int i = num-2; i >= 0; i--) {
                printf("%c", line[i]);
            }
            printf("\n");  
        }
        
    }
    return 0;
}
