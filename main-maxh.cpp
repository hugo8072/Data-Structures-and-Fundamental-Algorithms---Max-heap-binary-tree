#include "maxh.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    IMAXH maxHeap;
    string line;

    while (getline(cin, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "insert") {
            int item;
            bool heapFullShown = false; // Flag to control the display of heap full message
            while (ss >> item) {
                if (maxHeap.getN() == maxHeap.getNv() && !heapFullShown) {
                    cout << "Insert command: Heap is full!\n";
                    heapFullShown = true; // Mark that the message has been displayed
                }
                if (!heapFullShown) { // Only try to insert if the limit hasn't been reached
                    maxHeap.insert(item);
                }
            }
        } else if (command == "print_max") {
            maxHeap.printMax();
        } else if (command == "print") {
            maxHeap.print();
        } else if (command == "dim") {
            maxHeap.dim();
        } else if (command == "dim_max") {
            maxHeap.dimMax();
        } else if (command == "clear") {
            maxHeap.clear();
            cout << "Clear command: Heap is empty!\n";
        } else if (command == "delete") {
            maxHeap.deleteMax();
        } else if (command == "redim_max") {
            int newNv;
            if (ss >> newNv) {
                maxHeap.redimMax(newNv);
            }
        } else if (command == "heapify_up") {
            int item, count = 0, items[200];  // Assuming 200 is a safe limit for input
            while (ss >> item) {
                items[count++] = item;
            }
            if (count > 0) {
                maxHeap.heapifyUp(items, count);
            }
        } else {
            cout << "Command " << command << " is invalid!\n";
        }
    }

    return 0;
}
