// This is a simple program which given a filename as argument prints the first 10 lines of the file. If the file has less than 10 lines the entire file should be printed.
// Author: Yuanyuan Wu (z5232108)
// Date: 31/8/2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 10
#define MAX 1024

int main (int argc, char *argv[]) {
    if (strcmp(argv[1],"-n") != 0) {
        FILE *f = fopen(argv[1],"r");
        if (f == NULL) {
            fprintf(stderr,"%s: open '%s' file fail\n", argv[0],argv[1]);  
        }
        
        char line[MAX];
        for (int i = 0; i < LINE; i++) {
            if(fgets(line, MAX, f)) {
                fputs(line, stdout);
            }
            else {
                break;
            }
        }
        fclose(f);
    }
    
    else {
        FILE *f = fopen(argv[3],"r"); 
        if (f == NULL) {
            fprintf(stderr,"%s: open '%s' file fail\n", argv[0],argv[3]);  
        } 
        
        int lines = atoi(argv[2]);
        char line[MAX];
        for (int i = 0; i < lines; i++) {
            if(fgets(line, MAX, f)) {
                fputs(line, stdout);
            }
            else {
                break;
            }
        }
        fclose(f); 
               
    }
    
    
   






    return 0;
}

