# [Data Structures](../)

## Linked Lists (C++)

A linked list is a linear data structure in which elements are not stored in contiguous memory locations. The elements in a linked list are linked using pointers.

![linked-list](../img/linked-list.png)

#### Why Linked Lists?
  - Advantages:
    - Dynamic Size
    - Ease of insertion/deletion
  - Disadvantages:
    - Random access not allowed. We have to access elements sequentially starting from the first node.
    - Extra memory space for a pointer is required for each list node.
    - Not cache friendly. Since array elements are contiguous locations, there is a locality of reference that does not exist with linked lists.
  
### Singly Linked List
<b>Representation:</b>
A linked list is represented by a pointer to the first node of the linked list. The first node is called the head. If the linked list is empty, then the head is NULL.

Each node consists of 2 parts:
  1. Data
  2. A pointer (or reference) to the next node.

In C++, LinkedList can be represented as a class and a Node as a seperate class. The LinkedList class will contain reference to the Node class type.
  
  > ```
  > class Node{
  >    public:
  >       int data;
  >       Node* next;
  > }

### Doubly Linked List
<b>Representation:</b>
A doubly linked list contains an extra pointer, typically called a <i>previous pointer</i>, along with the `next` pointer and `data` which are found in a singly linked list.

![DLL](../img/doubly-linked-list.png)

Each node consists of 2 parts:
  1. Data
  2. A pointer (or reference) to the next node.
  3. A pointer (or reference) to the previous node.

In C++, DoublyLinkedList can be represented as a class and a Node as a seperate class. The DoublyLinkedList class will contain reference to the Node class type.
  
  > ```
  > class Node{
  >    public:
  >       int data;
  >       Node* next;
  >       Node* prev;
  > }
