#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

// Function to print a linked list, starting at the given node
void printList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Allocate 3 nodes onto the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);

    return 0;
}