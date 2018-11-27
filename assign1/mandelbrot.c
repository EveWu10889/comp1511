// Assignment 1 Mandelbrot: Mandelbrot generation functions
// mandelbrot.c
//
// Completed by
// Yuanyuan Wu (z5232108)
//
// Modified on 2018-08-25
// Tutor's name (day05-lab)
//
// Version 1.0.2: Fix minor typos in comments.
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include <stdio.h>

// Add your own #includes here
#include <math.h>
#include "mandelbrot.h"
#include "pixelColor.h"
// Add your own #defines here
#define TRUE 1
#define FALSE 0
// Add your own function prototypes here
struct complex complexAdd(struct complex a, struct complex b);
struct complex complexMul(struct complex a, struct complex b);
double complexAbs(struct complex c);
int isMandelbrot (int steps);
struct complex cal_O(struct complex center, double half_length);

// Take a pixel grid and and the path from the web browser used to
// request the 'tile'.
//
// The requestPath will be in the form "/mandelbrot/2/{zoom}/{x}/{y}.bmp".
// In the query, 'x' and 'y' are decimals and describe the 'center' of the
// tile and need to be converted into a complex number.
// 'zoom' is an integer representing the zoom level for the tile.
void serveMandelbrot(
                     struct pixel pixels[TILE_SIZE][TILE_SIZE],
                     char *requestPath
                     ) {
    struct complex center = {0.0, 0.0};
    int z = 7;
    
    sscanf(
           requestPath,
           "/mandelbrot/2/%d/%lf/%lf.bmp",
           &z, &center.re, &center.im
           );
    
    // Use drawMandelbrot to draw the image.
    drawMandelbrot(pixels, center, z);
}

// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(
                    struct pixel pixels[TILE_SIZE][TILE_SIZE],
                    struct complex center,
                    int z
                    ) {
    // TODO: COMPLETE THIS FUNCTION
    double d = pow(2, -z); // The distance between two pixels
    double half_length = d * (TILE_SIZE / 2); // Half length of the big pixel
    //printf("half length %lf",half_length);
    struct complex oriPoint = cal_O(center, half_length);
    struct complex currentPoint = oriPoint;
    int y = 0;
    int x = 0;
    //double mini_length = pow(2, -z);
    
    // build the pixels from bottom to top
    while (y < TILE_SIZE) {
        x = 0;
        currentPoint.re = oriPoint.re;
        while (x < TILE_SIZE) {          
            currentPoint.re += d;   // Calculate each point, and build from the real part
            // Check whether the point belongs to Mandelbrot set, and draw it
            int step = escapeSteps(currentPoint);
            pixels[y][x] = pixelColor(step);
            x++;
        }
        currentPoint.im += d;  // Calculate each point, and build from the imaginary part
        y++;
    }
}

        
    

    /*for(int y = O.im; y < TILE_SIZE; y++) {
        for(int x = O.re; x < TILE_SIZE; x++) {
            if (isMandelbrot()) {
                pixelColor(steps);
            }
            else {
                pixels[y][x] = white();  //????    
            }         
        }
        printf("\n");    
    }*/  


// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(struct complex c) {
     // TODO: COMPLETE THIS FUNCTION
    struct complex w;
    w.re = 0;
    w.im = 0;
    int steps = 0;
   
    while (steps < MAX_STEPS && complexAbs(w) < 2) {
        w = complexAdd (complexMul(w, w), c);
        steps++;
    }   
    return steps;
}

// Add your own functions here.
// Remember to make them static.

// Add two complex numbers
struct complex complexAdd(struct complex a, struct complex b) {
    struct complex result;
    // result = (a.re + b.re) + (a.im + b.im)i
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result; 
}

// Multiply two complex numbers 
struct complex complexMul(struct complex a, struct complex b) {
    struct complex result;
    // result = (a.re * b.re - a.im * b.im) + (a.im * b.re + a.re * b.im)i
    result.re = a.re * b.re - a.im* b.im;
    result.im = a.im * b.re + a.re * b.im;
    return result; 
}

// Calculate the absolute value of the complex number
double complexAbs(struct complex c) {
    double result = 0;
    double sum = c.re * c.re + c.im * c. im;
    result = sqrt(sum);
    return result; 
}

// Check whether it belongs to Mandelbrot set
int isMandelbrot (int steps) {
    if (steps < MAX_STEPS) {
        return FALSE; // Outside
    } else {
        return TRUE; // Inside
    }

}

// Calculate the original point
struct complex cal_O(struct complex center, double half_length) {
    struct complex O;
    O.re = center.re - half_length;
    O.im = center.im - half_length;
    return O;
}



