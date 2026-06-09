#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char pic[ROWS][COLS];

/*-------------------- Utility Functions --------------------*/

int isValid(int x, int y)
{
    return (x >= 0 && x < COLS &&
            y >= 0 && y < ROWS);
}

void clearPicture()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            pic[i][j] = '.';
        }
    }
}

void displayPicture()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c ", pic[i][j]);
        }
        printf("\n");
    }
}

/*-------------------- Shape Functions --------------------*/

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    int i;

    for(i = 0; i <= steps; i++)
    {
        if(isValid((int)x, (int)y))
        {
            pic[(int)y][(int)x] = '#';
        }

        x += xInc;
        y += yInc;
    }
}

void drawRectangle(int x1, int y1, int x2, int y2)
{
    int i;

    for(i = x1; i <= x2; i++)
    {
        if(isValid(i, y1))
            pic[y1][i] = '#';

        if(isValid(i, y2))
            pic[y2][i] = '#';
    }

    for(i = y1; i <= y2; i++)
    {
        if(isValid(x1, i))
            pic[i][x1] = '#';

        if(isValid(x2, i))
            pic[i][x2] = '#';
    }
}

void drawTriangle(int x, int y, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(isValid(x-i, y+i))
            pic[y+i][x-i] = '#';

        if(isValid(x+i, y+i))
            pic[y+i][x+i] = '#';
    }

    for(i = x-size+1; i <= x+size-1; i++)
    {
        if(isValid(i, y+size-1))
            pic[y+size-1][i] = '#';
    }
}

void drawCircle(int cx, int cy, int r)
{
    int x, y;

    for(y = -r; y <= r; y++)
    {
        for(x = -r; x <= r; x++)
        {
            int value = x*x + y*y;

            if(value >= r*r-r && value <= r*r+r)
            {
                if(isValid(cx+x, cy+y))
                {
                    pic[cy+y][cx+x] = '#';
                }
            }
        }
    }
}

/*-------------------- Object Operations --------------------*/

void addObject()
{
    char shape;

    printf("\nChoose Shape\n");
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
        scanf("%d%d%d%d",
              &x1, &y1,
              &x2, &y2);

        drawLine(x1, y1, x2, y2);
    }

    else if(shape == 'R' || shape == 'r')
    {
        int x1, y1, x2, y2;

        printf("Enter x1 y1 x2 y2: ");
        scanf("%d%d%d%d",
              &x1, &y1,
              &x2, &y2);

        drawRectangle(x1, y1, x2, y2);
    }

    else if(shape == 'T' || shape == 't')
    {
        int x, y, size;

        printf("Enter x y size: ");
        scanf("%d%d%d",
              &x, &y,
              &size);

        drawTriangle(x, y, size);
    }

    else if(shape == 'C' || shape == 'c')
    {
        int x, y, r;

        printf("Enter centerX centerY radius: ");
        scanf("%d%d%d",
              &x, &y,
              &r);

        drawCircle(x, y, r);
    }
}

void deleteArea(int x1, int y1, int x2, int y2)
{
    int i, j;

    for(i = y1; i <= y2; i++)
    {
        for(j = x1; j <= x2; j++)
        {
            if(isValid(j, i))
            {
                pic[i][j] = '.';
            }
        }
    }
}

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

/*-------------------- Main Function --------------------*/

int main()
{
    int choice;
    int x1, y1, x2, y2;

    clearPicture();

    do
    {
        printf("\n========== GRAPHICS EDITOR ==========\n");
        printf("1. Add Object\n");
        printf("2. Delete Area\n");
        printf("3. Modify Rectangle\n");
        printf("4. Display Picture\n");
        printf("5. Clear Canvas\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addObject();
                break;

            case 2:
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",
                      &x1, &y1,
                      &x2, &y2);

                deleteArea(x1, y1, x2, y2);
                break;

            case 3:
                modifyRectangle();
                break;

            case 4:
                displayPicture();
                break;

            case 5:
                clearPicture();
                printf("Canvas Cleared Successfully!\n");
                break;

            case 6:
                printf("Program Exited.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}