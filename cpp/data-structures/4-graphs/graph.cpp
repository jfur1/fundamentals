#include <iostream>
#include <vector>
using namespace std;

class Node{
    int data;
    Node* next;
};

class WeightedNode{
    int data, cost;
    Node* next;
};

// Queue used for BFS
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
                //cout << "Stack Overflow!\n";
                return -1;
            }
			data[tail++] = value;
            //cout << "Enqueue: " << value << endl;
			queueSize++;
			return 0;
		}

		int* dequeue(){
			if(isEmpty()){
                //cout << "Stack Underflow!\n";
                return NULL;
            }
			queueSize--;
			if(head == maxQueue-1){
				head = 0;
                //cout << "Dequeue: " << data[maxQueue - 1] << endl;
				return &data[maxQueue-1];
			}
			else{
                int* x = &data[head++];
                //cout << "Dequeue: " << x << endl;
				return x;
			}
		}
};
// Unweighted, Undirected Graph
class Graph{
    public:
        void addEdge(vector<int> adj_list[], int u, int v){
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

                void DFSutil(int u, vector<int> adj[], vector<bool> &visited){
                visited[u] = true; 
                cout << u << " "; 
                for (int i=0; i <adj[u].size(); i++) 
                    if (visited[adj[u][i]] == false) 
                        DFSutil(adj[u][i], adj, visited); 
        }

        // This function does DFSUtil() for all  
        // unvisited vertices. 
        void DFS(vector<int> adj[], int V) 
        { 
            vector<bool> visited(V, false); 
            for (int u=0; u<V; u++) 
                if (visited[u] == false) 
                    DFSutil(u, adj, visited); 
        }

        void BFS(vector<int> adj[], int V, int u){
            Queue *q = new Queue(V);
            vector<bool> visited(V, false);
            visited[u] = true;
            q->enqueue(u);

            while(!q->isEmpty()){
                int *u = q->dequeue();
                cout << *u << " ";
                vector<int>::iterator i;
                for(i = adj[*u].begin(); i != adj[*u].end(); ++i){
                    if (visited[*i] == false){
                        visited[*i] = true;
                        q->enqueue(*i);
                    }
                }
            }
        }
};

int main(){

    int V = 5; 
    Graph g;
  
    // The below line may not work on all 
    // compilers.  If it does not work on 
    // your compiler, please replace it with 
    // following 
    // vector<int> *adj = new vector<int>[V]; 
    vector<int> adj[V]; 
  
    // Add nodes/edges to the graph
    g.addEdge(adj, 0, 1); 
    g.addEdge(adj, 0, 4); 
    g.addEdge(adj, 1, 2); 
    g.addEdge(adj, 1, 3); 
    g.addEdge(adj, 1, 4); 
    g.addEdge(adj, 2, 3); 
    g.addEdge(adj, 3, 4); 


    cout << "Depth First Search on the graph: \n";
    g.DFS(adj, V);
    cout << "\nBreadth First Search on the graph: \n";
    g.BFS(adj, V, 3);
    cout << endl;

    return 0;
}