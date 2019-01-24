#include<iostream>
#include<queue>
#include"binarytree.h"
using namespace std;
void preorder(binarytree<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(binarytree<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void inorder(binarytree<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int height(binarytree<int>* root)
{
	if(root==NULL)
	{
		return 0;
	}
	return 1+max(height(root->left),height(root->right));
}
void printlevelwise(binarytree<int>* root)
{
	queue<binarytree<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		binarytree<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		if(front->left!=NULL)
		{
			cout<<front->left->data<<",";
			pendingnodes.push(front->left);
		}
		if(front->right!=NULL)
		{
			cout<<front->right->data;
			pendingnodes.push(front->right);
		}
		cout<<endl;
	}
}
void print(binarytree<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<":";
	if(root->left!=NULL)
	{
		cout<<root->left->data<<",";
	}
	if(root->right!=NULL)
	{
		cout<<root->right->data;
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
binarytree<int>* takeinputlevelwise()
{
	queue<binarytree<int>*> pendingnodes;
	int rootdata;
	cout<<"Enter the root data"<<endl;
	cin>>rootdata;
	binarytree<int>* root=new binarytree<int>(rootdata);
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		binarytree<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int leftchilddata;
		cout<<"Enter the left child of "<<front->data<<endl;
		cin>>leftchilddata;
		binarytree<int>* leftn=NULL;
		if(leftchilddata!=-1)
		{
			leftn=new binarytree<int>(leftchilddata);
			pendingnodes.push(leftn);
		}
		int rightchilddata;
		cout<<"Enter the right child of "<<front->data<<endl;
		cin>>rightchilddata;
		binarytree<int>* rightn=NULL;
		if(rightchilddata!=-1)
		{
			rightn=new binarytree<int>(rightchilddata);
			pendingnodes.push(rightn);
		}
		front->left=leftn;
		front->right=rightn;
	}
	return root;
}
binarytree<int>* input()
{
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	binarytree<int>* root=new binarytree<int>(rootdata);
	binarytree<int>* leftn=input();
	binarytree<int>* rightn=input();
	root->left=leftn;
	root->right=rightn;
	return root;
}
int main()
{
	//binarytree<int>* root=input();
	//print(root);
	binarytree<int>* root=takeinputlevelwise();
	printlevelwise(root);
	int h=height(root);
	cout<<"The height of the binary tree is "<<h<<endl;
	preorder(root);
	postorder(root);
	inorder(root);
}