#include<iostream>
#include"queue_using_ll.h"
using namespace std;
int main()
{
	queue_using_ll<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	cout<<q.front()<<endl;
	q.pop();
	q.pop();
	cout<<q.front()<<endl;
}