# [Data Structures](../)

## Stacks and Queues

### Stacks
The stack data structure is precisely what is sounds like: a stack of data. In certain types of problems, it can be favorable to store data in a stack over an array.

A stack uses LIFO (last in, first out) ordering. Like a stack of dinner plates, the most recent item added to the stack is the first item to be removed.

It uses the following operations:
  - `pop()`: Remove the top item from the stack
  - `push(item)`: Add an item to the top of the stack
  - `peek()`: Return the top of the stack
  - `isEmpty()`: Return true if and only if the stack is empty.

Unlike an array, a stack does not offer constant time access to the <i>i</i>th item. However, it does allow constant-time insertion and deletion, since it does not require moving items around. 

Stacks are often useful in recursive algorithms. Sometimes you need to push temporary data onto the stack as you recurse, but then remove them as you backtrack. 

### Queues

A queue data structure is also exactly what it sounds like: a linear ordering of items. A queue uses FIFO (first in, first out) ordering. Like a line or a queue at a ticket stand, items are removed from the data structure in the same order they were added.

It uses the following operations:
  - `enqueue(item)`: Add an item to the end of the queue.
  - `dequeue()`: Remove the first item from the queue.
  - `peek()`: Return the top of the queue
  - `isEmpty()`: Return true if and only if the queue is empty.

One place where queues are often used is in breadth-first search or implementing caches.
