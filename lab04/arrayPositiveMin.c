// Find and return the minimum positive value
// from the values in a given array.
// By Yuanyuan Wu (z5232108)
// Written on 2018-08-13
// Tutor (day05-lab)


// You need to implement this function

// Returns the minimum positive value from a given array.
// A value is a positive value if it is greater than zero.
// If there are no positive values in a given list,
// the function should return zero.

int arrayPositiveMin(int a[], int size) {
 
    // Implement this function 
    // You also need to change the return value.
    int min = 0;
    for(int i = 0; i < size; i++) {
        if (a[i] > 0) {
            min = a[i];
            break;
        }
    }
    
    for(int i = 0; i < size; i++) {
        if (a[i] > 0 && a[i] < min) {
            min = a[i];
        }   
    }
       
    return min;
}
