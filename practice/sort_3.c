#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_3 (double * x, double * y, double *z);

int main () {
    double x, y ,z;
    if(scanf("%lf %lf %lf", &x, &y, &z) == 3) {
        printf("Original: %.2lf %.2lf %.2lf\n", x, y, z);
    }
    sort_3(&x, &y, &z);
    printf("Sorted: %.2lf %.2lf %.2lf\n", x, y, z);
    return 0;
}

void sort_3 (double * x, double * y, double *z) {
    if(*x > *y) {
        double temp = *y;
        *y = *x;
        *x = temp;
         
    } 
    
    if (*x > *z) {
        double temp = *z;
        *z = *x;
        *x = temp; 
        
    } 
    
    if (*y > *z) {
        double tmp = *y;
        *y = *z;
        *z = tmp;
     
    }   
}


