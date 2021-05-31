#include <iostream>
using namespace std;

class Queue{
    private:
        int head, tail;
		int* data;
		int queueSize, maxQueue;

	public:
		Queue(int maxSize){
			head = 0;
			tail = 0;
			queueSize = 0;
			maxQueue = maxSize;
			data = new int[maxQueue];
		}
		~Queue(){
			delete[] data;
		}

		bool isEmpty(){
			return true ? (queueSize == 0) : false;
		}
		bool isFull(){
			return true? (queueSize == maxQueue) : false;
		}
        
		int enqueue(int value){
			if (isFull()){
                cout << "Stack Overflow!\n";
                return -1;
            }
			data[tail++] = value;
            cout << "Enqueue: " << value << endl;
			queueSize++;
			return 0;
		}

		int* dequeue(){
			if(isEmpty()){
                cout << "Stack Underflow!\n";
                return NULL;
            }
			queueSize--;
			if(head == maxQueue-1){
				head = 0;
                cout << "Dequeue: " << data[maxQueue - 1] << endl;
				return &data[maxQueue-1];
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
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    return 0;
}