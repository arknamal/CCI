// This program is part of the implementation of Lecture 1 of the CCI Course 2024 by Sarfraz Raza
// Problem 1b:
// Given two strings, write a method to determine if one is permutation of the other.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// initial solution:
bool isPermutationSlow(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
    // solution is smart and viable but complexity is n*log_n. Can be improved.
}

// alternate solution (assuming string consists of only small alphabets):
bool isPermutation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    int counts[26]{};
    for (int i = 0; i < s1.length(); i++)
    {
        int c1 = s1[i] - 'a';
        counts[c1]++;
        int c2 = s2[i] - 'a';
        counts[c2]--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string s1 = "abcd";
    string s2 = "dcba";
    cout << (isPermutation(s1, s2)?"Is Permutation":"Is Not A Permutation");
    return 0;
}