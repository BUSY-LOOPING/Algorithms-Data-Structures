#include "Heap.hpp"


int main() {
    Heap heap;
    heap.print();
    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    heap.insert(9);
    heap.insert(10);
    heap.deleteNode();
    heap.print();
}