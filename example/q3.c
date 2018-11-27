#include <stdio.h>
#include <string.h>

int main(void) {
    char *s = "hello";
    char i = strlen(s);
    printf("%c%d\n", s[0], i);
    return 0;
}
