#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
};
void print(Node *head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
Node* takeinputmethod2()
{
	int element;
	cin>>element;
	Node* head=NULL;
	Node* tail=NULL;
	while(element!=-1)
	{
		Node* newnode=new Node(element);
		if(head==NULL)
		{
			head=newnode;
			tail=head;
		}
		else
		{
			tail->next=newnode;
			tail=tail->next;
		}
		cin>>element;
	}
	return head;
}
Node* takeinputmethod1()
{
	int element;
	cin>>element;
	Node *head=NULL;
	Node *temp=NULL;
	while(element!=-1)
	{
		Node *newnode =new Node(element);
		if(head==NULL)
		{
			head=newnode;
			temp=head;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
		cin>>element;
	}
	return head;
}
int main()
{
	Node* head=takeinputmethod1();
	print(head);
	Node* head1=takeinputmethod2();
	print(head1);
}