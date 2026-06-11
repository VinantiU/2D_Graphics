#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char picture[ROWS][COLS];

/* Initialize Picture */
void clearPicture() {
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            picture[i][j] = '_';
}

/* Display Picture */
void displayPicture() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++)
            printf("%c", picture[i][j]);
        printf("\n");
    }
    printf("\n");
}

/* Draw Line */
void drawLine(int row, int startCol, int endCol, char ch) {
    for(int col = startCol; col <= endCol; col++)
        picture[row][col] = ch;
}

/* Draw Rectangle */
void drawRectangle(int row, int col, int width, int height, char ch) {

    for(int j = col; j < col + width; j++) {
        picture[row][j] = ch;
        picture[row + height - 1][j] = ch;
    }

    for(int i = row; i < row + height; i++) {
        picture[i][col] = ch;
        picture[i][col + width - 1] = ch;
    }
}

/* Draw Triangle */
void drawTriangle(int row, int col, int height, char ch) {

    for(int i = 0; i < height; i++) {
        picture[row + i][col - i] = ch;
        picture[row + i][col + i] = ch;
    }

    for(int j = col - height + 1; j <= col + height - 1; j++)
        picture[row + height - 1][j] = ch;
}

/* Draw Circle */
void drawCircle(int centerRow, int centerCol, int radius, char ch) {

    for(int angle = 0; angle < 360; angle++) {

        double rad = angle * 3.14159 / 180.0;

        int x = centerCol + radius * cos(rad);
        int y = centerRow + radius * sin(rad);

        if(x >= 0 && x < COLS && y >= 0 && y < ROWS)
            picture[y][x] = ch;
    }
}

int main() {

    clearPicture();

    printf("ADD LINE\n");
    drawLine(2, 5, 25, '*');
    displayPicture();

    printf("ADD RECTANGLE\n");
    drawRectangle(5, 5, 15, 6, '*');
    displayPicture();

    printf("ADD TRIANGLE\n");
    drawTriangle(2, 30, 6, '*');
    displayPicture();

    printf("ADD CIRCLE\n");
    drawCircle(14, 30, 4, '*');
    displayPicture();

    /* Delete Rectangle */
    printf("DELETE RECTANGLE\n");
    drawRectangle(5, 5, 15, 6, '_');
    displayPicture();

    /* Modify Line */
    printf("MODIFY LINE\n");
    drawLine(2, 5, 25, '_');      // delete old line
    drawLine(18, 10, 35, '*');    // draw new line
    displayPicture();

    return 0;
}