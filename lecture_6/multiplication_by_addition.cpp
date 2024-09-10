// This program is part of the implementation of Lecture 6 of the CCI Course 2024 by Sarfraz Raza
// Problem 6d:
// Multiplication by addition using recursion

#include <iostream>
using namespace std;

int multiplySlow (int a, int b) {
  if (b == 0)
    return 0;
  return a + multiplySlow (a, b - 1);
}

int multiplySmart (int a, int b) {
  if (b == 0)
    return 0;
  int sum = a;
  int pointer = 1;
  do {
    sum += sum;
    pointer += pointer;
  } while (2*pointer <= b);
  return sum + multiplySmart (a, b - pointer);
}

int main() {
	int a = 1, b = 1;
	while (a != 0 && b != 0) {
		cout << "Enter two numbers - enter 0 to exit." << endl;
		cout << "First number: ";
    cin >> a;
    cout << "Second number: ";
    cin >> b;
		if (a != 0 && b != 0) {
			cout << a << " * " << b << " = " << multiplySmart (a, b) << endl;
      cout << a << " * " << b << " = " << multiplySlow (a, b) << endl << endl;
		}
	}
	cout << "Exited successfully...";
	return 0;
}