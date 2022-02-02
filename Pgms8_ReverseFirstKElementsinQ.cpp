#include <iostream>
using namespace std;
#include <deque>
#include <queue>

// Coded by @Pranav on Jan 30, 2022
//Problem : Reverse first K element from given queue
// Solution : Use deque stl and push_front and then pop_back each item
//           and push_front to the original queue
//           A stack could also be used here for revereing


void printQ(queue<int> q);
void printDQ(deque<int> dq);

int main() {
	
	
    int K=4;
    queue<int>q;
    int i,val;
    
    for(i=10;i<=100;i+=10)
    {
        q.push(i);
    }
    printQ(q);
    deque<int>dq;
    
    for(i=0;i<K&& i<q.size();i++)
    {
        dq.push_back(q.front());
        q.pop();
    }
    
    queue<int> ResQ;
    printDQ(dq);
    while(!dq.empty())
    {
        val=dq.back();
        dq.pop_back();
        ResQ.push(val);
    }
    
    while(!q.empty())
    {
        val=q.front();
        q.pop();
        ResQ.push(val);
    }
    
    
    printQ(ResQ);
    
    
	return 0;
}

void printQ(queue<int> q)
{
    cout << "Queue=";
    queue<int> Q=q;
    while(!Q.empty())
    {
        cout << Q.front() << ",";
        Q.pop();
    }
    cout <<  endl;
}

void printDQ(deque<int> dq)
{
    cout << "Queue=";
    deque<int> Q=dq;
    while(!Q.empty())
    {
        cout << Q.front() << ",";
        Q.pop_front();
    }
    cout <<  endl;
}
