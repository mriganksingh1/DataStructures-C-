#include<iostream>
using namespace std;
template<typename T>
class queue_using_array{
int size;
int capacity;
T *arr;
public:
	queue_using_array()
	{
		size=0;
		capacity=5;
		arr=new T[capacity];
	}
	void push(T element)
	{
		if(size==capacity)
		{
			T *newarr=new T[2*capacity];
			for(int i=0;i<capacity;i++)
			{
				newarr[i]=arr[i];
			}
			capacity=2*capacity;
			arr=new T[capacity];
			arr=newarr;
		}
		arr[size]=element;
		size++;
	}
	void pop()
	{
		if(size==0)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		for(int i=0;i<size-1;i++)
		{
			arr[i]=arr[i+1];
		}
		size--;
	}
	T front()
	{
		if(size==0)
		{
			cout<<"The Queue is empty"<<endl;
			return -1;
		}
		return arr[0];
	}
	bool isEmpty()
	{
		return (size==0)?true:false;
	}
};