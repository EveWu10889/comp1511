/*
 * Test if a point is inside a triangle.
 * Julian Saknussemm
 *
 * Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
 * the triangle.
 *
 * This is determined by satisfying the following rule:
 * A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
 * iff
 * P is on the same side of the line AB as C
 * P is on the same side of the line BC as A
 * and
 * P is on the same side of the line AC as B
 *
 * A special case exits for a vertical line (inf gradient) when testing the side of the line
 */
 // Author: Julian (the original author) && Yuanyuan Wu (z5232108)
 // Date: 10/8/2018
 
#include <stdio.h>
 
int test_side( double px, double py, double m, double b ) {
    if( py < m * px + b ) {
      return -1; // point is under line
    } else if ( py == m * px + b ){
      return 0;  // point is on the line
    } else {
      return 1; // point is above the line
    }
}
 
// two points lie on the same side of a line
int test_same_side( double px, double py, double m, double b, double lx, double ly ) {
    return ( test_side( px, py, m, b ) == test_side( lx, ly, m, b ));
}

int tritest( double x0, double y0, double x1, double y1, double x2, double y2, double px, double py ) {
    int line1, line2, line3;
    // line eqns
 
    double m01, b01, m02, m12, b02, b12;

    if ( x1 != x0 && x2 != x0 && x2 != x1 ) {    
        
        m01 = (y1 - y0) / (x1 - x0);
        // b: y - y1 = m( x - x1 ), x = 0
        b01 = m01 * ( -x1 ) + y1;
        m02 = (y2 - y0) / (x2 - x0);
        m12 = (y2 - y1) / (x2 - x1);
        b02 = m02 * -x2 + y2;
        b12 = m12 * -x2 + y2;
        
    }

    // vertical line checks
    if( x1 == x0 ) {
       line1 = ( (px <= x0) == (x2 <= x0) );
    } else {
        line1 = test_same_side( px, py, m01, b01, x2, y2 );
    }
     
    if( x1 == x2 ) {
        line2 = ( (px <= x2) == (x0 <= x2) );
    } else {
        line2 = test_same_side( px, py, m12, b12, x0, y0 );
    }
     
    if( x2 == x0 ) {
        line3 = ( (px <= x0 ) == ( x1 <= x0 ) );
    } else {
        line3 = test_same_side( px, py, m02, b02, x1, y1 );
    }
     
    return line1 && line2 && line3;
     
}


int main( int argc, char* argv[] ) {
    double x0, y0, x1, y1, x2, y2;
    double px, py;
     
    //int scanfsReturnValueAggregatedOverAllScanfs = 0;
    int scanfs = 0;
     
    // get input
    printf("Please enter two numbers seperated by comma!\n");
    printf("Triangle Vertex A (x,y): "); 
    scanfs += scanf("%lf,%lf", &x0, &y0);
    printf("Triangle Vertex B (x,y): "); 
    scanfs += scanf("%lf,%lf", &x1, &y1);
    printf("Triangle Vertex C (x,y): "); 
    scanfs += scanf("%lf,%lf", &x2, &y2);
    printf("Test Point (x,y): "); 
    scanfs += scanf("%lf,%lf", &px, &py);
     
    // print error
    if( scanfs != 8 ) {
        printf("You're stupid and didn't put in the right inputs!\n");
        return 1;
    }
 
    // print answer
    printf("Point (%.2lf,%.2lf) is ", px, py);
    if( tritest(x0, y0, x1, y1, x2, y2, px, py) ) 
        printf("inside the Triangel\n");
    else 
        printf("outside the Triangel\n");
 
    // return 0
    return 0;
}

// In this program, I think there are some simple problems that make it unreadable, especially the coding style.
// For example, the missed space between brakets and characters, variables and variables,  
// operators and characters, and some regular spaces for every lines or statements. 
// The names of the fuctions are also not clear enough, and some of them even too long to read.
// And some statements are not separeted from the last one, that is, it does not go to another line necessarily. 
// But one thing to recommend is that the comments are very clear to understand for readers.





