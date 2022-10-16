#include <iostream> 
#include <list> 
using namespace std; 
//graph class for DFS travesal  
class DFSGraph { 
    int V;    // No. of vertices 
    list<int> *adjList;    // adjacency list 
    void DFS_util(int v, bool visited[]);  // A function used by DFS 
    public: // class Constructor
    DFSGraph(int V){
        this->V = V; 
        adjList = new list<int>[V]; 
    }
    void addEdge(int v, int w){ // function to add an edge to graph 
    adjList[v].push_back(w); // Add w to v’s list.
    }
    void DFS();    // DFS traversal function 
};

void DFSGraph::DFS_util(int v, bool visited[]){ 
    visited[v] = true; // current node v is visited 
    cout << v << " "; // recursively process all the adjacent vertices of the node 
    list<int>::iterator i; 
    for(i = adjList[v].begin(); i != adjList[v].end(); ++i){
        if(!visited[*i]){
            DFS_util(*i, visited);
        }
   }
} 
   
void DFSGraph::DFS(){// DFS traversal
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    for (int i = 0; i < V; i++){// explore the vertices one by one by recursively calling  DFS_util
        if (visited[i] == false){
            DFS_util(i, visited);
        }
}

int main(){ 
    DFSGraph gdfs(5);// Create a graph
    gdfs.addEdge(0, 1); 
    gdfs.addEdge(0, 2); 
    gdfs.addEdge(0, 3);
    gdfs.addEdge(1, 2); 
    gdfs.addEdge(2, 4);
    gdfs.addEdge(3, 3); 
    gdfs.addEdge(4, 4);
    cout << "Depth-first traversal for the given graph:"<<endl; 
    gdfs.DFS(); 
    return 0; 
}