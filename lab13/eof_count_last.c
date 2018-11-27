#include <stdio.h>

#define MAX_NUM 10000
int main() {
    int array[MAX_NUM];
    int num = 0;
    int i = 0;
    int index;
    int count = 0;
    while(scanf("%d", &num) == 1) {
        array[i++] = num;
    }
    index = i - 1;
    
    int last = array[index];
     
    for(int j = 0; j < i; j++) {
        if (last == array[j]) {
            count ++;
        }
    }
    
    printf("%d\n", count);
}
