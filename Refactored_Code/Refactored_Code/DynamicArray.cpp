#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{
    capacity = 5;
    size = 0;
    data = new int[capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] data;
}

void DynamicArray::resize()
{
    int newCapacity = capacity * 2;

    int *temp = new int[newCapacity];

    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }

    delete[] data;

    data = temp;
    capacity = newCapacity;
}

void DynamicArray::add(int value)
{
    if (size == capacity)
    {
        resize();
    }

    data[size] = value;
    size++;

    cout << "Added: " << value << endl;
}

bool DynamicArray::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Invalid index!" << endl;
        return false;
    }

    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }

    size--;

    cout << "Removed item at index " << index << endl;

    return true;
}

int DynamicArray::find(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            return i;
        }
    }

    return -1;
}

void DynamicArray::printAll()
{
    cout << "Current List: ";

    if (size == 0)
    {
        cout << "(empty)";
    }

    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;
}

int DynamicArray::getSize()
{
    return size;
}

int DynamicArray::getCapacity()
{
    return capacity;
}
