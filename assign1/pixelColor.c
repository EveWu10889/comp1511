// Assignment 1 Mandelbrot: Pixel coloring functions
// pixelColor.c
//
// Completed by
// Yuanyuan Wu (z5232108)
//
// Modified on 2018-08-25
// Tutor's name (day05-lab)
//
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include "mandelbrot.h"
#include "pixelColor.h"

#include <stdio.h>
#include <math.h>
// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
struct pixel pixelColor(int steps) {
    struct pixel color = {
        .red = steps,
        .green = steps ,
        .blue = steps,
    };
    
    // TODO: Change the color of the pixel for different numbers of
    // steps.
    // Draw outside and make it colorful using math function(not belongs to Mandelbrot set)
    if (steps < MAX_STEPS ) {
        //printf("%d",color.red);
        //printf("*****************\n");
        color.red = (int)(cos(steps) * steps * 100) % 255;
        color.green = (steps * 58) % 255;
        color.blue = (int)(sin(steps) * steps * 100) % 255;
    } 
    // Draw inside (belongs to Mandelbrot set)
    else {
        color.red = 0;
        color.green = 0;
        color.blue = 0; 
    }  
    
    return color;
}
