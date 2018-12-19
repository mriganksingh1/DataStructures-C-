#include<iostream>
using namespace std;
class Node                   //creating a class
{
	public:
		int data;
		Node* next;          
		Node(int data)
		{
			this->data=data;    //assigning the value to data declared in line 6
			next=NULL;
		}
};