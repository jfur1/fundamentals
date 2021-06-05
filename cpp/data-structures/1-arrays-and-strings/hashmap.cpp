#include <iostream>
#include <list>
using namespace std;

class Hash{
    // Number of "buckets"
    int N;

    // Pointer to a list containing our "buckets"
    list<int> *table;

    public:
        Hash(int V){
            this->N = V;
            table = new list<int>[N];
        }
        ~Hash(){
            delete[] table;
        }

        // Simple hashing function that computes key using (value % N)
        int hashFunction(int x){
            return (x % N);
        }

        void insert(int key){
            // Get the hash index for the key
            int index = hashFunction(key);
            table[index].push_back(key);
        }

        void deleteItem(int key){
            int index = hashFunction(key);

            // Find the key in the table
            list<int>::iterator i;
            for(i = table[index].begin(); i != table[index].end(); i++)
                if(*i == key)
                    break;
            
            // If the key is found in our hash table, then remove it
            if(i != table[index].end())
                table[index].erase(i);
        }

        void printHash(){
            for(int i = 0; i < N; i++){
                cout << i;
                for(auto x : table[i])
                    cout << " --> " << x;
                cout << endl;
            }
        }
};


int main(){

  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
  
  // insert the keys into the hash table
  Hash h(7);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++) 
    h.insert(a[i]);  
  
  // delete 12 from hash table
  h.deleteItem(12);
  
  // display the Hash table
  h.printHash();
    return 0;
}