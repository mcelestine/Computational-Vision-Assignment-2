/**
 * Title:           Image.h
 * Name:            Makina Celestine <mcelesti@hunter.cuny.edu>
 * Class:           CSCI 493.69
 * Assignment#:     2
 * Created:         
 *
 * Revisions:
 *
 *
 * Notes:           This is the implementation for the Image class.
 *                  Uses the sample code given for this assignment.
 *
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Image
{
public:
    Image();                        // Default constructor
    Image (const Image &im);        // Copy constructor
    ~Image();                       // Destructor
    
    
    /* setSize
     * Purpose: sets the size of the image to the given
     *          height (# of rows) and width (# of columns).
     * @return: 0 if OK or -1 if fails
     */
    int setSize(int rows, int columns);
    
    /* getNumOfCols
     *
     * @return: the number of columns in the image.
     */
    int getNumOfCols()const
    {
        return numOfCols;
    };
    
    /* getNumOfRows
     *
     * @return: the number of rows in the image.
     */
    int getNumOfRows()const
    {
        return numOfRows;
    };
    
    /* setColors
     *
     * Purpose: Sets the number of gray-level colors in the image
     *          (not counting 0)
     *
     * @return: 0 if OK or -1 if fails
     */
    int setColors(int colors);
    
    /*
     returns the number of gray-level colors in the image;
     */
    int getColors()const
    { 
        return numOfColors; 
    };
    
    /*
     sets the pixel in the image at row i and column j
     to a particular color;
     */
    int setPixel( int i, int j, int color);
    
    /*
     returns the color of the pixel in the image at row i and column j;
     */
    int getPixel( int i, int j )const;

 private:
  int numOfRows; /*number of rows */
  int numOfCols; /*number of columns */
  int numOfColors; /*number of gray level colors */
  int **image;
  
};


/*
 functions for read-write pgm images
*/

int readImage(Image *im, const char *filename);
int writeImage(const Image *im, const char *filename);

/*
function for drawing a line
*/

int line(Image *&im, int x0, int y0, int x1, int y1, int color);

#endif
