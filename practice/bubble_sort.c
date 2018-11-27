#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int *v, int len);

int main(int argc, char *argv[]) {
    int len;
    
    if (argc == 1) {
        fscanf(stdin, "%d", &len);
        int *v = malloc(sizeof(int) * len);  
        for (int i = 0; i < len; i++) {
            fscanf(stdin, "%d", &v[i]);       
        }
        bubble_sort(v, len);
        for (int j = 0; j < len; j++) {
            printf("%d ", v[j]);
        }
        printf("\n");
        free(v); 
    } else if (argc == 2) {
        FILE *fi = fopen("argv[1]", "r");
        fscanf(fi, "%d", &len);
        int *v = malloc(sizeof(int) * len);  
        for (int i = 0; i < len; i++) {
            fscanf(fi, "%d", &v[i]);       
        }
        bubble_sort(v, len);
        for (int j = 0; j < len; j++) {
            printf("%d ", v[j]);
        }
        printf("\n");
        fclose(fi);
        free(v);
    } else if (argc == 3) {
        FILE *fi = fopen("argv[1]", "r");
        FILE *fo = fopen("argv[2]", "w+");
        fscanf(fi, "%d", &len);
        int *v = malloc(sizeof(int) * len);  
        for (int i = 0; i < len; i++) {
            fscanf(fi, "%d", &v[i]);       
        }
        bubble_sort(v, len);
        for (int j = 0; j < len; j++) {
            fprintf(fo, "%d ", v[j]);
        }
        fprintf(fo, "\n");
        fclose(fi);
        fclose(fo);
        free(v);
    }
        
    return 0;
}

void bubble_sort(int *v, int len) {
    int sort = 0;
    while (sort == 0) {
        sort = 1;
        
        for(int i = 1; i < len; i++) {
            if(v[i-1] > v[i]) {
                int temp = v[i];
                v[i] = v[i-1];
                v[i-1] = temp;
                sort = 0;
            }
        }
        
    }
}
