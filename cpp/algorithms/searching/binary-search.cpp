#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = l + (r - l) / 2;

        // If the target == middle
        if(arr[mid] == x) return mid;

        if(arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    // If element not present in the array return -1
    return -1;
}

int main(){
    int arr[] = { 2, 3, 4, 10, 40 };
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, target);
    (result == -1) ? cout << "Value: " << target << " is not present in array"
                   : cout << "Value: " << target << " is present at index " << result;
    return 0;
}