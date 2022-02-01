#include <iostream>
using namespace std;
#include <list>
#include <queue>
#include <cstring> // For Memset()

// Coded by @Pranav on Feb 1, 2022
//Problem : Shortest path in a Binary Maze
// Solution : Add the distance+1 for each adjacent vertex using BFS
//           Once src and dest are same return the distance

#define ROW 3 
#define COL 3 


struct Point
{
    int x,y;
};

struct QNode
{
    Point p;
    int dist;
};

bool IsValid(int r,int c)
{
    if(r>=0 && r<ROW && c>= 0 && c<COL)
        return true;
    else
        return false;
}
int RowNum[4]={-1,0,0,1};
int ColNum[4]={0,-1,1,0};

int ShortestPathinMaze(int Adj[][3],Point src,Point dest)
{
    int i;
    if(!Adj[src.x][src.y] && !Adj[dest.x][dest.y])
        return -1;
        
    bool visited[ROW][COL];
    memset(visited,false,sizeof(visited));
    
    QNode obj={src,0};
    queue<QNode> Q;
    Q.push(obj);
    visited[src.x][src.y]=true;
    
    while(!Q.empty())
    {
        QNode cur=Q.front();
        
        Point pt=cur.p;
        int pt_dist=cur.dist;
        
        Q.pop();
        
        if(pt.x==dest.x && pt.y==dest.y)
            return pt_dist;
        
        for(i=0;i<4;i++)
        {
            int row=pt.x+RowNum[i];
            int col=pt.y+ColNum[i];
            
            if(IsValid(row,col) && !visited[row][col] && Adj[row][col])
            {
                Point newPoint={row,col};
                QNode newobj={newPoint,pt_dist+1};
                visited[row][col]=true;
                Q.push(newobj);
            }
        }
    }
    
    return -1;
}

int main() {
    
    int Adj[3][3]= {
                   {1,1,1},
                   {1,0,1},
                   {1,0,1}
                   };
                   
    Point src={0,1};
    
    Point dest={2,2};
    
    
    cout  << "ShortestPathinMaze = " << ShortestPathinMaze(Adj,src,dest) << endl;
    
    
    return 0;
    
}

