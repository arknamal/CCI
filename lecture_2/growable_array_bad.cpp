// This program is part of the implementation of Lecture 2 of the CCI Course 2024 by Sarfraz Raza
// Problem 2a:
// Implementing a dynamic array:

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class GrowableArray
{
    int size;
    T* Vs;

    public:
    GrowableArray(): size{0}, Vs{nullptr} {}
    GrowableArray(int s): size(s)
    {
        Vs(new T[s]);
    }
    T& operator[](int i)
    {
        return Vs[i];
    }
    void push_back(T v)
    {
        T* heapArray = new T[size + 1];
        for (int i = 0; i < size; i++)
            heapArray[i] = Vs[i];
        heapArray[size] = v;
        delete[] Vs;
        size++;
        Vs = heapArray;
    }
    friend ostream & operator<<(ostream &, GrowableArray<T>& GA)
    {
        for (int i = 0; i < GA.size; i++)
            cout << GA[i] << " ";
        return cout;
    }
};

int main()
{
    GrowableArray<int> GA;
    ifstream reader("input_array.txt");
    int input = 0;
    while (reader)
    {
        reader >> input;
        if (!reader)
            break;
        GA.push_back(input);
    }
    cout << GA << endl;
    return 0;
}