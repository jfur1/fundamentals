# Sorting Algorithms

## Divide and Conquer Algorithms
In divide and conquer algorithms, the idea is to solve the problem in two sections. The first section divides the problem into subproblems of the same type. The second section solves the smaller problem independently and then adds the combined results to return the final solution to the problem.

### Merge Sort
Merge sort divides the input array into two halves, calls itself on the two halves, then merges the two sorted halves. The `merge()` function is used to merge the two sorted halves. 

<img src="../img/merge-sort.png"/>

- Time Complexity: O(N log N) for all 3 cases (worst, average, and best)
  - Mergesort always divides the array into two halves and takes linear time to merge the two halves.
- Space Complexity: O(N)

Applications of Mergesort:
1. Usefor for [sorting linked lists](https://www.geeksforgeeks.org/merge-sort-for-linked-list/) in O(N log N) time -- requires no auxilary space!
2. [Inverted counting](https://www.geeksforgeeks.org/counting-inversions/)
3. [External sorting](https://en.wikipedia.org/wiki/External_sorting)


### Quick Sort



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
