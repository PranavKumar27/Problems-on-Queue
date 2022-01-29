#include <iostream>
using namespace std;

// Question: Implement Queue using Dynamic array
// Size of array is not fixed with Max size , It keeps on growing
// Queue as expected is FIFO with standard Enqueue, DeQueue operations 
// Solutions: We need to use a circular queue array here 
// Once it reaches it max capacity, we need to reallocate new block of 
// memory twice of the original capacity

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
        if(IsFull())
            ResizeQ();
        
        if(front==-1)
            {
                front=0;
            }
            rear=(rear+1)%capacity;
            arr[rear]=data;
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
    
    void ResizeQ()
    {
        // Create a new array of twice the old capacity
        int i;
        int * arr_ptr=new int[2*capacity];
        
        // Initalize with -1
        for(i=0;i<2*capacity;i++)
            arr_ptr[i]=-1;
        // copy old queue element into new array
        
        int j=0;
        if(front<rear)
            {
                for(i=front;i<=rear;i++)
                    arr_ptr[j++]=arr[i];
            }
            else
            {
                for(i=front;i<capacity;i++)
                    arr_ptr[j++]=arr[i];
               
               cout << "case 2  j=" << j << endl;
                if(front!=rear)  // More than 1 element in queue
                {
                    for(i=0;i<=rear;i++)
                       arr_ptr[j++]=arr[i];
                }
                // If only one element in Q, run upto front will cover all elments 
                //No need to run upto rear again since front and rear are same
                else
                {
                    for(i=0;i<rear;i++)
                        arr_ptr[j++]=arr[i];
                }
            }
            delete [] arr;
            
            arr=arr_ptr;
            
            front=0;
            rear=j-1;
            capacity=2*capacity;
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
     q1.print();
    cout << "q= 3 4 5 6 7.8 Top=" << q1.top() << endl; 
        q1.Enqueue(9);
     q1.print();
    cout << "q= 3 4 5 6 7.8 9 Top=" << q1.top() << endl; 
        q1.Enqueue(10);
     q1.print();
    cout << "q= 3 4 5 6 7.8 9 10 Top=" << q1.top() << endl; 
    q1.Dequeue();
    cout << "q= 4 5 6 7.8 9 10 Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q= 5 6 7.8 9 10 Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q= 6 7.8 9 10.Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q=7.8 9 10..Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q=8 9 10..Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q=9 10..Top=" << q1.top() << endl;
    q1.Dequeue();
    q1.print();
    cout << "q=10..Top=" << q1.top() << endl;
    //q1.Dequeue();
    //q1.Dequeue();
	// your code goes here
	return 0;
}
