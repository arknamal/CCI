// This program is part of the implementation of Lecture 6 of the CCI Course 2024 by Sarfraz Raza
// Problem 6b:
// Binary Strings of Length n:
// Provided any number n >= 1, return all possible binary numbers of n length in form of strings.

// Personal comments:
// This program returns perfectly arranged binary numbers because a set arranges its leaves in a BST
// To visualize the program's real sequence of creation of numbers, replace `set` with `list`. Have Fun!

#include <iostream>
#include <set>
using namespace std;

set<string> stringsOf0sAnd1s(int n) {
	if (n == 0) {
		return set<string>{""};
	}
	set<string> prev_result = stringsOf0sAnd1s(n - 1);
	set<string> result{};
	for (auto i = prev_result.begin(); i != prev_result.end(); i++) {
		result.insert("0" + *i);    // replace with push_back in case of using list
		result.insert("1" + *i);    // same as above
	}
	return result;
}

int main() {
	int n = 1;
	while (n > 0) {
		cout << "Enter n (>0) - enter 0 or negative number to exit: ";
		cin >> n;
		if (n > 0) {
			set<string> result;
			result = stringsOf0sAnd1s(n);
			cout << "All binary numbers of length " << n << ":" << endl;
			for (auto i = result.begin(); i != result.end(); i++) {
				cout << *i << endl;
			}
		}
	}
	cout << "Exited successfully...";
	return 0;
}