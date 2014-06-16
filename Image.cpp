/**
 * Title:           Image.cpp
 * Name:            Makina Celestine <mcelesti@hunter.cuny.edu>
 * Class:           CSCI 493.69
 * Assignment#:     2
 * Created:         
 *
 * Revisions:
 *
 *
 * Notes:           This is the definition for the Image class.
 *                  Uses the sample code given for this assignment.
 *
 */

#include "Image.h"

Image::Image()
{
    /* Initialize image class
     * All values are set to zero 
     */
    numOfCols = 0;
    numOfRows = 0;
    numOfColors = 0;
    image = NULL;
}

Image::Image(const Image &rhs)
{
    /* Initialize image class
     * Copy from rhs  
     */
    
  setSize(rhs.getNumOfRows(), rhs.getNumOfCols());
  setColors(rhs.getColors());
  int i,j;
    for (i = 0; i < getNumOfRows(); ++i){
        for (j = 0; j < getNumOfCols(); ++j){
            setPixel(i,j, rhs.getPixel(i,j));
        }
    }
}

Image::~Image()
{
    int i;
    if (image) {
	for (i = 0; i < numOfRows; i++)
	    free(image[i]);
	free(image);
    }
}

/* setSize
 *
 * Allocates space for an rows x columns image.
 * @return: -2 if rows or columns <=0
            -1 if cannot allocate space
            rows * columns if success
 */
int Image::setSize(int rows, int columns)
{

    if (rows <= 0 || columns <= 0){
	cout << "setSize: rows, columns must be positive\n";
	return -2;
    }
    
    // Alocate a new array of pointer which will represent rows
    if ( (image=(int **)malloc(sizeof(int *) * rows)) == NULL )
    {
        cout << "setSize: Can't allocate space. Not enough memory.\n";
        return -1;
    }
    
    for (int i = 0; i < rows; i++) 
    {
        // Allocate columns for each row in the array
        if ( (image[i]=(int *)malloc(sizeof(int) * columns)) == NULL)
        {
            cout << "setSize: can't allocate space\n";
            return -1;
        }
    }

    numOfRows = rows;
    numOfCols = columns;

    return rows*columns;
}


/* setColors
 *
 * Sets the number of gray-levels
 * @return: number of Colors
 */
int Image::setColors(int colors)
{
  numOfColors = colors;
  return numOfColors;
}


/* setPixel
 *
 * sets pixel i, j
 * @return: 0 if the image is empty. 
 *         -1 if error.
 */
int Image::setPixel(int i, int j, int colorOfPixel)
{
    if ( !image ) 
    {
        cout << "setPixel: write pixel to an empty image";
        return 0;
    }
    
    if ( i<0 || i >numOfRows || j<0 || j>numOfCols )
    {
        //error_msg("Image::setPixel -> Out of boundaries\n");
        cout << "setPixel: Out of boundaries\n";
        return -1;
    }
    
    image[i][j] = colorOfPixel;
    return colorOfPixel;
}

/* getPixel
 *
 * @return: pixel i,j
 -1 if image is "empty".
 */
int Image::getPixel(int i, int j)const
{
    if ( !image ) 
    {
        cout << "getPixel: read pixel from an empty image\n";
        return -1;
    }
    if (i<0 || i>numOfRows || j<0 || j>numOfCols)
    {
        // error_msg("getPixel: out of image");
        cout << "getPixel: out of image\n";
        return -1;
    }
    else
        return image[i][j];
}




