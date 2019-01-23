#include<iostream>
#include<queue>
#include"trees.h"
using namespace std;
void depth(trees<int>* root,int k)
{
	if(k==0)
	{
		cout<<root->data<<endl;
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		depth(root->children[i],k-1);
	}
}
int height(trees<int>* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int maxheight=0;
	for(int i=0;i<root->children.size();i++)
	{
		int childheight=height(root->children[i]);
		if(childheight>maxheight)
		{
			maxheight=childheight;
		}
	}
	return 1+maxheight;
}
void printtreelevelwise(trees<int>* root)
{
	queue<trees<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		trees<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++)
		{
			cout<<front->children[i]->data<<",";
			pendingnodes.push(front->children[i]);
		}
		cout<<endl;
	}
}
void printtree(trees<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		printtree(root->children[i]);
	}
}
trees<int>* takeinputlevelwise()
{
	queue<trees<int>*> pendingnodes;
	int rootdata;
	cout<<"Enter the value of root"<<endl;
	cin>>rootdata;
	trees<int>* root=new trees<int>(rootdata);
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		trees<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int numchild;
		cout<<"Enter the number of children of "<<front->data;
		cout<<endl;
		cin>>numchild;
		for(int i=0;i<numchild;i++)
		{
			int children;
			cout<<"Enter the value of child"<<endl;
			cin>>children;
			trees<int>* child=new trees<int>(children);
			pendingnodes.push(child);
			front->children.push_back(child);
		}
	}
	return root;
}
trees<int>* takeinput()
{
	int rootdata;
	cin>>rootdata;
	trees<int>* root=new trees<int>(rootdata);
	int n;
	cout<<"Enter the number of children"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		trees<int>* child=takeinput();
		root->children.push_back(child);
	}
	return root;
}
int main()
{
	//trees<int>* root=takeinput();
	//printtree(root);
	trees<int>* root=takeinputlevelwise();
	printtreelevelwise(root);
	int h=height(root);
	cout<<"The height of the tree is "<<h<<endl;
	int k;
	cout<<"Enter the depth"<<endl;
	cin>>k;
	depth(root,k);
}