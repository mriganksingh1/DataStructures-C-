#include<iostream>
using namespace std;
template<typename V>
class Node{
public:
	V data;
	Node *next;
	Node(V data)
	{
		this->data=data;
		this->next=NULL;
	}
};
template<typename T>
class queue_using_ll{
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	queue_using_ll()
	{
		head=NULL;
		tail=NULL;
		size=0;
	}
	void push(T element)
	{
		Node<T> *newnode=new Node<T>(element);
		if(size==0)
		{
			head=newnode;
			tail=head;
		}
		else
		{
			tail->next=newnode;
			tail=tail->next;
		}
		size++;
	}
	void pop()
	{
		if(size==0)
		{
			cout<<"Queue is Empty"<<endl;
			return;
		}
		head=head->next;
		size--;
	}
	T front()
	{
		if(size==0)
		{
			cout<<"Queue is Empty"<<endl;
			return -1;
		}
		return head->data;
	}
	bool isEmpty()
	{
		return (size==0)?true:false;
	}
};