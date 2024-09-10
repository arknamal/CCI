// This program is part of the implementation of Lecture 6 of the CCI Course 2024 by Sarfraz Raza
// Problem 6c:
// Print digits of a number

#include <iostream>
using namespace std;

void printN(int n) {
	cout << n << " ";
	return;
}

void printDigitsR2L(int n) {
	printN(n % 10);
	if (n / 10 == 0) {
		return;
	}
	printDigitsR2L(n / 10);
}

void printDigitsL2R(int n) {
	if (n / 10 == 0) {
		printN(n % 10);
		return;
	}
	printDigitsL2R(n / 10);
	printN(n % 10);
}

int main() {
	int n = 1;
	while (n != 0) {
		cout << "Enter n - enter 0 to exit: ";
		cin >> n;
		if (n != 0) {
			printDigitsR2L(n);
			cout << endl;
			printDigitsL2R(n);
			cout << endl;
		}
	}
	cout << "Exited successfully...";
	return 0;
}