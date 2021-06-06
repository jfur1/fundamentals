#include <iostream>
using namespace std;

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap{
    // Pointer to an array of elements in the heap
    int *heapArr;
    int capacity;
    int heap_size;

    public:
        MinHeap(int capacity){
            this->capacity = capacity;
            this->heap_size = 0;
            this->heapArr = new int[capacity];
        }
        ~MinHeap(){
            delete[] heapArr;
        }
        
        int parent(int i) { return (i-1)/2; }
  
        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }
    
        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }

        // Returns the minimum key (key at root) from min heap
        int getMin() { return heapArr[0]; }

        void insertKey(int key){
            if(heap_size == capacity){
                cout << "\nHeap Overflow! Unable to insert key.\n";
                return;
            }

            // 1) Insert new key at the end of the heapArray
            heap_size++;
            int i = heap_size - 1;
            heapArr[i] = key;

            while(i != 0 && heapArr[parent(i)] > heapArr[i]){
                swap(&heapArr[i], &heapArr[parent(i)]);
                i = parent(i);
            }
        }

        // Function decreases value of key at index 'i' to new_val. 
        // It's assumed that new_val < heapArr[i]
        void decreaseKey(int i, int new_val){
            heapArr[i] = new_val;
            while(i != 0 && heapArr[parent(i)] > heapArr[i]){
                swap(&heapArr[i], &heapArr[parent(i)]);
                i = parent(i);
            }
        }

        // Method to remove minimum element (root) from the min-heap
        int extractMin(){
            if(heap_size <= 0) return INT_MAX;
            if(heap_size == 1){
                heap_size--;
                return heapArr[0];
            }

            // Store min value and remove
            int root = heapArr[0];
            heapArr[0] = heapArr[heap_size - 1];
            heap_size--;
            MinHeapify(0);
            
            return root;
        }

        // Method deletes a key at index i. First reduce to infinity, then extract min
        void deleteKey(int i){
            decreaseKey(i, INT_MIN);
            extractMin();
        }

        // Recursive method to heapify a subtree with the root at a given index
        // Method assumes subtrees already heapified
        void MinHeapify(int i){
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if(l < heap_size && heapArr[l] < heapArr[i])
                smallest = l;
            if(r < heap_size && heapArr[r] < heapArr[smallest])
                smallest = r;
            if(smallest != i){
                swap(&heapArr[i], &heapArr[smallest]);
                MinHeapify(smallest);
            }
        }
};



int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}