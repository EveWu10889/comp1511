// This is a simple program which reads characters from its input until end of input. And It should then print the occurrence frequency for each of the 26 letters 'a'..'z'.
// Author: Yuanyuan Wu (z5232108)
// Date: 21/08/2018

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct words {
    int ch;
    float frequency;
    int count;
}words;

int main(void){
    words word[26];
    
    int x = 'a';
    float sum = 0;
    for (int i = 0; i < 26; i++) {
        word[i].ch = x;
        x++; 
        word[i].count = 0;        
    }
    int cha = getchar();
    while(cha != EOF) {
        if (cha >= 'A' && cha <= 'Z') {
            cha = tolower(cha);
        } 
        if(cha >= 'a' && cha <= 'z'){
            sum++;
        }
        for (int j = 0; j < 26; j++){
            if(cha - word[j].ch == 0) {
                word[j].count++; 
            }
            
        }
        cha = getchar();   
    }
    //printf("%lf",sum);
    //printf("*******************************");
    for(int k = 0; k < 26;k++){
        word[k].frequency = word[k].count / sum;    
    }
    
    for(int m = 0; m < 26; m++) {
        printf("'%c' %.6lf %d\n",word[m].ch, word[m].frequency, word[m].count);
    }
    
    return 0;
}
     
