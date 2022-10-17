#include <iostream>
#define rep(i, a, b) for (int i = a;i < b; i++)
using namespace std;

void heapify(int arr[], int n, int i) {
    int maxIndex = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[maxIndex]) {
        maxIndex = l;
    }
    if (r < n && arr[r] > arr[maxIndex]) {
        maxIndex = r;
    }
    if (maxIndex != i) {
        swap (arr[i], arr[maxIndex]);
        heapify (arr, n, maxIndex);
    }
    
}

void heapsort(int arr[], int n) {
    //first non leaf element -> n /2 -1
    for (int i = n /2 -1; i >= 0;i --) {
        heapify(arr, n, i);
    }

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Driver program
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, n);

    rep(i, 0, n)
    {
        cout << arr[i] << " ";
    }
}

void heapify_max(int arr[], int n, int i) {
    int maxIndex = i;
    int l = i * 2 +1;
    int r = i * 2 +2;

    if (l < n && arr[l] < arr[maxIndex])
        maxIndex = l;
    if (r < n && arr[r] < arr[maxIndex])
        maxIndex = r;
    
    if (maxIndex != -1) 
    {
        swap(arr[maxIndex], arr[i]);
        heapify(arr, n, maxIndex);
    }
}

void heapsort2(int arr[], int n) {
    for (int i = n / 2 -1; i > 0;i --) {
        heapify(arr, n, i);
    }

    for (int i = n-1; i > 0; i++) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
