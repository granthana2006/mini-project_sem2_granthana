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
// Draw Line
void drawLine(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2)
    {
        for(i = x1; i <= x2; i++)
            pic[y1][i] = '*';
    }
    else if(x1 == x2)
    {
        for(i = y1; i <= y2; i++)
            pic[i][x1] = '*';
    }
}

// Draw Rectangle
void drawRectangle(int x1, int y1, int x2, int y2)
{
    int i;

    for(i = x1; i <= x2; i++)
    {
        pic[y1][i] = '*';
        pic[y2][i] = '*';
    }

    for(i = y1; i <= y2; i++)
    {
        pic[i][x1] = '*';
        pic[i][x2] = '*';
    }
}

// Draw Triangle
void drawTriangle(int x, int y, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        pic[y + i][x - i] = '*';
        pic[y + i][x + i] = '*';
    }

    for(i = x - size + 1; i <= x + size - 1; i++)
    {
        pic[y + size - 1][i] = '*';
    }
}

// Draw Circle (simple approximation)
void drawCircle(int cx, int cy, int r)
{
    int x, y;

    for(y = -r; y <= r; y++)
    {
        for(x = -r; x <= r; x++)
        {
            if(x*x + y*y <= r*r)
            {
                pic[cy + y][cx + x] = '*';
            }
        }
    }
}
// Add Object
void addObject()
{
    char shape;

    printf("\nChoose Shape:\n");
    printf("L - Line\n");
    printf("R - Rectangle\n");
    printf("T - Triangle\n");
    printf("C - Circle\n");

    printf("Enter Shape: ");
    scanf(" %c", &shape);

    if(shape == 'L' || shape == 'l')
    {
        int x1, y1, x2, y2;

        printf("Enter x1 y1 x2 y2: ");
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        drawLine(x1, y1, x2, y2);
    }

    else if(shape == 'R' || shape == 'r')
    {
        int x1, y1, x2, y2;

        printf("Enter x1 y1 x2 y2: ");
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        drawRectangle(x1, y1, x2, y2);
    }

    else if(shape == 'T' || shape == 't')
    {
        int x, y, size;

        printf("Enter x y size: ");
        scanf("%d%d%d", &x, &y, &size);

        drawTriangle(x, y, size);
    }

    else if(shape == 'C' || shape == 'c')
    {
        int x, y, r;

        printf("Enter centerX centerY radius: ");
        scanf("%d%d%d", &x, &y, &r);

        drawCircle(x, y, r);
    }
}

// Delete Area
void deleteArea(int x1, int y1, int x2, int y2)
{
    int i, j;

    for(i = y1; i <= y2; i++)
    {
        for(j = x1; j <= x2; j++)
        {
            pic[i][j] = '_';
        }
    }
}

// Modify Rectangle
void modifyRectangle()
{
    int oldx1, oldy1, oldx2, oldy2;
    int newx1, newy1, newx2, newy2;

    printf("Enter old rectangle coordinates:\n");
    scanf("%d%d%d%d",
          &oldx1, &oldy1,
          &oldx2, &oldy2);

    deleteArea(oldx1, oldy1, oldx2, oldy2);

    printf("Enter new rectangle coordinates:\n");
    scanf("%d%d%d%d",
          &newx1, &newy1,
          &newx2, &newy2);

    drawRectangle(newx1, newy1, newx2, newy2);
}