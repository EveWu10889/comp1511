
// Test file to test the function "arrayPositiveMin".
// 

#include <stdio.h>
#include <math.h>

int arrayPositiveMin(int a[], int size);


void checkArrayPositiveMin(int test_no, int a[], int size, int expected_answer) {

    int student_answer = arrayPositiveMin(a, size);
    
    printf("------------- \n");
    if (student_answer == expected_answer) {
        printf("Test %d Passed\n\n", test_no );
        return ;
    }
    
    printf("Test %d Failed!, see below for the expected answer.\n", test_no);
    int i = 0;
    printf("  Array is: ");
    while (i < size) {
        printf("%d, ", a[i]);
        i++; 
    }
    printf("\n");
    printf("  Average Positive Min, expected: %d, your answer: %d\n\n", expected_answer, student_answer);

}

int main(int argc, char *argv[]) {
 
    int a1[]  = {4, 2, 9};
    checkArrayPositiveMin(1, a1, 3, 2); 
    
    int a2[]  = {5, -6, 3 , 20};
    checkArrayPositiveMin(2, a2, 4, 3);     
    
    int a3[]  = {-5, 6, -12 , 5, 0, -2 , 8};
    checkArrayPositiveMin(3, a3, 7, 5);   
        
    // Add more test cases here ... 
    int a4[]  = {0, 0, 0, 0, 0, -2 , 0};
    checkArrayPositiveMin(4, a4, 7, 0); 
    
    int a5[]  = {10, 0, -12, -5, 0, -2, 8};
    checkArrayPositiveMin(5, a5, 7, 8); 
    
    int a6[]  = {-5, -6, -12 , -5, 0, -2, 0};
    checkArrayPositiveMin(6, a6, 7, 0); 
    
    int a7[]  = {-5, 6, -12};
    checkArrayPositiveMin(7, a7, 3, 6); 
    
    int a8[]  = {8};
    checkArrayPositiveMin(8, a8, 1, 8); 
    
    int a9[]  = {0, -2 , 8};
    checkArrayPositiveMin(9, a9, 3, 8); 
    
    int a10[]  = {0, -2};
    checkArrayPositiveMin(10, a10, 2, 0); 

    return 0;
}


