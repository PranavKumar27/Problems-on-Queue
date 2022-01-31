#include <iostream>
using namespace std;
#include <queue>

//Coded on Jan 29, 2022
//Problem : Implement stack using two queues
// Method 1: 
// Push:    Add item to q2  
//          pop all items from q1 into q2, q1 empties itself
//          Rename q2 to q1 and q2 to q1
// Pop:     Pop the item from q1
// Top:     Get the top from q1

class MyStack
{
    
    queue<int> q1,q2;
    
    public:
    void push(int data)
    {
        int val;
        q2.push(data);
        
        while(q1.size()>0)
        {
            val=q1.front();
            q1.pop();
            q2.push(val);
        }
        
        while(q2.size()>0)
        {
            val=q2.front();
            q2.pop();
            q1.push(val);
        }
    }
    
    void pop()
    {
        if(q1.size()>0)
        {
            q1.pop();
        }
        else
        {
            cout << "pop() Failed !! Stack is Still Empty" << endl;
        }
    }
    
    int top()
    {
        int val;
        
        if(q1.size()>0)
        {
            val=q1.front();
        }
        else
        {
            cout << "top() Failed !! Stack is Still Empty" << endl;
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
