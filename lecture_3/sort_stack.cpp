// This program is part of the implementation of Lecture 3 of the CCI Course 2024 by Sarfraz Raza
// Problem 3b:
// Sort a stack using only one more stack but no other data structure

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> originalStack)
{
    // invert the only comparison operator to reverse the order of the sort :)
    stack<int> tempStack;
    while(originalStack.size())
    {
        int tempHolder = originalStack.top();
        originalStack.pop();
        while (!tempStack.empty() && tempStack.top() > tempHolder)
        {
            originalStack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(tempHolder);
    }
    return tempStack;
}

int main()
{
    stack<int> originalStack;
    int inputs[7] = {3, -2, 5, 8, -9, 11, -16};
    for (int i = 0; i < 7; i++)
    {
        originalStack.push(inputs[i]);
    }
    originalStack = sortStack(originalStack);
    while (originalStack.size())
    {
        cout << originalStack.top() << " ";
        originalStack.pop(); 
    }
    return 0;
}