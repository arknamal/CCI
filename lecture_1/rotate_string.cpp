// This program is part of the implementation of Lecture 1 of the CCI Course 2024 by Sarfraz Raza
// Problem 1g:
// Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g. "waterbottle" is a rotation of "erbottlewat").

#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2)
{
    // using find method to check if s2 is a substring of s1
    if (s1.find(s2) != string::npos)
        return true;
    return false;
}

bool isRotation (string s1, string s2)
{
    s2 += s2;

    // utilizing isSubstring function to check if out s1 is present inside the doubled s2:
    // (i.e. 2 x s2 = "erbottlewaterbottlewat" contains s1 = "waterbottle")
    return isSubstring(s2, s1);
}

int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    cout << (isRotation (s1, s2) ? "Is a rotation" : "Not a rotation") << endl;
}