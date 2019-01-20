#include<iostream>
#include"stack_using_array.h"
using namespace std;
int main()
{
	stack_using_array<char> s;
	cout<<s.isEmpty()<<endl;;
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');
	s.push('f');
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;;
	cout<<s.isEmpty()<<endl;
}