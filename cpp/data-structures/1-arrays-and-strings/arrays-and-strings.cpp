#include <iostream>
using namespace std;

const int N = 3;
const int M = 3;

void traverseArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void traverse2Darray(int arr[][M], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

// Traversal using the string class
// Note: parameter could also be (char str[])
void traverseString(string str){
    int i = 0;
    while(str[i] != '\0'){
        cout << str[i];
        i++;
    }
    cout << endl;
}

int main(){
    // 1-D Array
    int arr[] = { 1, 2, 3, 4 };
    
    // Size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "1D Array: ";
    traverseArray(arr, n);
    cout << endl;

    // 2-D Array
    int arr2D[][M] = { { 1, 2 }, { 3, 4} };

    cout << "2D Array: " << endl;
    traverse2Darray(arr2D, N);
    cout << endl;

    // A string implemented using character array
    char chars[] = "I am an array of characters";
    // A string implemented using the string class
    string str = "I was implemented using the string data type";

    traverseString(chars);
    traverseString(str);

    return 0;
}