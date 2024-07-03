// This program is part of the implementation of Lecture 3 of the CCI Course 2024 by Sarfraz Raza
// Problem 3a:
// Decimal to Base Converter

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// initial solution (mine):
char convertIntToBasedChar(int remainder)
{
    char chunk = '0' + remainder;
    if (remainder > 9)
    {
        remainder-=10;
        chunk = 'A' + remainder;
    }
    return chunk;
}
string decimalToBaseConverterWithString(int n, int base)
{
    string result = "";
    int remainder = -1, quotient = n;
    while(quotient >= base)
    {
        remainder = quotient % base;
        quotient = quotient / base;
        char chunk = convertIntToBasedChar(remainder);
        result = chunk + result;
    }
    result = convertIntToBasedChar(quotient) + result;
    return result;
}

// better solution using stack:
string decimalToBaseConverter(int n, int base)
{
    int remainder = 0;
    stack<char> chars;

    do
    {
        remainder = n % base;
        n /= base;
        if (remainder > 9)
        {
            chars.push('A' + remainder - 10);
        } else
        {
            chars.push('0' + remainder);
        }
    } while (n != 0);

    int size = chars.size();
    char *result = new char[size + 1] {};
    
    for (int i = 0; i < size; i++)
    {
        result[i] = chars.top();
        chars.pop();
    }
    return result;
}

int main()
{
    int n = 0, b = 10;
    while (true)
    {
        cout << "Give nummber and base (2..36): " << endl;
        cin >> n;
        if (n < 0)
        {
            break;
        }
        cin >> b;
        cout << "The number " << n << " in base " << b << " is: " << decimalToBaseConverter(n, b) << endl;
    }
    cout << "Exited successfully...";
    return 0;
}