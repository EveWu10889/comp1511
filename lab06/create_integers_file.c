// This is a simple program which creates a file of given name containing the given integers.
// Author: Yuanyuan Wu
// Date: 31/8/2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[3],"w");
    if (f == NULL) {
        fprintf(stderr, "%s: open of '%s' failed\n", argv[0],argv[3]);    
    }
    if (argv[1] < 0 || argv[2] < 0) {
        fprintf(stderr,"please enter two positive numbers\n");          
    }
    
    for(int i = atoi(argv[1]); i <= atoi(argv[2]); i++) {
        fprintf(f,"%d\n", i);        
    }
    
    fclose(f);
    return 0;
}
