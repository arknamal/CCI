// This program is part of the implementation of Lecture 1 of the CCI Course 2024 by Sarfraz Raza
// Problem 1e:
// Write an algorithm which determines if all elements in an M x N matrix are 0s or not.

#include <iostream>

using namespace std;

#define ROWS 100
#define COLS 100

// Solution:
bool isZeroMatrix(int matrix[ROWS][COLS], int n)
{
    for (int ri = 0; ri < n; ri++)
        for (int ci = 0; ci < n; ci++)
        {
            // cout << ri << ci << matrix[ri][ci] << endl;
            if (matrix[ri][ci] != 0)
                return false;
        }
    return true;
}

int main()
{
    int matrix[ROWS][COLS]{};
    // matrix[3][3] = 1;
    cout << (isZeroMatrix(matrix, 5) ? "Is a zero matrix" : "Not a zero matrix");
    return 0;
}