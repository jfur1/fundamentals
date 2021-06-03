#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Directed graph using adjacency list
class Graph{
    public:
        // Add vertex v to vertex u's adjacency list
        void addEdge(vector<int> adj[], int u, int v){
            adj[u].push_back(v);
        }

        void DFSutil(int u, vector<int> adj[], vector<bool> &visited){
            visited[u] = true;
            cout << u << " ";
            for(int i = 0; i < adj[u].size(); i++){
                if(visited[adj[u][i]] == false)
                    DFSutil(adj[u][i], adj, visited);
            }
        }

        // Function performs DFS on the graph starting from node v
        void DFS(vector<int> adj[], int V){
            vector<bool> visited(V, false);
            for(int u = 0; u < V; u++){
                if(visited[u] == false)
                    DFSutil(u, adj, visited);
            }
        }
};

int main(){

    int V = 6;
    Graph g;

    vector<int> adj[V];

    g.addEdge(adj, 0, 1);
    g.addEdge(adj, 0, 4);
    g.addEdge(adj, 1, 2);
    g.addEdge(adj, 1, 3);
    g.addEdge(adj, 2, 4);
    g.addEdge(adj, 2, 0);
    g.addEdge(adj, 3, 1);
    g.addEdge(adj, 4, 5);

    cout << "Depth First Search on the graph: \n";
    g.DFS(adj, V);
    cout << endl;

    return 0;
}