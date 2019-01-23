#include<iostream> 
using namespace std;
template<typename T>
class Node
{
public:
	T data;
	Node* next;
	Node(T data)
	{
		this->data=data;
		next=NULL;
	}
};
template<typename V>
class stack_using_linkedlist
{
	int size;
	Node<V>* head;
public:
	stack_using_linkedlist()
	{
		size=0;
		head=NULL;
	}
	void push(V element)
	{
		Node<V>* newnode=new Node<V>(element);
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			newnode->next=head;
			head=newnode;
		}
		size++;
	}
	void pop()
	{
		if(size==0)
		{
			cout<<"The stack is empty"<<endl;
			return;
		}
		head=head->next;
		size--;
	}
	V top()
	{
		if(size==0)
		{
			cout<<"The stack is empty"<<endl;
			return -1;
		}
		return head->data;
	}
	bool isEmpty()
	{
		return (size==0)?true:false;
	}
};
