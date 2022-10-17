#ifndef _HEAP_
#define _HEAP_

#include <iostream>
#define rep(i, a, b) for (int i = a;i < b; i++)
using namespace std;


class Heap {
    int* arr;
    int size;
    void minHeapify(int n, int i);
    public:
    Heap() : arr(NULL), size(0) {}
    void insert(int data);
    void deleteNode();
    void print() const;
};


void Heap :: minHeapify(int n, int i) {
    int index = i;
    int l = 2 * arr[n] + 1; 
    int r = 2 * arr[n] + 2; 

    if (l < n && arr[l] < arr[index]) {
        index = l;
    }
    if (r < n && arr[r] < arr[index]) {
        index = r;
    }
    if (index != i) {
        swap(arr[index], arr[i]);
        minHeapify(n, index);
    }
}


void Heap :: insert(int data) {
    int* newArr = new int[++size];
    rep(i, 0, size - 1)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    arr[size - 1] = data;
    minHeapify(0, size - 1);

    // for (int i = size-1; i > 0; i++) {
    //     swap(arr[0], arr[i]);
    //     minHeapify(size, i);
    // }
    // minHeapify(size, 0);
}


void Heap :: deleteNode() {
    if (size > 0) {
        swap(arr[size -1], arr[0]);
        size--;
        minHeapify(size, 0);

    } else {
        cout << "\nHeap already empty!";
        return;
    }
}


void Heap :: print() const {
    rep(i , 0, size)
    {
        cout << arr[i] << " ";
    }
}

#endif // _HEAP_