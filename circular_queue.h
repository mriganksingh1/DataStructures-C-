#include<iostream>
using namespace std;
template<typename T>
class circular_queue
{
	int frontindex;
	int nextindex;
	int size;
	int capacity;
	T* arr;
public:
	circular_queue()
	{
		size=0;
		frontindex=-1;
		nextindex=0;
		capacity=5;
		arr=new T[capacity];
	}
	void push(T element)
	{
		if(frontindex==-1)
		{
			frontindex++;
		}
		if(size==capacity)
		{
			cout<<"Queue is full "<<endl;
			return;
		}
		nextindex=nextindex%capacity;
		arr[nextindex]=element;
		size++;
		nextindex++;
	}
	void pop()
	{
		if(size==0)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		frontindex++;
		size--;
	}
	T fornt()
	{
		if(size==0)
		{
			cout<<"Queue is empty"<<endl;
			return -1;	
		}
		return arr[frontindex];
	}
	bool isEmpty()
	{
		return (size==0)?true:false;
	}
};