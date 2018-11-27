#include <stdio.h>
#include <string.h>


#define MAX 1000

int main () {
    char line[MAX];
    printf ("Input: ");
    fgets(line, MAX, stdin);
    int length = strlen(line);
    //printf("%d\n", length);
    if (length > 0) {
        printf("Output: ");
        for(int i = 0; i < length; i++) {
           if(line[i] >= 'a' && line[i] <= 'z') {
            //printf("I am lower\n");
                //toupper(line[i]);
                printf("%c", line[i]-32);
           } else if (line[i] >= 'A' && line[i] <= 'Z') {
                //tolower(line[i]);
                printf("%c", line[i]+32);
           } else {
                printf ("%c", line[i]);
           }
        }
        //printf("\n");
    }
    
    return 0;
}
