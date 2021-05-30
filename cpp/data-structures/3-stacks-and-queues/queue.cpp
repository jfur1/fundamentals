#include <iostream>
using namespace std;

class Queue{
    private:
        int head, tail;
		int* data;
		int queueSize, maxSize;
		//Private Methods
		bool isEmpty(){
			return true ? (queueSize == 0) : false;
		}
		bool isFull(){
			return true? (queueSize == maxSize) : false;
		}
    public:
        // Default Constructor
        Queue(int maxSize){
            head = -1;
            tail = -1;
            queueSize = 0;
            maxSize = maxSize;
            data = new int[maxSize];
        }

        // Destructor
        ~Queue(){
            delete[] data;
        }

        int enqueue(int value){
            if(isFull()){
                cout << "Queue overflow" << endl;
                return -1;
            }
            data[tail++] = value;
            cout << "Enqueued: " << value << endl;
            queueSize++;
            return 0;
        }

        int* dequeue(){
            if(isEmpty()){
                cout << "Queue underflow" << endl;
                return NULL;
            }
            queueSize--;
            if(head == maxSize - 1){
                head = 0;
                cout << "Dequeue: " << data[maxSize - 1] << endl;
                return &data[maxSize - 1];
            }
            else{
                cout << "Dequeue: " << data[head++] << endl;
                return &data[head];
            }
        }
};

int main(){
    Queue myQueue(5);

	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
    myQueue.enqueue(5);
	myQueue.enqueue(6);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    return 0;
}