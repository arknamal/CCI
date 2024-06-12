// This program is part of the implementation of Lecture 1 of the CCI Course 2024 by Sarfraz Raza
// Problem 1c:
// Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// initial solution:
void urlifyExtraSpace(char charsArray[], int arrayLength)
{
    char *charsArray2 = new char[arrayLength * 3 + 1];

    int j = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (charsArray[i] != ' ')
            charsArray2[j] = charsArray[i], j++;
        else
        {
            charsArray2[j] = '%', j++;
            charsArray2[j] = '2', j++;
            charsArray2[j] = '0', j++;
        }
    }

    for (int i = 0; i <= j; i++)
    {
        charsArray[i] = charsArray2[i];        
    }
    // good solution, works in O(n) but uses extra space.
}

// Efficient Solution without using extra space (in-place)
void urlify(char charsArray[], int arrayLength)
{
    int spacesCount = 0;
    for (int i = 0; i < arrayLength; i++)
        if (charsArray[i] == ' ')
            spacesCount++;

    for (int i = arrayLength, j = arrayLength + spacesCount * 2; j > i; i--, j--)
    {
        if (charsArray[i] != ' ')
            charsArray[j] = charsArray[i];
        else
        {
            charsArray[j] = '0', j--;
            charsArray[j] = '2', j--;
            charsArray[j] = '%';
        }
    }
}

int main()
{
    char charsArray[100] = "I am a string";
    // int arrayLength = strlen(charsArray);
    int arrayLength = 13; // avoiding the lengthy procedure needed to count alphabets first for efficient sol
    urlify(charsArray, arrayLength);
    cout << charsArray;
    return 0;
}