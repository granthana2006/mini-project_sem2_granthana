#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

char pic[ROWS][COLS];

// Clear Picture
void clearPicture()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            pic[i][j] = '_';
        }
    }
}

// Display Picture
void displayPicture()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", pic[i][j]);
        }
        printf("\n");
    }
}