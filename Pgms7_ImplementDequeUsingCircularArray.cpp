#include <iostream>
using namespace std;

// Coded by @Pranav on Jan 30, 2022
//Problem : Implement a DeQueue using Arrays
// Solution : Use Circular arrays and Implement dequeue 
//           Implement methods like insert_front()
//           insert_rear(), pop_front(), pop_rear()
//           get_front(), get_rear()

#define MAX 5

class MyDequeue
{
    int *arr;
    int front,rear,capacity;

    
    public:
    
    MyDequeue()
    {
        front=-1;
        rear=-1;
        capacity=MAX;
        arr=new int[capacity];
    }
    
    void push_rear(int data)
    {
        if(!IsFull())
        {
            if(front==-1)
                front=0;
        
            rear=(rear+1)%capacity;
            arr[rear]=data;
        }
        else
        {
            cout << "Dequeue is Full, push_back Failed" << endl;
        }
    }
    
    void push_front(int data)
    {
         if(!IsFull())
        {
            if(front==-1||front==0)
            {
                front=capacity-1;
                arr[front]=data;
            }
            else if(front-1!=rear)
            {
                front=front-1;
                arr[front]=data;
            }
        }
        else
        {
            cout << "Dequeue is Full, push_back Failed" << endl;
        }
    }
    
    void pop_rear()
    {
        if(!IsEmpty())
        {
            arr[rear]=-1;
            
            if(front==rear)
            {
                front=-1;
                rear=-1;
            }
            else if(rear==0)
            {
                rear=capacity-1;
            }
            else
            {
                rear=rear-1;
            }
        }
        else
        {
            cout << "Dequeue is Empty, pop_rear Failed" << endl;
        }
    }
    
    void pop_front()
    {
        if(!IsEmpty())
        {
            arr[front]=-1;
            
            if(front==rear)
            {
                front=-1;
                rear=-1;
            }
            else if(front==capacity-1)
            {
                front=0;
            }
            else
            {
                front=front+1;
            }
        }
        else
        {
            cout << "Dequeue is Empty, pop_rear Failed" << endl;
        }
    }
    
    int getFront()
    {
        int val;
        if(!IsEmpty())
        {
            val=arr[front];
            return val;
        }
        else
        {
            cout << "Dequeue is Empty, No Front Item" << endl;
        }
        return -1;
    }
    int getRear()
    {
        int val;
        if(!IsEmpty())
        {
            val=arr[rear];
            return val;
        }
        else
        {
            cout << "Dequeue is Empty, No Rear Item" << endl;
        }
        return -1;
    }
    bool IsFull()
    {
        if(front==(rear+1)%capacity)
            return true;
        else
            return false;
    }
    
    bool IsEmpty()
    {
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    void print()
    {
        cout << "Dequeue >>>>" << endl;
        //cout << "front=" << front << "rear=" << rear << "capacity=" << capacity << endl; 
        if(front>rear)
        {
            for(int i=front; i<capacity;i++)
                cout << arr[i] << " ";
        }
        for(int i=0; i<rear+1;i++)
                cout << arr[i] << " ";
        
        cout << "<<<<<<<" <<endl;
    }
};
int main() {
	
	MyDequeue dq;

    // dq.pop_front();
    // dq.pop_rear();
    
    dq.push_rear(1);
    dq.push_rear(2);
    dq.push_rear(3);
    
    cout << " 1 2 3 front=" << dq.getFront() << endl;
    cout << " 1 2 3 rear=" << dq.getRear() << endl;
     
    
    dq.pop_rear();
    cout << " 1 2 front=" << dq.getFront() << endl;
    cout << " 1 2 rear=" << dq.getRear() << endl;
    
    dq.print();
    dq.push_front(10);
    dq.push_front(20);
    
    dq.print();
    cout << "20 10 1 2 front=" << dq.getFront() << endl;
    cout << " 20 10 1 2 rear=" << dq.getRear() << endl;
    
    dq.push_rear(100);
    dq.push_rear(200);
    dq.push_rear(300);
    cout << "100 20 10 1 2 front=" << dq.getFront() << endl;
    
    
    dq.pop_front();
    dq.pop_front();
    cout << "1 2 100 front=" << dq.getFront() << endl;
    
    dq.pop_rear();
    dq.print();
    dq.pop_rear();
    
    dq.print();
    
    
	return 0;
}

