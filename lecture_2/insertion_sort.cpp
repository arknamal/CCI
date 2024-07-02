// This program is part of the implementation of Lecture 2 of the CCI Course 2024 by Sarfraz Raza
// Problem 2e:
// Insertion Sort

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

void insert_in_sorted_array(vector<int>& v, int i)
{
    int j = i - 1;
    while(j >= 0 && v[j] > v[i])
    {
        swap(v[i], v[j]);
        i--;
        j--;
    }
}
void insertion_sort(vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
        insert_in_sorted_array(v, i);
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
        {
            break;
        }
        v.push_back(input);
    }
    cout << v << endl;
    insertion_sort(v);
    cout << v << endl;
    return 0;
}