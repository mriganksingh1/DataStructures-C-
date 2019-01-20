#include<iostream>
#include"stack_using_linkedlist.h"
using namespace std;
int main()
{
	stack_using_linkedlist<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.isEmpty()<<endl;
}