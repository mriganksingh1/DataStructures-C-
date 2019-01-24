#include<iostream>
using namespace std;
template<typename T>
class binarytree{
public:
	T data;
	binarytree<T>* right;
	binarytree<T>* left;
	binarytree(T data)
	{
		this->data=data;
		this->right=NULL;
		this->left=NULL;
	}	
	~binarytree()
	{
		delete right;
		delete left;
	}
};