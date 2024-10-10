#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int L, int mid, int h) {
    int i = L;
    int j = mid + 1;
    int k = L;
    int temp[h + 1]; // Creating a temporary array to store merged elements

    while (i <= mid && j <= h) {
        if (A[i] <= A[j]) {
            temp[k] = A[i];
            i++;
        } else {
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    if(i>mid){
    while (j <= h) {
        temp[k] = A[j];
        j++;
        k++;
    }

}    else{
         while (i <= mid) {
        temp[k] = A[i];
        i++;
        k++;
    }
    }

    // Copy elements from temporary array to original array A
    for (int x = L; x <= h; x++) {
        A[x] = temp[x];
    }

}
void mergeSort(int A[], int L, int h) {
    if (L < h) {
        int mid = (L + h) / 2;
        mergeSort(A, L, mid);
        mergeSort(A, mid + 1, h);
        merge(A, L, mid, h);
    }
}

int main() {
    // Example usage
    int A[] = {4,1,20,12,11,9,5,0,34,54,21,34,76,89,98,76,898};
    int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);

    cout << "Sorted array after merging: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
