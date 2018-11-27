// Draw a 512x512 chessboard
// By Yuanyuan Wu (z5232108)
// Written on 2018-08-13
// Tutor (day05-lab)

// Remember to pipe the output of this program into a file
// $ ./chessboard > chessboard.bmp
// $ eog chessboard.bmp &

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_SIZE   512
#define SQUARE_SIZE  (512 / 8)
#define FALSE 0
#define TRUE 1

// For writing BMP
#define PIXEL_START 26
#define PIXEL_BYTES 3
#define PIXEL_ALIGN 4
#define PIXEL_BITS  24
#define HEADER_SIZE 12

typedef unsigned char color;

typedef struct _pixel {
    color red;
    color green;
    color blue;
} pixel;

void drawChessboard(pixel pixels[BOARD_SIZE][BOARD_SIZE]);
int sameIndex (int y, int x);

// Write an image to output
void writeImage(int output, pixel pixels[BOARD_SIZE][BOARD_SIZE]);

int main(int argc, char *argv[]) {
    // Pixel 2-dimensional array
    // remember, it's pixels[y][x]
    pixel pixels[BOARD_SIZE][BOARD_SIZE];

    drawChessboard(pixels);

    // Write the image to output
    writeImage(STDOUT_FILENO, pixels);

    return EXIT_SUCCESS;
}

pixel white () {
    pixel white_pix;
    white_pix.red = 255;
    white_pix.green = 255;
    white_pix.blue = 255;
    return white_pix;
}

pixel black () {
    pixel black_pix;
    black_pix.red = 0;
    black_pix.green = 0;
    black_pix.blue = 0;
    return black_pix;
}

int isBlack (int y, int x) {
    int i = FALSE;
    if (sameIndex(y, x)) {
        i = TRUE;
    }
    return i;
}

int sameIndex (int y, int x) {
    int i = FALSE;
    if (y / SQUARE_SIZE % 2 == x / SQUARE_SIZE % 2) {
        i = TRUE;
    }
    return i;
}

// Draws a chessboard
void drawChessboard(pixel pixels[BOARD_SIZE][BOARD_SIZE]) {
    //pixel draw_white = white();
    //pixel draw_black = black();
    
    for(int y = 0; y < BOARD_SIZE; y++) {
        for(int x = 0; x < BOARD_SIZE; x++) {
            if (isBlack(y, x)) {
                pixels[y][x] = black();
            }
            else {
                pixels[y][x] = white();      
            }         
        }
        printf("\n");    
    }

}

// Writes the pixels as a BMP file using the specification from
// https://en.wikipedia.org/wiki/BMP_file_format
void writeImage(int output, pixel pixels[BOARD_SIZE][BOARD_SIZE]) {
    // Initial BM bytes
    write(output, "BM", 2);

    // File size
    unsigned int rowSize = BOARD_SIZE * PIXEL_BYTES;
    unsigned int rowPadding = 0;
    if (rowSize % PIXEL_ALIGN != 0) {
        // Padd pixel to align properly
        rowPadding = PIXEL_ALIGN - (rowSize % PIXEL_ALIGN);
        rowSize += rowPadding;
    }

    unsigned int fileSize = PIXEL_START + (rowSize * BOARD_SIZE);
    write(output, (char *)&fileSize, sizeof(fileSize));

    // 4 reserved bytes
    write(output, "\0\0\0\0", 4);

    // start of pixel data
    // pixels start immediately after header
    unsigned int pixelStart = PIXEL_START;
    write(output, (char *)&pixelStart, sizeof(pixelStart));

    // Size of header
    unsigned int headerSize = HEADER_SIZE;
    write(output, (char *)&headerSize, sizeof(headerSize));

    // Image width and height
    unsigned short size = BOARD_SIZE;
    write(output, (char *)&size, sizeof(size));
    write(output, (char *)&size, sizeof(size));

    // Number of image planes (1)
    unsigned short planes = 1;
    write(output, (char *)&planes, sizeof(planes));

    // Number of bits per pixel (24)
    unsigned short bitsPerPixel = PIXEL_BITS;
    write(output, (char *)&bitsPerPixel, sizeof(bitsPerPixel));

    // Write each of the pixels
    unsigned int padding = 0x01234567;
    int y = 0;
    while (y < BOARD_SIZE) {
        int x = 0;
        while (x < BOARD_SIZE) {
            // Write the blue, green, then red pixels
            pixel pixel = pixels[y][x];
            write(output, &(pixel.blue), sizeof(pixel.blue));
            write(output, &(pixel.green), sizeof(pixel.green));
            write(output, &(pixel.red), sizeof(pixel.red));
            x++;
        }

        // Write the row padding bytes
        write(output, (char *)&padding, rowPadding);
        y++;
    }
}
