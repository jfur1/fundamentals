#include <iostream>
using namespace std;

class Stack{
    private:
        int top;
        int max_size;
        int* data;

    public:
        // Default Constructor
        Stack(int size){
            top = -1;
            max_size = size;
            data = new int[max_size];
        }

        // Destructor
        ~Stack(){
            delete[] data;
        }

        bool isFull(){
            return true ? (top == max_size - 1) : false;
        }

        bool isEmpty(){
            return true ? (top == -1) : false;
        }

        int push(int value){
            if(isFull())
                return -1;

            data[top++] = value;

            return 0;
        }

        int* pop(){
            if(isEmpty())
                return NULL;
            return &data[top--];
        }

        int peek(){
            if(isEmpty())
                return -1;
            int x = data[top];
            return x;
        }
};


int main(){

    Stack myStack(5);

    // Test Full/Empty
	cout << "\t---TEST FULL/EMPTY---" << endl;
	cout << "\tFull?: " << myStack.isFull() << endl;
	cout << "\tEmpty?: " << myStack.isEmpty() << endl;
	cout << endl;

    // Test push
	int returned;
	cout << "\t---PUSH---" << endl;
	for(int i = 0; i < 6; i++){	
		returned = myStack.push(i+1); //Push values 1-11 into the 10 slot array
		if(!returned){ //If the value is pushed print "Pushed: num"
			cout << "\tPushed: " << i+1 << endl;
		}
		else{ // If the stack is full, give error message
			cout << "\tStack is full! Failed to push " << i+1 << "." << endl;
		}
	}
	cout << "\tFull after push?: " << myStack.isFull() << endl;
	cout << "\tEmpty after push?: " << myStack.isEmpty() << endl;
	cout << endl;

    return 0;
}