#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE *fi = fopen("fin.txt", "r");
    FILE *fo = fopen("fout.txt", "w");
    
    int sum = 0;
    int len;
    fscanf(fi, "%d", &len);
    
    int *v1 = malloc(sizeof(int) * len);
    int *v2 = malloc(sizeof(int) * len);
    
    for(int i = 0; i <len; i++) {
        fscanf(fi, "%d", &v1[i]);
    }   
     
    for(int i = 0; i <len; i++) {    
        fscanf(fi, "%d", &v2[i]);
    }    
    
    for(int i = 0; i <len; i++) {   
        sum += v1[i] * v2[i];
    }
    
    fprintf(fo, "%d\n", sum);
    
    fclose(fi);
    fclose(fo);
    
    free(v1);
    free(v2);
    //remember to free;
    return 0;

}
