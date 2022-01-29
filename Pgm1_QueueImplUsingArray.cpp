#include <iostream>
using namespace std;

// Question: Implement Queue using array
// Size of array is fixed with Max size 
// Queue as expected is FIFO with standard Enqueue, DeQueue operations 
// Solutions: We need to use a circular queue array here since in linear array
// memory is wasted and unused 

#define MAX 5

class QueueImpl
{
    int * arr;
    int rear,front;
    int capacity;
    public:
    QueueImpl()
    {
        capacity=MAX;
        front=rear=-1;
        arr=new int[capacity];
    }
    void Enqueue(int data)
    {
        if(!IsFull())
        {
            if(front==-1)
            {
                front=0;
            }
            rear=(rear+1)%capacity;
            arr[rear]=data;
        }
        else
        {
            cout << "Q is Full, Enqueue Operation Not Allowed" << endl;
        }
    }
    bool IsFull()
    {
       if((rear+1)%capacity==front)
            return true;
        else 
            return false;
    }
    void Dequeue()
    {
        int val;
        if(!IsEmpty())
        {
            val=arr[front];
            
            arr[front]=-1;
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front=(front+1)%capacity;
            }
        }
        else
        {
            cout << "Q is Empty, Dequeue Operation Not Allowed" << endl;
        }
    }
    int top()
    {
        if(front!=-1)
        {
            return arr[front];
        }
        else
        {
            return -1;
        }
    }
    bool IsEmpty()
    {
        if(front==-1)
            return true;
        else 
            return false;
    }
    void print()
    {
        int i;
        if(!IsEmpty())
        {
            if(front<rear)
            {
                cout << "{";
                for(i=front;i<=rear;i++)
                {
                    cout << arr[i] << ", ";
                }
                cout << "}" << endl;
            }
            else
            {
                cout << "{";
                for(i=front;i<capacity;i++)
                {
                    cout << arr[i] << ", ";
                }
                
                if(front!=rear)  // More than 1 element in queue
                {
                    for(i=0;i<=rear;i++)
                    {
                        cout << arr[i] << ", ";
                    }
                }
                // If only one element in Q, run upto front will cover all elments 
                //No need to run upto rear again since front and rear are same
                else
                {
                    for(i=0;i<rear;i++)
                    {
                        cout << arr[i] << ", ";
                    }
                }
                
                
                
                cout << "}" << endl;
                
                
            }
        }
    }
};
int main() {
    
    QueueImpl q1;
    
    // q1.Dequeue();
    q1.Enqueue(1);
    q1.Enqueue(2);
    cout << "q= 1 2 .Top=" << q1.top() << endl;
    q1.Enqueue(3);
    q1.Enqueue(4);
    cout << "q= 1 2 3 4.Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q= 2 3 4 .Top=" << q1.top() << endl;
    q1.Enqueue(5);
    q1.Dequeue();
    cout << "q= 3 4 5.Top=" << q1.top() << endl;
    q1.Enqueue(6);
    q1.Enqueue(7);
    q1.print();
    cout << "q= 3 4 5 6 7.Top=" << q1.top() << endl;
    q1.Enqueue(8);
    q1.Dequeue();
    cout << "q= 4 5 6 7.Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q= 5 6 7.Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q= 6 7.Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q=7.Top=" << q1.top() << endl;
    
	return 0;
}
