# Sorting Algorithms

## Divide and Conquer Algorithms
In divide and conquer algorithms, the idea is to solve the problem in two sections. The first section divides the problem into subproblems of the same type. The second section solves the smaller problem independently and then adds the combined results to return the final solution to the problem.

### Merge Sort
Merge sort divides the input array into two halves, calls itself on the two halves, then merges the two sorted halves. The `merge()` function is used to merge the two sorted halves. 

<img src="../img/merge-sort.png"/>

- **Time Complexity:** **O(N log N)** for all 3 cases (worst, average, and best)
  - Mergesort always divides the array into two halves and takes linear time to merge the two halves.
- **Space Complexity:** **O(N)**
  - The space required for temp arrays L[] and R[]

Applications of Mergesort:
1. Usefor for [sorting linked lists](https://www.geeksforgeeks.org/merge-sort-for-linked-list/) in O(N log N) time -- requires no auxilary space!
2. [Inverted counting](https://www.geeksforgeeks.org/counting-inversions/)
3. [External sorting](https://en.wikipedia.org/wiki/External_sorting)


### Quick Sort
Like mergesort, Quicksort is another divide and conquer algorithm. It picks an element as a pivot and partitions the given array around that pivot. There are four main versions of quicksort that choose the pivot in different ways:
  1. Always pick the first element as the pivot
  2. Always pick the last element as the pivot
  3. Pick a random element as the pivot
  4. Pick the median as the pivot

The key process in Quicksort is the `partition()` function. The target of partition is, given an array and an element x of the array as a pivot, put element x at its correct position in the sorted array. Then, put all elements less than x before x, and all elements greater than x after x. This is all acheived in linear time. 

<img src="../img/quick-sort.png"/>

- **Time Complexity**: 
  - Worst Case: **O(n^2)**
  - Average Case: **O(N log N)**
  - Best Case: **O(N log N)**
- **Space Complexity**:
  - **O(1)** -- no auxilary space necessary!

Advantages:
- In-place sorting algorithm -- no auxilary space required
<hr/>

### Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

C++ Implementation:
```
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
```

### Heap Sort
Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning. We repeat the same process for the remaining elements.

> Complexity:
>   - Time: O(N Log N)
>   - Space: O(1)

## Dynamic Programming (Memoization) Algorithms
In dynamic programming, we using memoization to avoid repeated work by storing previously calculated results. The problem is divided into smaller, overlapping subproblems and the results are stored for future use.

Examples Include:
- Dijkstra's Shortest Path Algorithm
- Knapsack Problem
- Weighted Job Scheduling

## Greedy Algorithms
In greedy algorithms, the final solution is built part by part. The decision to choose the next part is done on the basis that it produces an immediate result. It never considers previous decisions.

Examples Include:
- Greedy Best First Search
- Prim's Algorithm
- Huffman Coding

## Backtracking Algorithms
Bracktracking algorithms involve solving a problem incrementally. The problem is solved by incrementally building a solution using recursive results one peice at a time, while removing any results that fail to satisfy the problem constraints.

Examples Include:
- Hamiltonian Cycles
- M-Coloring Problem
- Rat in a Maze Problem 
