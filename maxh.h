#ifndef MAXH_H
#define MAXH_H

/**
 * @class IMAXH
 * @brief Class implementing a Max Heap with various command-based operations.
 * 
 * This class manages a max-heap data structure with operations such as insertion, deletion,
 * heapification, and printing of heap contents. It maintains the heap invariant, ensuring
 * that the largest element is always at the root.
 */
class IMAXH {
private:
    int* v;  ///< Array of heap elements.
    int n;   ///< Number of elements in the heap.
    int nv;  ///< Maximum capacity of the heap.

public:
    /**
     * @brief Constructs an empty max heap with the specified capacity.
     * 
     * @param nmax The maximum number of elements the heap can hold. Default is 15.
     */
    explicit IMAXH(int nmax = 15);

    /**
     * @brief Destructor that frees the allocated memory for the heap array.
     */
    ~IMAXH();

    /**
     * @brief Gets the array representing the heap.
     * @return Pointer to the array of heap elements.
     */
    int* getV() const { return v; }

    /**
     * @brief Sets a new array to represent the heap.
     * @param newV Pointer to the new array of heap elements.
     */
    void setV(int* newV) { v = newV; }

    /**
     * @brief Gets the current number of elements in the heap.
     * @return The number of elements in the heap.
     */
    int getN() const { return n; }

    /**
     * @brief Sets the current number of elements in the heap.
     * @param newN The new number of elements in the heap.
     */
    void setN(int newN) { n = newN; }

    /**
     * @brief Gets the maximum capacity of the heap.
     * @return The maximum number of elements the heap can hold.
     */
    int getNv() const { return nv; }

    /**
     * @brief Sets the maximum capacity of the heap.
     * @param newNv The new maximum capacity of the heap.
     */
    void setNv(int newNv) { nv = newNv; }

    /**
     * @brief Inserts an element into the heap and restores the max-heap property.
     * 
     * @param item The element to insert into the heap.
     */
    void insert(int item);

    /**
     * @brief Prints the maximum element (root) of the heap.
     * 
     * If the heap is empty, an error message is displayed.
     */
    void printMax() const;

    /**
     * @brief Prints the entire heap in level-order.
     * 
     * If the heap is empty, an error message is displayed.
     */
    void print() const;

    /**
     * @brief Prints the current number of elements in the heap.
     */
    void dim() const;

    /**
     * @brief Prints the maximum capacity of the heap.
     */
    void dimMax() const;

    /**
     * @brief Deletes the maximum element (root) and restores the heap property.
     * 
     * If the heap is empty, an error message is displayed.
     */
    void deleteMax();

    /**
     * @brief Maintains the max-heap property by heapifying the subtree rooted at index i.
     * 
     * @param i The index to start the heapify operation.
     */
    void heapify(int i);

    /**
     * @brief Builds a max heap from the current elements in the array.
     */
    void buildMaxHeap();

    /**
     * @brief Clears the heap by resetting the number of elements to zero.
     */
    void clear();

    /**
     * @brief Resizes the heap to a new maximum capacity.
     * 
     * @param newNv The new maximum capacity of the heap.
     */
    void redimMax(int newNv);

    /**
     * @brief Reorganizes the heap after inserting multiple elements.
     * 
     * @param items Array of elements to be inserted.
     * @param count The number of elements in the array.
     */
    void heapifyUp(int* items, int count);
};

#endif // MAXH_H
