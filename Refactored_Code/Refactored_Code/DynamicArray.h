#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{
private:
    int *data;
    int size;
    int capacity;

    void resize();

public:
    DynamicArray();
    ~DynamicArray();

    void add(int value);
    bool removeAt(int index);
    int find(int value);
    void printAll();

    int getSize();
    int getCapacity();
};

#endif
