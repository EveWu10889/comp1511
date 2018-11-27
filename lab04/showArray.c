// Prints out an array.
// Created by
// Yuanyuan Wu (z5232108)
// Created on 2018-08-??
// Tutor's name (day05-lab)

#include <stdio.h>
#include <assert.h>

void show_array(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCITON
int main(int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // Declare the array.
    int array[size];

    printf("Enter array values: ");
    // Initialise the array values.
    int i = 0;
    while (i < size) {
        assert(scanf("%d", &array[i]) == 1);
        i = i + 1;
    }

    show_array(size, array);

    return 0;
}

// Print the array in the format [1, 2, 3, ...]
void show_array(int size, int array[size]) {
    // Put your code here
    printf("[%d",array[0]);
    for(int i = 1; i < size; i++) {
        printf(", %d", array[i]);   
    }
    printf("]\n");
    
}
