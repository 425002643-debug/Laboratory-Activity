#include <iostream>
#include <string>

using namespace std;

// Refactored Subsystem using explicit size and capacity tracking
int* dataArray = nullptr;
size_t size = 0;
size_t capacity = 5;

void add_item(int val) {
    // Initial allocation
    if (size == 0 && dataArray == nullptr) {
        dataArray = new int[capacity];
    }

    // Feature 1: Dynamic Memory Array Resizing (Strictly applied matching your spec)
    if (size >= capacity) {
        size_t newCapacity = capacity * 2;
        int* temp = new int[newCapacity];

        for (size_t i = 0; i < size; ++i) {
            temp[i] = dataArray[i];
        }

        delete[] dataArray; // Release old buffer (Justification: Prevents heap memory leaks)
        dataArray = temp;
        capacity = newCapacity;
    }

    dataArray[size] = val;
    ++size;
    cout << "Added item: " << val << endl;
}

void remove_item_at(size_t idx) {
    // Upper bound safety check
    if (idx >= size) {
        cout << "Invalid index!" << endl;
        return;
    }

    // Feature 2: Array Deletion Shifting Logic (Strictly applied matching your spec)
    for (size_t i = idx; i < size - 1; ++i) {
        dataArray[i] = dataArray[i + 1];
    }
    --size; // Justification: Eliminates redundant loops into a clear O(n) pass

    cout << "Item removed from index " << idx << endl;
}

int find_item(int target) {
    for (size_t i = 0; i < size; i++) {
        if (dataArray[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void print_all() {
    if (size == 0) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Current List Contents: ";
    for (size_t i = 0; i < size; i++) {
        cout << dataArray[i] << " ";
    }
    cout << endl;
}

void clean_up() {
    delete[] dataArray;
    dataArray = nullptr;
}

int main() {
    cout << "STARTING UPGRADED SUBSYSTEM" << endl;

    add_item(10);
    add_item(20);
    add_item(30);
    add_item(40);
    add_item(50);
    add_item(60); // Resizes buffer cleanly using Feature 1

    print_all();

    remove_item_at(2); // Shifts data cleanly using Feature 2
    print_all();

    clean_up();
    return 0;
}
