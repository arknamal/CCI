// This program is part of the implementation of Lecture 1 of the CCI Course 2024 by Sarfraz Raza
// Problem 1d:
// String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3, If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// Solution:
string compressString(string inputString)
{
    string result = "";
    int charCount = 1;
    char c = inputString[0];
    for (int i = 1; i <= inputString.length(); i++)
    {
        if (inputString[i] == c)
            charCount++;
        else
        {
            result += c;
            result += (charCount + 48);
            c = inputString[i];
            charCount = 1;
        }
    }
    return result.length() < inputString.length() ? result : inputString;
}

int main()
{
    string inputString = "aabbccccdee";
    cout << compressString(inputString);
    return 0;
}