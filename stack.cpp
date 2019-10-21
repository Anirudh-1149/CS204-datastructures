#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)

class Stack
{
	int *arr;
	int size;
	int top=-1;
	public:
		Stack(int size);
		void push(int num);
		void pop();
		void peek();
		void display();

	
};
Stack::Stack(int size)
{
	this->size=size;
	arr = new int[size];
}

void Stack::push(int num)
{
	if(top>=size-1)
		cout<<"Stack Overflow\n";
	else
	{
		top++;
		arr[top]=num;
	}
}

void Stack::peek()
{
	if(top>=0)
		cout<<arr[top]<<"\n";
	else
		cout<<"Stack is empty\n";
}
void Stack::pop()
{
	if(top>=0)
	{
		//cout<<"Element Poped is "<<arr[top]<<"\n";
		top--;
	}
	else
	{
		cout<<"Stack is Empty";
	}

}

void Stack::display()
{
	if(top>=0)
	{
		fi(i,0,top+1)
		{
			cout<<arr[top]<<" ";
		}
		cout<<"\n";
	}
	else
		cout<<"Stack is Empty";
}




int main()
{	
	Stack s(5);
	s.push(1);
	s.push(2);
	s.peek();
}