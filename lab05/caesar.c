// This is a simple C program which reads characters from its input and writes the characters to its output encrypted with a Caesar cipher.
// Author: Yuanyuan Wu (z5232108)
// Date: 21/8/2018

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int encrypt(int character, int shift);

int main(int argc, char *argv[]) {
    int shift = atoi(argv[1]);
    int ch = getchar();
    
    while(ch != EOF) {
        ch = encrypt(ch,shift);
        putchar(ch);
        ch = getchar();
    }     
}

int encrypt(int character, int shift){
    shift = shift % 26;
    if(shift > 0) {
        if (character >= 'a' && character <= 'z') {
            int new_char = character - 'a';
                new_char = (new_char + shift) % 26;
                character = 'a' + new_char;
        }
        else if (character >= 'A' && character <= 'Z') {
            int new_char = character - 'A';
                new_char = (new_char + shift) % 26;
                character = 'A' + new_char;   
        }
    }
    else {
        if (character >= 'a' && character <= 'z') {
            
             int new_char = character - 'a';
             shift = (shift % 26) + 26;
             new_char = (new_char + shift) % 26;
             character = 'a' + new_char;
        }
        else if (character >= 'A' && character <= 'Z') {
                int new_char = character - 'A';
                shift = (shift % 26) + 26;
                new_char = (new_char + shift) % 26;
                character = 'A' + new_char;   
        }
    
    }
    return character;
}
