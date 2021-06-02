#include <iostream>
using namespace std;

// Utility function used to swap two elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

/*
    Function takes the LAST element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionLast(int arr, int low, int high){


}

/*
    Function takes the FIRST element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionFirst(int arr, int low, int high){


}

/*
    Function takes the MEDIAN element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionMedian(int arr, int low, int high){


}

/*
    Function takes a RANDOM element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionRandom(int arr, int low, int high){


}


/* Function to print an array */
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char* argv[]){

    return 0;
}