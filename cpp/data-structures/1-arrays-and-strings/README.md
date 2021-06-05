# [Data Structures](../)

## Arrays and Strings (C++)

### Strings:

Internally, C++ uses a character array to store strings. Memory management, allocation, and null termination are all handled by the string class itself, which is why it's easy to use. 

  > char str[] = "hello world!"

### Arrays:
An array in C or C++ is a collection of items stored at contiguous memory locations and elements can be accessed randomly using indices of the array.

  - One Dimensional Array:

    > data_type variable_name[size]
    >  
    >  <b>data_type</b> is the type of array (i.e., int, float, char, etc.)<br/>
    >  <b>variable_name</b> is the name of the array.<br/>
    >  <b>size</b> is the length of the array which is fixed.

  - Two Dimensional Array (Matrix):
    
    > data_type variable_name[N][M]
    > 
    > <b>data_type</b> is the type of array (i.e., int, float, char, etc.)<br/>
    > <b>variable_name</b> is the name of the array.<br/>
    > <b>N</b> is the number of rows. <br/>
    > <b>M</b> is the numbers of columns.



### Hashing:

Hashing is a technique or process of mapping keys, values into the hash table by using a hash function. It is done for faster access to elements. The efficiency of mapping depends on the efficiency of the hash function used. A simple example is direct indexing, as is used to access elements of an array; however, there is a chance that the hash function generates a key that maps to an existing value. This is known as a hash collision.

> What are the chances of a hash collision in a large table?
> - Collisions are very likely even if we have a large table for storing keys. An important observation is the [birthday paradox](https://www.geeksforgeeks.org/birthday-paradox/). With only 23 people, the probability that 2 people have the same birthday is 50%.

#### How do we handle collisions?
  <b>1) Seperate Chaining:</b> each cell of hash table points to a linked list of nodes that have same hash function value. 
    
    Advantages: 
      1) Simple to implement. 
      2) Hash table never fills up, we can always add more elements to the chain. 
      3) Less sensitive to the hash function or load factors. 
      4) It is mostly used when it is unknown how many and how frequently keys may be inserted or deleted. 

    Disadvantages: 
      1) Cache performance of chaining is not good as keys are stored using a linked list. Open addressing provides better cache performance as everything is stored in the same table. 
      2) Wastage of Space (Some Parts of hash table are never used) 
      3) If the chain becomes long, then search time can become O(n) in the worst case. 
      4) Uses extra space for links. 

  <b>2) Open Addessing:</b>  all elements are stored in the hash table itself. So at any point, the size of the table must be greater than or equal to the total number of keys (Note that we can increase table size by copying old data if needed). 
