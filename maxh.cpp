#include "maxh.h"
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Constructs an empty heap with a specified maximum capacity.
 * 
 * Initializes the heap with zero elements and sets the maximum capacity.
 * 
 * @param nmax The maximum number of elements the heap can hold.
 */
IMAXH::IMAXH(int nmax) : v(new int[nmax]), n(0), nv(nmax) {}

/**
 * @brief Destructor that frees the allocated memory for the heap.
 */
IMAXH::~IMAXH() {
    delete[] v;
}

/**
 * @brief Inserts an element into the heap and restores the max-heap property.
 * 
 * @param item The element to insert into the heap.
 */
void IMAXH::insert(int item) {
    if (n == nv) {
        cout << "Insert command: Heap is full!\n";
        return;
    }
    v[n] = item;
    int i = n++;
    while (i > 0 && v[(i - 1) / 2] < v[i]) {
        swap(v[i], v[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/**
 * @brief Prints the maximum element (root) of the heap.
 * 
 * If the heap is empty, an error message is displayed.
 */
void IMAXH::printMax() const {
    if (n == 0)
        cout << "Print max command: Heap is empty!\n";
    else
        cout << "Max = " << v[0] << "\n";
}

/**
 * @brief Prints the entire heap in level-order.
 * 
 * If the heap is empty, an error message is displayed.
 */
void IMAXH::print() const {
    if (n == 0) {
        cout << "Print command: Heap is empty!\n";
        return;
    }
    int levelSize = 1, levelCount = 0;
    cout << "Heap =\n";
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (levelCount + 1 < levelSize && i < n - 1)
            cout << " ";
        levelCount++;
        if (levelCount == levelSize || i == n - 1) {
            cout << "\n";
            levelSize *= 2;
            levelCount = 0;
        }
    }
}

/**
 * @brief Prints the current number of elements in the heap.
 */
void IMAXH::dim() const {
    cout << "Heap has " << n << " items\n";
}

/**
 * @brief Prints the maximum capacity of the heap.
 */
void IMAXH::dimMax() const {
    cout << "Heap has capacity for " << nv << " items\n";
}

/**
 * @brief Deletes the maximum element (root) and restores the heap property.
 * 
 * If the heap is empty, an error message is displayed.
 */
void IMAXH::deleteMax() {
    if (n == 0) {
        cout << "Delete command: Heap is empty!\n";
        return;
    }
    v[0] = v[--n];
    heapify(0);
}

/**
 * @brief Maintains the max-heap property by heapifying the subtree rooted at index i.
 * 
 * @param i The index to start the heapify operation.
 */
void IMAXH::heapify(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && v[left] > v[largest]) largest = left;
    if (right < n && v[right] > v[largest]) largest = right;
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(largest);
    }
}

/**
 * @brief Builds a max heap from the current elements in the array.
 */
void IMAXH::buildMaxHeap() {
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(i);
}

/**
 * @brief Clears the heap by resetting the number of elements to zero.
 */
void IMAXH::clear() {
    n = 0;
}

/**
 * @brief Resizes the heap to a new maximum capacity.
 * 
 * @param newNv The new maximum capacity of the heap.
 */
void IMAXH::redimMax(int newNv) {
    int* newV = new int[newNv];
    delete[] v;
    v = newV;
    nv = newNv;
    n = 0;
}

/**
 * @brief Reorganizes the heap after inserting multiple elements.
 * 
 * @param items Array of elements to be inserted.
 * @param count The number of elements in the array.
 */
void IMAXH::heapifyUp(int* items, int count) {
    clear();
    if (count > nv) {
        cout << "Error: more items than the capacity allows.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        v[i] = items[i];
    }
    n = count;
    buildMaxHeap();
}
