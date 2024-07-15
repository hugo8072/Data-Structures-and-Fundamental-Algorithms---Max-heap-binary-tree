#include "maxh.h"
#include <iostream>
#include <algorithm>

using namespace std;

IMAXH::IMAXH(int nmax) : v(new int[nmax]), n(0), nv(nmax) {}

IMAXH::~IMAXH() {
    delete[] v;
}

void IMAXH::insert(int item) {
    if (n == nv) {
        cout << "Comando insert: Heap cheio!\n";
        return;
    }
    v[n] = item;
    int i = n++;
    while (i > 0 && v[(i - 1) / 2] < v[i]) {
        swap(v[i], v[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void IMAXH::print_max() {
    if (n == 0)
        cout << "Comando print_max: Heap vazio!\n";
    else
        cout << "Max= " << v[0] << "\n";
}

void IMAXH::print() {
    if (n == 0) {
        cout << "Comando print: Heap vazio!\n";
        return;
    }
    int levelSize = 1, levelCount = 0;
    cout << "Heap=\n";
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

void IMAXH::dim() {
    cout << "Heap tem " << n << " itens\n";
}

void IMAXH::dim_max() {
    cout << "Heap tem capacidade " << nv << " itens\n";
}

void IMAXH::deleteMax() {
    if (n == 0) {
        cout << "Comando delete: Heap vazio!\n";
        return;
    }
    v[0] = v[--n];
    heapify(0);
}

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

void IMAXH::buildMaxHeap() {
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(i);
}

void IMAXH::clear() {
    n = 0;
}

void IMAXH::redim_max(int newNv) {
    int* newV = new int[newNv];
    delete[] v;
    v = newV;
    nv = newNv;
    n = 0;
}

void IMAXH::heapify_up(int* items, int count) {
    clear();
    if (count > nv) {
        cout << "Erro: mais itens do que a capacidade permite.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        v[i] = items[i];
    }
    n = count;
    buildMaxHeap();
}
