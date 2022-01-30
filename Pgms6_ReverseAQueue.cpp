#include <iostream>
using namespace std;
#include <stack>
#include <queue>

// Coded by @Pranav on Jan 30, 2022
//Problem : Reverse a Queue
// Solution : use a stack to reverse

void print(queue<int> p);

int main() {
	
	queue<int> q;
	
	int i;
	for(i=1;i<=5;i++)
	{
	    q.push(i);
	}
	
	stack<int> s;
	
	while(!q.empty())
	{
	    s.push(q.front()); // NOTE: top() is defined for priority_queue<int> 
	                        //and front() is defined for queue<int>
	    q.pop();
	}
	
	// Save Stack to queue 
	
	while(!s.empty())
	{
	    q.push(s.top());
	    s.pop();
	}
	
	print(q);
	

	return 0;
}

void print(queue<int> p)
{
    queue<int> q=p;
    
    while(!q.empty())
    {
        cout << q.front() << ",";
        q.pop();
    }
    
    cout << endl;
}
