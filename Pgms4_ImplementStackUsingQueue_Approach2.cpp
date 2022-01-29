#include <iostream>
using namespace std;
#include <queue>

//Problem : Implement queue using two stacks
// Method 2: 
// Push:    Add item to q1  
// Pop:     Pop all the item from q1 to q2 uptill last element
//          Copy all items from q2 to q1
// Top:     Go upto last element in q1 and return it

class MyStack
{
    
    queue<int> q1,q2;
    
    public:
    void push(int data)
    {
        q1.push(data);
    }
    
    void pop()
    {
        int i= 0;
        int sz=q1.size();
        // Move q1 to q2 except last item
        while(!q1.empty() && i!=sz-1) 
        {
            i++;
            q2.push(q1.front());
            q1.pop();
        }
        
        // Pop Last item
        q1.pop();
        
        
        // Copy q2 back to q1
        while(!q2.empty()) 
        {
            q1.push(q2.front());
            q2.pop();
        }
        
    }
    
    int top()
    {
        int val;
        queue<int> qq1=q1;
        
        while(!qq1.empty() ) 
        {
            val=qq1.front();
            qq1.pop();
        }
        
        return val;
        
    }
};
int main() {
	
	
	MyStack s1;
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	
	cout << "5 4 3 2 1 , s1.top()=" << s1.top() << endl;
	
	s1.pop();
	s1.pop();
	
	cout << "3 2 1 , s1.top()=" << s1.top() << endl;
	
	s1.push(6);
	s1.push(7);
	
	cout << "7 6 3 2 1 , s1.top()=" << s1.top() << endl;
	
	return 0;
}
