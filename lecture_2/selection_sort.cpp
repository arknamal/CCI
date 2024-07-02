// This program is part of the implementation of Lecture 2 of the CCI Course 2024 by Sarfraz Raza
// Problem 2d:
// Selection Sort

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

int find_index_of_min_in_range(vector<int>& v, int start_index, int end_index)
{
    int min_index = start_index; // initial assumption
    int min = v[min_index]; // the min is the entry at min_index
    for (int i = min_index; i <= end_index; i++)
    {
        if (v[i] < min)
        {
            min_index = i;
            min = v[i];
        }
    }
    return min_index;
}
void selection_sort(vector<int>& v)
{
    int end_index = v.size() - 1;
    for (int i = 0; i <= end_index; i++)
    {
        int min_index = find_index_of_min_in_range(v, i, end_index);
        swap(v[i], v[min_index]);
    }
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
    selection_sort(v);
    cout << v << endl;
    return 0;
}