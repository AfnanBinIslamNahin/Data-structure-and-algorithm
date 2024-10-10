
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int first ,int last , int target) {

    while (first <= last) {

        int mid = (first + last)/ 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            first = mid + 1;
        else
            last= mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int target = 40;
      int n=sizeof(arr)/sizeof(arr[0]);
    int result = binarySearch(arr,0,n-1, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
