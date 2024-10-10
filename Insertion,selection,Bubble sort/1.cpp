#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int A[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[minIndex]) {
                  minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(A[i], A[minIndex]);
        }
    }
}

void InsertionSort(int A[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

void BubbleSort(int A[], int size) {
    for (int i = 0; i < size - 1; i++) {
         int   flag=0;
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                flag=1;
            }
        }
       if(flag==0)break;
    }
}

void DisplayArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout<<endl;
}
int main() {
    int A[] = {64, 25, 12, 22,90,78,65,34,50,43,22,11};
    int size = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    DisplayArray(A, size);

    cout << "Selection Sort: ";
    SelectionSort(A, size);
    DisplayArray(A, size);

    cout << "Insertion Sort: ";
    InsertionSort(A, size);
    DisplayArray(A, size);

    cout << "Bubble Sort   : ";
    BubbleSort(A, size);
    DisplayArray(A, size);


    return 0;
}

