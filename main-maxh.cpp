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
            bool heapFullShown = false; // Flag para controlar a exibição da mensagem de heap cheio
            while (ss >> item) {
                if (maxHeap.getN() == maxHeap.getNv() && !heapFullShown) {
                    cout << "Comando insert: Heap cheio!\n";
                    heapFullShown = true; // Marca que a mensagem foi exibida
                }
                if (!heapFullShown) { // Apenas tenta inserir se ainda não atingiu o limite
                    maxHeap.insert(item);
                }
            }
        } else if (command == "print_max") {
            maxHeap.print_max();
        } else if (command == "print") {
            maxHeap.print();
        } else if (command == "dim") {
            maxHeap.dim();
        } else if (command == "dim_max") {
            maxHeap.dim_max();
        } else if (command == "clear") {
            maxHeap.clear();
            cout << "Comando clear: Heap vazio!\n";
        } else if (command == "delete") {
            maxHeap.deleteMax();
        } else if (command == "redim_max") {
            int newNv;
            if (ss >> newNv) {
                maxHeap.redim_max(newNv);
            }
        } else if (command == "heapify_up") {
            int item, count = 0, items[200];  // Assuming 200 is a safe limit for input
            while (ss >> item) {
                items[count++] = item;
            }
            if (count > 0) {
                maxHeap.heapify_up(items, count);
            }
        } else {
            cout << "Comando " << command << " é inválido!\n";
        }
    }

    return 0;
}
