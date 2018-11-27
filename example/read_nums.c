#include <stdio.h>

#define MAX 1000

int main() {
    //int check = 0;
    int num[1000];
    int i = 0;
    while (scanf("%d", &num[i++]) == 1) {
        if (i != 1) {
            for (int j = 0; j < i-1; j++) {
                if (num[i-1] == num[j]) {
                    printf ("%d is repeated\n", num[i-1]);
                    return 0;
                }
            }
         }
    }

}
