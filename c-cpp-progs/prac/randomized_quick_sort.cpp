#include <iostream>
#include <ctime>
#define rep(i, a, b) for (int i = a;i < b; i++)
using namespace std;

int partition(int arr[], int l, int h) {
    srand(time(0));
    int randIndex = l + rand() % (h - l);
    swap(arr[randIndex], arr[l]);
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j) {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n);
    rep(i, 0, n) 
    {
        cout << arr[i] << " ";
    }
}