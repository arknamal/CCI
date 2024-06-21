// This program is part of the implementation of Lecture 1 of the CCI Course 2024 by Sarfraz Raza
// Problem 1f:
// Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include <iostream>

using namespace std;

#define ROWS 100
#define COLS 100

// initial solution:
void performOneRotation(char matrix[ROWS][COLS], int n, int ri, int ci, int stackDepth)
{
    char tempChar = matrix[ri][ci];
    int newRow = n - ci - 1;
    int newCol = ri;
    if (stackDepth == 3)
    {
        matrix[newRow][newCol] = tempChar;
        return;
    }
    performOneRotation(matrix, n, newRow, newCol, stackDepth + 1);
    matrix[newRow][newCol] = tempChar;
}

void printMatrix(char matrix[ROWS][COLS], int n)
{
    for (int ri = 0; ri < n; ri++)
    {
        for (int ci = 0; ci < n; ci++)
            cout << matrix[ri][ci] << "  ";
        cout << endl;
    }
    cout << endl;
}

void rotateMatrix(char matrix[ROWS][COLS], int n)
{
    for (int ri = 0; ri * 2 < n; ri++)
    {
        for (int ci = ri; ci + ri < n - 1; ci++)
        {
            performOneRotation(matrix, n, ri, ci, 0);
            // printMatrix(matrix, n); // if you want to see rotation in steps
        }
    }
}

void populateMatrix(char matrix[ROWS][COLS], int n)
{
    for (int ri = 0; ri < n; ri++)
        for (int ci = 0; ci < n; ci++)
            matrix[ri][ci] = 'A' + ri * n + ci;
}

int main()
{
    char matrix[ROWS][COLS]{};
    int n = 7; // change value of n for different sizes of matrices
    populateMatrix(matrix, n);
    printMatrix(matrix, n);
    cout << endl;
    rotateMatrix(matrix, n);
    printMatrix(matrix, n);
    return 0;
}