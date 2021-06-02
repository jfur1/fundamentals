#include <iostream>
using namespace std;

// Function to merge two subarrays of arr[]
// First subarray is arr[l...m]
// Second subarray is arr[m+1...r]
void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }

    // Merge the temp arrays back into arr[l...r]
    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if there are any
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy remaining elements of R[], if there are any
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r){
    if(l >= r) return;
    int m = l + (r-l) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergesort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}