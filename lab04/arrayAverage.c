// Find the average of the values in a given array.
// By Yuanyuan Wu (z5232108)
// Written on 2018-08-12
// Tutor (day05-lab)

// You need to implement this function

// Calculates the average of all the values in a given array,
// and returns the average value.
double arrayAverage(int a[], int size) {

    // implement this function and 
    // change return value

    double average = 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];    
    }
    average = sum / size;
    return average ;

}
