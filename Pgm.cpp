/**
 * Title:           Pgm.cpp
 * Name:            Makina Celestine <mcelesti@hunter.cuny.edu>
 * Class:           CSCI 493.69
 * Assignment#:     2
 * Created:         
 *
 * Revisions:
 *
 *
 * Notes:           This is the implementation for the Pgm class.
 *                  Uses the sample code given for this assignment.
 *                  All rights go to Copyright: Anton Nikolaev, 1995
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Image.h"


/* readImage
 *
 * Purpose: Reads an image from fname
 * @return: 0 if image was read OK
            -1 if unsuccessful
 *
 */
int readImage(Image *img, const char *filename)
{
    FILE *input;
    char line[1024];
    int nCols,nRows;
    int levels;
    int i, j;
    
    
    /* open it */
    if (!filename || (input = fopen(filename,"r")) == 0){
        printf("readImage: Cannot open file\n");
        return -1;
    }
    
    // check for the right "magic number" 
    // i.e identify that the file type is pg,
    if (fread(line,1,3,input)!=3 || strncmp(line,"P5\n",3))
    {
        fclose(input);
        printf("readImage: Expected .pgm file\n");
        return -1;
    }
    
    /* skip the comments */
    do
        fgets(line,sizeof line,input);
    while(*line == '#');
    
    /* read the width and height */
    sscanf(line,"%d %d\n",&nCols,&nRows);
    img->setSize(nRows, nCols);
    
    /* read # of gray levels */
    fgets(line,sizeof line,input);
    sscanf(line,"%d\n",&levels);
    img->setColors(levels);
    
    /* read pixel row by row */
    for(i=0;i<nRows;i++)
    {
        for(j=0;j<nCols;j++)
        {
            int byte=fgetc(input); // value of pixel
            
            if (byte==EOF) /* short file */
            {
                fclose(input);
                printf("readImage: short file\n");
                return -1;
            }
            else
                img->setPixel(i,j,byte);
        }
    }
    
    /* close the file */
    fclose(input);
    return 0; /* OK */
}

/* writeImage
 * 
 * Purpose: Writes the image into filename;
 * @return: 0 if successful
            -1 if unsuccessful
 */
int writeImage(const Image *img, const char *filename)
{
    FILE *output;
    int nRows;
    int nCols;
    int colors;
    int i, j;
    
    /* open the file */
    if (!filename || (output=fopen(filename,"w"))==0){
        printf("writeImage: cannot open file\n");
        return(-1);
    }
    
    nRows=img->getNumOfRows();
    nCols=img->getNumOfCols();
    colors=img->getColors();
    
    printf("Saving image of size %d %d\n", nRows, nCols);
    
    /* write the header of the output pgm file */
    fprintf(output,"P5\n"); /* magic number */
    fprintf(output,"#\n");  /* empty comment */
    fprintf(output,"%d %d\n%03d\n",nCols,nRows,colors); /* image info */
    
    /* write pixels row by row */
    for(i=0;i<nRows;i++)
    {
        for(j=0;j<nCols;j++)
        {
            int byte=img->getPixel(i,j);
            
            if (fputc(byte,output)==EOF) /* couldn't write */
            {
                fclose(output);
                printf("writeImage: could not write\n");
                return -1;
            }
        }
    }
    
    /* close the file */
    fclose(output);
    return 0; /* OK */
}

