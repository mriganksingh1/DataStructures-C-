#include<iostream>
#include"BST.h"
using namespace std;
int main()
{
	BST b;
	b.insert(10);
	b.insert(20);
	b.insert(30);
	b.insert(40);
	b.insert(50);
	b.insert(60);
	b.insert(70);
	b.insert(80);
	b.insert(90);
	b.insert(9);
	b.insert(7);
	b.insert(5);
	b.printTree();
	cout<<b.hasData(80)<<endl;
	b.deleteData(90);
	b.deleteData(10);
	b.printTree();
	cout<<b.hasData(90);
}