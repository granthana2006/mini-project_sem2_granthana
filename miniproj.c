#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

char pic[ROWS][COLS];

// Initialize picture
void clearPicture() {
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            pic[i][j] = '_';
}

// Display picture
void displayPicture() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++)
            printf("%c", pic[i][j]);
        printf("\n");
    }
}

// Draw Rectangle
void drawRectangle(int r, int c, int h, int w) {
    for(int i=r;i<r+h && i<ROWS;i++)
        for(int j=c;j<c+w && j<COLS;j++)
            pic[i][j] = '*';
}

// Draw Horizontal Line
void drawLine(int r, int c, int len) {
    for(int j=c;j<c+len && j<COLS;j++)
        pic[r][j] = '*';
}

// Draw Triangle
void drawTriangle(int r, int c, int h) {
    for(int i=0;i<h;i++) {
        for(int j=0;j<=i;j++) {
            if(r+i < ROWS && c+j < COLS)
                pic[r+i][c+j] = '*';
        }
    }
}

// Draw Simple Circle
void drawCircle(int r, int c, int radius) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            int x = i-r;
            int y = j-c;
            if(x*x + y*y <= radius*radius)
                pic[i][j] = '*';
        }
    }
}

// Delete Object (fill area with '_')
void deleteObject(int r, int c, int h, int w) {
    for(int i=r;i<r+h && i<ROWS;i++)
        for(int j=c;j<c+w && j<COLS;j++)
            pic[i][j] = '_';
}

int main() {
    int choice;

    clearPicture();

    do {
        printf("\n1.Draw Rectangle");
        printf("\n2.Draw Line");
        printf("\n3.Draw Triangle");
        printf("\n4.Draw Circle");
        printf("\n5.Delete Area");
        printf("\n6.Modify (Delete then Draw Rectangle)");
        printf("\n7.Display Picture");
        printf("\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        int r,c,h,w,len,radius;

        switch(choice) {

        case 1:
            printf("Row Col Height Width: ");
            scanf("%d%d%d%d",&r,&c,&h,&w);
            drawRectangle(r,c,h,w);
            displayPicture();
            break;

        case 2:
            printf("Row Col Length: ");
            scanf("%d%d%d",&r,&c,&len);
            drawLine(r,c,len);
            displayPicture();
            break;

        case 3:
            printf("Row Col Height: ");
            scanf("%d%d%d",&r,&c,&h);
            drawTriangle(r,c,h);
            displayPicture();
            break;

        case 4:
            printf("CenterRow CenterCol Radius: ");
            scanf("%d%d%d",&r,&c,&radius);
            drawCircle(r,c,radius);
            displayPicture();
            break;

        case 5:
            printf("Row Col Height Width: ");
            scanf("%d%d%d%d",&r,&c,&h,&w);
            deleteObject(r,c,h,w);
            displayPicture();
            break;

        case 6:
            printf("Delete Area (Row Col Height Width): ");
            scanf("%d%d%d%d",&r,&c,&h,&w);
            deleteObject(r,c,h,w);

            printf("New Rectangle (Row Col Height Width): ");
            scanf("%d%d%d%d",&r,&c,&h,&w);
            drawRectangle(r,c,h,w);
            displayPicture();
            break;

        case 7:
            displayPicture();
            break;
        }
    } while(choice != 0);

    return 0;
}