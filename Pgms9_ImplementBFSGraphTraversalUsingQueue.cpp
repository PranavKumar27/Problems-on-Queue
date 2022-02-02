#include <iostream>
using namespace std;
#include <list>
#include <queue>
#include <cstring> // For Memset()

// Coded by @Pranav on Feb 1, 2022
//Problem : Implement BFS
// Solution : Use queue to store nodes,
//           adjacency list and visited array

class Graph
{
  list<int> *Adj;
  int V;
  public:
    Graph(int vertices)
    {
       V=vertices;
       Adj=new list<int>[V]; 
    }
    
    void addEdge(int v,int u)
    {
        Adj[v].push_back(u);
    }
    void BFS(int s)
    {
        bool *visited=new bool[V];
//         for(int j=0;j<V;j++)
//         {
//             visited[j]=false;
//         }
        memset(visited, false, sizeof visited);
	    
        queue<int> Q;
        Q.push(s);
        visited[s]=true;
        int node;
        
        list<int>::iterator itr;
        while(!Q.empty())
        {
           node=Q.front();
           cout << node << ",";
           Q.pop();
           
           for(itr=Adj[node].begin();itr!=Adj[node].end();itr++)
           {
               if(!visited[*itr])
               {
                   Q.push(*itr);
                   visited[*itr]=true;
               }
           }
        }  
    }
};

int main() {
  
    Graph g(7);  // Always provide the correct number of nodes else SIGSEGV error is seen
    g.addEdge(0, 1);
    g.addEdge(1, 0); // a -> b and b -->a means undirected edge, No direction
    g.addEdge(1, 2); 
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(1, 4);  // 1->4 is directed, can go from 1 to 4 and not from 4 to 1
    g.addEdge(2, 5);
    g.addEdge(4, 6);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
	
// 	int r,c;
// 	r=ROW;
// 	c=COL;
// 	int Adj[8][8]={
// 	                {0,1,0,0,0,0,0,0},
// 	                {1,0,1,0,0,0,0,1}, 
// 	                {0,1,0,1,1,0,0,0},
// 	                {0,0,1,0,0,0,0,0}, 
// 	                {0,0,1,0,0,1,1,0},
// 	                {0,0,0,0,1,0,0,0},
// 	                {0,0,0,0,1,0,0,0},
// 	                {0,1,0,0,0,0,0,0}
//                 	};
                	
//     vector<int> visited = {0,0,0,0,0,0,0,0};
    
//     int i,j,k;
//     queue<int> Q;
    
//     for(i=0;i<r;i++)
//     {
//         for(j=0;j<c;j++)
//         {
//             if(Adj[i][j]==1 && !visited[i])
//             {
//                 visited[i]=1;
//                 Q.push(i);
//             }
//         }
//     }
    
//     printQ(Q);

    return 0;   
}
