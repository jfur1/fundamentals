#include <iostream>
using namespace std;

// Utility function used to swap two elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

typedef void (* partition)(int arr[], int low, int high);

/*
    Function takes the LAST element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionLast(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

/*
    Function takes the FIRST element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionFirst(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    
    for(int j = low + 1; j <= high; j++){
        if(arr[j] < pivot){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i-1]);
    return (i - 1);
}

/*
    Function takes the MEDIAN element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionMedian(int arr[], int low, int high){

    return 0;
}

/*
    Function takes a RANDOM element to be the pivot.
    Places the pivot at its correct position in the sorted array,
    and places all elements less than pivot to the left of pivot,
    and places all elements greater than pivot to the right of pivot.
*/
int partitionRandom(int arr[], int low, int high){

    return 0;
}

void quicksort(int arr[], int low, int high, int (* partition)(int arr[], int low, int high)){
    if(low < high){
        // pi is the partitioning index, arr[p] is now at the right place
        int pi = partition(arr, low, high);

        // Seperately sort elements before partition and after partition
        quicksort(arr, low, pi - 1, partition);
        quicksort(arr, pi + 1, high, partition);
    }
}


/* Function to print an array */
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char* argv[]){
    // cout << "argc: " << argc << endl;
    // cout << "argv[1]: " << argv[1] << endl;

    int arr[] = { 5, 3, 7, 9, 1, 2, 4, 8, 6 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Given array: \n";
    printArray(arr, arr_size);
    
    if(argc > 1){
        if(string(argv[1]) ==  "last")
            quicksort(arr, 0, arr_size - 1, &partitionLast);
        else if(string(argv[1]) ==  "first")
            quicksort(arr, 0, arr_size - 1, &partitionFirst);
        else if(string(argv[1]) ==  "median")
            quicksort(arr, 0, arr_size - 1, &partitionMedian);
        else if(string(argv[1]) ==  "random")
            quicksort(arr, 0, arr_size - 1, &partitionRandom);
    }

    cout << "Sorted array: \n";
    printArray(arr, arr_size);

    return 0;
}