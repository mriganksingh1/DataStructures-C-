#include<iostream>
using namespace std;
template<typename T>
class stack_using_array
{
private:
	int size;
	T *arr;
	int capacity;
public:
	stack_using_array()
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
			cout<<"The stack is empty"<<endl;
			return;
		}
		size--;
	}
	T top()
	{
		if(size==0)
		{
			cout<<"The stack is empty"<<endl;
			return -1;
		}
		return arr[size-1];
	}
	bool isEmpty()
	{
		return (size==0)?true:false;
	}
};