// This program is part of the implementation of Lecture 2 of the CCI Course 2024 by Sarfraz Raza
// Problem 2c:
// Bubble Sort

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ostream& operator<<(ostream&, vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return cout;
}

bool bubble_up(vector<int>& v)
{
    bool change_happened = false;
    for (int i = 0; i + 1 < v.size(); i++)
        if (v[i] > v[i + 1])
        {
            swap(v[i], v[i + 1]);
            change_happened = true;
        }
    return change_happened;
}
void bubble_sort(vector<int>& v)
{
    while(bubble_up(v));
}

int main()
{
    vector<int> v;
    ifstream reader("sortable_array.txt");
    int input = 0;
    while (reader)
    {
        reader >> input;
        if (!reader)
            break;
        v.push_back(input);
    }
    cout << v << endl;
    bubble_sort(v);
    cout << v << endl;
    return 0;
}