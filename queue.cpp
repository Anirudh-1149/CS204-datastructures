#include <bits/stdc++.h> 
using namespace std;

class Queue  
{   
    int front, rear, size;  
    unsigned capacity;  
    int* array; 
    public:
        Queue(int capacity);
        int Full();
        int Empty();
        void Enqueue(int item);
        void Dequeue();
        void Front();
        void Rear();
};  
  

Queue::Queue(int capacity)  
{   
    this->capacity = capacity;  
    front = size = 0;  
    rear = capacity - 1;  
    array = new int[capacity];  
}  
  

int Queue::Full()  
{ return (size == capacity); }  
  

int Queue::Empty()  
{ return (size == 0); }  
  

void Queue::Enqueue(int item)  
{  
    if (Full())  
        cout<<"Queue is Full";
    else{
        rear = (rear + 1) % capacity;  
        array[rear] = item;  
        size = size + 1;  
        cout << item << " enqueued to queue\n";  
    }
}  

void Queue::Dequeue()  
{  
    if (Empty())  
        cout<<"Queue is Empty\n";
    else{  
        int item = array[front];  
        front = (front + 1) % capacity;  
        size = size - 1;  
        cout<<item<<" is Dequeued\n"; 
    } 
}  
  
void Queue::Front()  
{  
    if (Empty())  
        cout<<"Queue is Empty";
        else{
            cout<<array[front]<<"\n";
        }    
}  
  
void Queue::Rear()  
{  
    if (Empty())  
        cout<<"Queue is Empty";  
    else
    {
        cout<<array[rear]<<"\n";
    } 
}  

int main()
{
    Queue q(6);
    q.Enqueue(1);
    q.Front();  
    q.Rear();  
}