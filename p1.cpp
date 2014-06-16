/**
 * Title:           p1.cpp
 * Name:            Makina Celestine <mcelesti@hunter.cuny.edu>
 * Class:           CSCI 493.69
 * Assignment#:     2
 *
 *
 *
 * Program that converts a gray-level image to a binary one using a threshold value.        
 */
#include "Image.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char **argv)
{
    
	if (argc!=4) 
    {
		printf("Usage: %s {input file} {threshold} {output}\n", argv[0]);
		return 0;
	}
    
    int threshold = 0;
    int greyPixel = 0;
	Image *greyImage;
	greyImage = new Image;
	assert(greyImage!=0);
    threshold = atoi(argv[2]);
    
	if (readImage(greyImage, argv[1])!=0) 
    {
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}
    
    // Apply thresholding to input image
    for (int i = 0; i < greyImage->getNumOfRows(); ++i)
    {
        for (int j = 0; j < greyImage->getNumOfCols(); ++j)
        {
            greyPixel = greyImage->getPixel(i, j);
            if (greyPixel < threshold)
            {
                greyImage->setPixel(i, j, 0); //background; black
            }
            else if (greyPixel >= threshold)
            {
                greyImage->setPixel(i, j, 1); //object; white
            }
        }
    }
    greyImage->setColors(1);
	if (writeImage(greyImage, argv[3])!=0){
		printf("Can't write to file %s\n", argv[2]);
		return 0;
	}
}
