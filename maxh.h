/*
** file: maxh.h
**
** Max Heap operado por comandos (2023-24)
** Universidade Aberta
**
** Aluno: Hugo Silva n:2100455
*/

#ifndef MAXH_H
#define MAXH_H

class IMAXH {
private:
    int* v; // vetor com nós
    int n; // número de nós usados
    int nv; // dimensão máxima do vetor (capacidade)

public:
    IMAXH(int nmax = 15); // cria heap vazio com capacidade nmax nós
    ~IMAXH();
    int* getV() const { return v; }
    void setV(int* newV) { v = newV; }
    int getN() const { return n; }
    void setN(int newN) { n = newN; }
    int getNv() const { return nv; }
    void setNv(int newNv) { nv = newNv; }

    void insert(int item);
    void print_max();
    void print();
    void dim();
    void dim_max();
    void deleteMax();
    void heapify(int index);
    void buildMaxHeap();
    void clear();
    void redim_max(int newNv);
    void heapify_up(int* items, int count);
};

#endif // MAXH_H
