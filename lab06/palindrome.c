// This is a simple program which reads a string and tests if it is a palindrome.
// Author: Yuanyuan Wu (z5232018)
// Date: 31/8/2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 4096

int main (void) {
    char line[MAX];
    int count = 0;
    printf("Enter a string: ");
    if (fgets(line, MAX, stdin) != NULL) {
        int i = strlen(line);
        if (i > 0 && line[i-1] == '\n') {
            line[i-1] = '0';
        }  
        
        for (int j = 0; j < (i/2); j++) {
            if (line[j] == line[i-j-2]) {
                //printf("%c",line[j]);
                //printf("%c",line[i-j-2]);
                count++;
                continue;
            }
            else {
                printf("String is not a palindrome\n");
                break;           
            }
        }  
        
        if (count == (i/2)){
            printf("String is a palindrome\n");
        }        
    }
    return 0;
}
