#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {    
    
    FILE *fin = fopen("fin.txt","r" );
    FILE *fout = fopen("fopen.txt","w");

    int len;
    fscanf(fin, "%d", &len);
    
    int v1[len];
    int v2[len];
    
    for(int i = 0; i < len; i++){
    
        fscanf(fin, "%d", &v1[i]);
    
    }
    for(int i = 0; i < len; i++){
    
        fscanf(fin, "%d", &v2[i]);
    
    }
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += v1[i]*v2[i];
    
    }
    
    fprintf(fout, "%d\n", sum);
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}
