// This program is part of the implementation of Lecture 3 of the CCI Course 2024 by Sarfraz Raza
// Problem 3c:
// Merge Sort without Recursion

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ostream& operator<<(ostream&, vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return cout;
}

vector<int> merge(vector<int>& A, vector<int> B)
{
    int a_s = A.size(), b_s = B.size();
    int size = a_s + b_s;
    vector<int> result(size);
    for (int i = 0, ai = 0, bi = 0; i < size; i++)
    {
        if (ai == a_s)
        {
            result[i] = B[bi], bi++;
        }
        else if (bi == b_s)
        {
            result[i] = A[ai], ai++;
        } else if (A[ai] < B[bi]) // invert this comparison operator for inverted sort :)
        {
            result[i] = A[ai], ai++;
        } else
        {
            result[i] = B[bi], bi++;
        }
    }
    return result;
}

void merge_sort(vector<int>& v)
{
    queue<vector<int>> Q;
    for (int i = 0; i < v.size(); i++)
    {
        Q.push(vector<int> {v[i]});
    }
    do
    {
        vector<int> v1 = Q.front(); Q.pop();
        vector<int> v2 = Q.front(); Q.pop();
        Q.push(merge(v1, v2));
    } while(Q.size() > 1);
    v = Q.front();
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
    merge_sort(v);
    cout << v << endl;
    return 0;
}