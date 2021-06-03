#include <iostream>
#include <vector>
#include <queue>
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

        void BFS(vector<int> adj[], int V, int u){
            queue<int> q;
            vector<bool> visited(V, false);
            visited[u] = true;
            q.push(u);

            while(!q.empty()){
                int u = q.front();
                cout << u << " ";
                q.pop();
                vector<int>::iterator i;
                for(i = adj[u].begin(); i != adj[u].end(); i++){
                    if(visited[*i] == false){
                        visited[*i] = true;
                        q.push(*i);
                    }
                }
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

    cout << "Breadth First Search on the graph: \n";
    g.BFS(adj, V, 0);
    cout << endl;

    return 0;
}