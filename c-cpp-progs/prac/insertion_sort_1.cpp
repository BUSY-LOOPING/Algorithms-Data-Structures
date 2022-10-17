#include <iostream>
#include<time.h>
using namespace std;

int insertionSort(int arr[], int n) {
    int noCmp = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp) {
            noCmp++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j +1] = temp;
    }
    return noCmp;
}


int main() {
    srand(time(0));


    cout << endl;
    int m = 0;
    while (m < 10) {
        int n = rand() % 1000;
        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand();
        }
        cout << "\nno of comparisons for size " << n << " is " << insertionSort(a, n);
        m++;
    } 

}

void insertionSort2(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    
}