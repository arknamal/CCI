// This program is part of the implementation of Lecture 1 of the CCI Course 2024 by Sarfraz Raza
// Problem 1a:
// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
// (assuming the array consists of small alphabets only)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Initial solution:

// Following function expects a character array, a starting index, length of the array and a character to look for. Then it iterates from the starting index to the length of the array and returns true if the character is found, otherwise false.
bool searchChar(char charsArray[], int startingIndex, int length, char c)
{
    for (int i = startingIndex; i < length; i++)
    {
        if (charsArray[i] == c)
            return true;
    }
    return false;
}

bool isUniqueSlow(char charsArray[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (searchChar(charsArray, i + 1, arrayLength, charsArray[i]))
            return false;
    }
    return true;
}

bool isUniqueExtraSpace(char charsArray[], int arrayLength)
{
    // initialize an empty array to keep counts of occurance of every alphabet in the array
    int counts[26]{};
    for (int i = 0; i < arrayLength; i++)
    {
        int c = charsArray[i] - 'a';
        counts[c]++;
        if (counts[c] > 1)
            return false;
    }
    return true;
}

bool isUnique(char charsArray[], int arrayLength)
{
    sort(charsArray, charsArray + arrayLength);
    for (int i = 0; i < arrayLength;)
    {
        if (charsArray[i++] == charsArray[i])
            return false;
    }
    return true;
}

int main()
{
    int arrayLength = 10;
    char charsArray[11] = {"abcdefghii"};
    cout << (isUniqueSlow(charsArray, arrayLength)?"Unique":"Not Unique");
    return 0;
}