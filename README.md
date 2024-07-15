Max Heap Command Operated Program
This project is a C++11 program designed to manage a binary tree of type max heap for storing integer items (positive or negative). The items represent both the key and the information. Commands generally allow inserting, removing, listing items, and other specific operations. The heap is implemented using a vector with a maximum capacity of N elements, indexed from 0 to N-1.
Features
- Insert items into the heap in the order presented.
- Print the maximum item in the heap.
- Print the entire heap tree.
- Print the number of items in the heap.
- Print the maximum capacity of the heap.
- Clear the heap.
- Remove the maximum item in the heap.
- Convert a vector into a max heap using the bottom-up algorithm.
- Resize the maximum capacity of the heap.
Commands
Insert Commands
insert item ... - Insert items into the heap in the presented order. Duplicate items are allowed.
Print Commands
print_max - Print the maximum item in the heap.
print - Print the entire heap tree, with each level on a new line.
Utility Commands
dim - Print the number of items in the heap.
dim_max - Print the maximum capacity of the heap.
clear - Initialize the heap with zero elements.
delete - Remove the maximum item in the heap.
heapify_up item ... - Convert the vector defined by the items into a max heap.
redim_max N - Resize the maximum capacity of the heap.
Error Handling
The program ensures stability by checking for an empty heap before performing operations. If an operation cannot be executed due to an empty heap, appropriate error messages are printed.
Input File Format
The input file should contain one command per line. Commands may be followed by multiple arguments separated by spaces. Lines starting with '#' are treated as comments and ignored.
Example Input
# This line is a comment
insert 7 9 3 8
print
Example Output
Heap=
9
8 3
7
