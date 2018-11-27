#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 100;
	char c = (char) i;
	int *ip = (int *) i;
	int nums[] = {0};
	printf("%c\n", (char) i );
	printf("%s\n", (char *) &i );
	printf("%s\n", (char*) nums);
	return 0;
}
