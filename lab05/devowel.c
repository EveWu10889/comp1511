// This is a simple C program which reads characters from its input and writes the same characters to its output, except it does not write lower case vowels ('a', 'e','i', 'o', 'u').
// Author: Yuanyuan Wu
// Date: 21/8/2018

#include<stdio.h>

int is_vowel(int character);

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        if (!is_vowel(ch)) {
          putchar(ch);  
        }       
        ch = getchar();
    }
    return 0;
}



int is_vowel(int character) {
    int cha = character;
    if (cha == 'a'|| cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u') {
        return 1;  
    }
    return 0;
}

