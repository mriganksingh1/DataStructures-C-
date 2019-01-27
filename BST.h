#include<iostream>
using namespace std;
template<typename T>
class BinaryTree{
public:
T data;
BinaryTree<T>* right;
BinaryTree<T>* left;
	BinaryTree(T data)
	{
		this->data=data;
		this->right=NULL;
		this->left=NULL;
	}
};
class BST{
BinaryTree<int>* root;
public:
	BST()
	{
		root=NULL;
	}
private:
	bool hasData(BinaryTree<int>* root,int data)
	{
		if(root==NULL)
		{
			return false;
		}
		if(root->data==data)
		{
			return true;
		}
		else if(data > root->data)
		{
			return hasData(root->right,data);
		}
		else if(data < root->data)
		{
			return hasData(root->left,data);
		}
	}
	void printTree(BinaryTree<int>* root)
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
		printTree(root->left);
		printTree(root->right);
	}
	BinaryTree<int>* insert(BinaryTree<int>* root,int data)
	{
		if(root==NULL)
		{
			BinaryTree<int>* node=new BinaryTree<int>(data);
			return node;
		}
		if(data > root->data)
		{
			root->right=insert(root->right,data);
		}
		else if(data < root->data)
		{
			root->left=insert(root->left,data);
		}
		return root;
	}
	BinaryTree<int>* deleteData(BinaryTree<int>* root,int data)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(data>root->data)
		{
			root->right=deleteData(root->right,data);
			return root;
		}
		else if(data<root->data)
		{
			root->left=deleteData(root->left,data);
			return root;
		}
		else if(root->data==data)
		{
			if(root->left==NULL&&root->right==NULL)
			{
				delete root;
				return NULL;
			}
			else if(root->left==NULL&&root->right!=NULL)
			{
				BinaryTree<int>* rightnode=root->right;
				root->right=NULL;
				delete root;
				return rightnode;
			}
			else if(root->right==NULL&& root->left!=NULL)
			{
				BinaryTree<int>* leftnode=root->left;
				root->left==NULL;
				delete root;
				return leftnode;
			}
			else if(root->right!=NULL && root->left!=NULL)
			{
				BinaryTree<int>* minnode=root->right;
				while(minnode->left!=NULL)
				{
					minnode=minnode->left;
				}
				int rightmin=minnode->data;
				root->data=rightmin;
				root->right=deleteData(root->right,rightmin);
				return root;
			}
		}
	}
public:
	bool hasData(int data)
	{
		return hasData(root,data);
	}
	void printTree()
	{
		printTree(root);
	}
	void insert(int data)
	{
		this->root=insert(root,data);
	}
	void deleteData(int data)
	{
		this->root=deleteData(root,data);
	}
};