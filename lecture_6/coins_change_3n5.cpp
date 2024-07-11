// This program is part of the implementation of Lecture 6 of the CCI Course 2024 by Sarfraz Raza
// Problem 6a:
// Coin Change (3 and 5):
// Provided any number n >= 8, return the the number of coins of 3 and 5 needed to make that amount in 'change'.

#include <iostream>
using namespace std;

bool coinChange(int n, int& threes, int& fives) {
    if (n % 5 == 0) {
        fives += n/5;
        n /= 5;
        return true;
    } else if (n % 3 == 0) {
        threes += n/3;
        n /= 3;
        return true;
    } else if (coinChange(n - 5,threes,fives)) {
        fives++;
        return true;
    } else if (coinChange(n - 3,threes,fives)) {
        threes++;
        return true;
    }
    return false;
}

int main() {
    int n = 8, threes = 0, fives = 0;

    while (n >= 8) {
        cout << "Enter the number (n >= 8). Less than 8 to exit: ";
        cin >> n;
        if (n >= 8) {
            coinChange(n, threes, fives);
            cout << "The coins needed are: 3s = " << threes << ", 5s = " << fives << endl;
            threes = 0, fives = 0;
        }
    }

    cout << "Exited successfully...";

    return 0;
}