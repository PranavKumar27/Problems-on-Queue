#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Coded by @Pranav on Jan 30, 2022
//Problem : Implement a sliding window and find the max element in the window
// Solution : use a priority queue of window w,
// Pop element that is the maximum
// Create a new Priority queue with new set of elements in a window

void print(priority_queue<int> p);

int main() {
	
	vector<int> v= {1,3,-1,-3,5,3,6,7};
	int w=3;
	vector<int> vmax;
	int i,j;
	for(i=0;i<=v.size()-w;i++)
	{
	    priority_queue<int> pq;
	    for(j=i;j<i+w;j++)
	    {
	        pq.push(v[j]);
	    }
	    vmax.push_back(pq.top());
	    print(pq);
	}
	
	// Print the vector max
	
	for(auto a:vmax)
	{
	    cout << a << ","; 
	}
	cout << endl;
	
	
	return 0;
}

void print(priority_queue<int> p)
{
    priority_queue<int> q=p;
    
    while(!q.empty())
    {
        cout << q.top() << ",";
        q.pop();
    }
    
    cout << endl;
}
