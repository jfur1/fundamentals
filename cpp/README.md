# C++ Fundamentals

## Table of Contents

### [Algorithms](algorithms)
  * [Sorting](algorithms/sorting)
  
  * [Searching](algorithms/searching)


### [Data Structures](data-structures)
  * [Arrays and Strings](data-structures/1-arrays-and-strings)

  * [Linked Lists](2-linked-lists)

  * [Stacks and Queues](data-structures/3-stacks-and-queues)

  * [Graphs](data-structures/4-graphs)
  
  * [Bit Manipulation](data-structures/5-bit-manipulation)

  * [Classes](data-structures/6-classes)

<hr/>

![Big-O](data-structures/img/big-o.png)
![ds-ops](data-structures/img/data-structures-big-o.png)
![sort-ops](data-structures/img/array-sorting-big-o.png)
<hr/>

## Asymptotic Analysis

### Time Complexity
For the sake of simplicity, we shall only consider Big-O notation, which is the convention in practice. We can describe the Big-O runtime of an algorithm in 3 different ways. Let's take a look at quicksort as an example:

Quicksort chooses a random element as a "pivot" and then swaps values in the array such that elements less than the pivot come before elements greater than the pivot. This gives us a "partial sort". Then it recursively sorts the left and right subarrays using a similar process.

 - **Best Case**: 
   - If all elements are equal, then quicksort will, on average, traverse through the array only one. This requires **O(N)** time.

 - **Worst Case**:
   - What if we get very unlucky and the pivot is repeatedly the largest element in the array? (Actually, this can easily happen. If the pivot is chosen to be the first element in the subarray and the array is sorted in reverse order, then we'll have this situation). In this case, our recursion doesn't divide the array in half and recurse on each half. It just shrinks our array by one element on each iteration, requiring **O(N^2)** time.

 - **Expected Case**:
   - Typically, these wonderful (or terrible) situations will not occur. Sure, sometimes our pivot may be very low or high, but usually won't happen over and over again. We can expect a runtime of **O(N log N)**.

#### Drop the Constants:
It is very possible for <i>O(N)</i> code to run faster than <i>O(1)</i> code for specific inputs. Big-O simply describes the rate of increase. For this reason, we drop constants when describing runtimes. An algorithm that one might describe as <i>O(2N)</i> is actually <i>O(N)</i>.

#### Drop the Non-Dominant Terms:
What do we do in the case of a runtime like `O(N^2 + N)`? The second `N` isn't exactly a constant, but it's not especially important. We already discussed dropping constants, therefore `O(N^2 + N^2)` would actually just be `O(N^2)`. If we don't care about the second `N^2` term, then why would we care about `N`? We don't. 

You should drop the non-dominant terms:
- O(N^2 + N) becomes O(N^2)
- O(N + log N) becomes O(N)
- O(5 * 2^N + 1000N^100) becomes O(2^N)

We can still have a sum in a rumtime, however. For example, the expression O(B^2 + A) cannot be reduced (without some special knowledge of A and B).

#### Multi-part Algorithms: Add vs. Multiply
Suppose we have an algorithm that has two (or more) steps. When do you multiply the runtimes and when do you add them?

##### Add the Runtimes: O(A + B)
```
  1. for(int a : arrA)
  2.    print(a)
  3.
  4. for(int b : arrB)
  5.    print(b)
```
In this example, we do `A` chunks of work, then `B` chunks of work. Therefore, our total amount of work is **O(A + B)**

##### Multiply the Runtimes: O(A * B)
```
  1. for(int a : arrA)
  2.    for(int b : arrB)
  3.       print(a + ',' + b);
```
In this example, we do `B` chunks of work for each element in `A`. Therefore the total amount of work is **O(A * B)**

In other words:
- If the algorithm takes the form "do this, then, when you're finished, do that", then you add the runtimes.
- If the algorithm takes the form "do this for each time you do that", then you multiply the runtimes.



<hr/>

### Space Complexity
Time is not our only consideration when designing algorithms. We are also concerned with how much memory is required by an algorithm. Spatial asymptotic analysis is parallel with runtime analysis. I.e., if we need to create an array of size `n`, then this will require **O(N)** space. Similarly, a 2D array of size `n` by `n` will require **O(N^2)** space. 

Stack space for recursive function calls is another consideration in spatial complexity analysis. For example, the following code would take both **O(N)** time and **O(N)** space.

```
  1.  int sum(int n){
  2.     if(n <= 0)
  3.         return 0;
  4.     return n + sum(n-1);
  5.  }
```
Each function call adds one level to the call stack:
```
  1.  sum(4)
  2.   -> sum(3)
  3.     -> sum(2)
  4.        -> sum(1)
  5.           -> sum(0)
```
<i>However</i>, just because you have `n` calls in total, does not mean that it requires `O(N)` space. Consider the following example, which adds adjacent elements between 0 and `n`.

```
  1.  int pairSumSequence(int n){
  2.    int sum = 0;
  3.    for(int i = 0; i < n; i++)
  4.       sum += pairSum(i, i+1);
  5.    return sum;
  6.  }
  7.
  8.  int pairSum(int a, int b){
  9.    return a + b;
  10. }
```
There will be roughly <i>O(N)</i> calls to `pairSum()`. However, these calls do not exist simultaneously on the call stack. Therefore, we only need **O(1)** space.


