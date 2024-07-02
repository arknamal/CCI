// This program is part of the implementation of Lecture 2 of the CCI Course 2024 by Sarfraz Raza
// Problem 2b:
// Implementing a dynamic array (better method):

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Vector
{
    int size, capacity;
    T* Vs;

    public:
    Vector(): size{0}, capacity{1}, Vs{new int[1]} {}
    Vector(int s): size{s}, capacity{s}
    {
        Vs(new T[s]);
    }
    T& operator[](int i)
    {
        return Vs[i];
    }
    void push_back(T t)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* heapArray = new T[capacity];
            for (int i = 0; i < size; i++)
                heapArray[i] = Vs[i];
            delete[] Vs;
            Vs = heapArray;
        }
        Vs[size] = t;
        size++;
    }
    void pop_back()
    {
        size--;
    }
    int* begin()
    {
        return Vs;
    }
    int* end()
    {
        return Vs + size;
    }
    friend ostream & operator<<(ostream &, Vector<T>& v)
    {
        for (int i = 0; i < v.size; i++)
            cout << v[i] << " ";
        return cout;
    }
};

int main()
{
    // ofstream writer("input_array.txt");
    // for (int i = 0; i < 100000; i++)
    //     writer << i << " ";
    Vector<int> v;
    ifstream reader("input_array.txt");
    int input = 0;
    while (reader)
    {
        reader >> input;
        if (!reader)
            break;
        v.push_back(input);
    }
    cout << v << endl;
    return 0;
}