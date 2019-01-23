#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class trees{
public:
	T data;
	vector<trees*> children;
	trees(T data)
	{
		this->data=data;
	}
};