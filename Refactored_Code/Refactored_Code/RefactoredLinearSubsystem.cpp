#include <iostream>
#include "DynamicArray.h"
using namespace std;

void processMatrix()
{
    int matrix[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transpose[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << transpose[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    cout << "--- REFACTORED LINEAR SUBSYSTEM ---" << endl;

    DynamicArray records;

    records.add(10);
    records.add(20);
    records.add(30);
    records.add(40);
    records.add(50);
    records.add(60);

    cout << "\nAfter adding items:" << endl;
    records.printAll();

    cout << "Size: " << records.getSize() << endl;
    cout << "Capacity: " << records.getCapacity() << endl;

    cout << "\nSearching for 30..." << endl;

    int position = records.find(30);

    if (position != -1)
        cout << "30 found at index " << position << endl;
    else
        cout << "30 not found" << endl;

    cout << "\nRemoving item at index 2..." << endl;
    records.removeAt(2);

    cout << "After removal:" << endl;
    records.printAll();

    cout << "\nTesting invalid index 99..." << endl;
    records.removeAt(99);

    cout << "\nList after invalid deletion:" << endl;
    records.printAll();

    processMatrix();

    cout << "\n--- PROGRAM FINISHED SAFELY ---" << endl;

    return 0;
}
