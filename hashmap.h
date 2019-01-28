#include<string>
using namespace std;
template<typename T>
class Mapnode
{
public:
 string key;
 T value;
 Mapnode* next;
 Mapnode(string key,T value)
 {
 	this->key=key;
 	this->value=value;
 	next=NULL;
 }
 ~Mapnode()
 {
 	delete next;
 }
};
template<typename T>
class ourmap
{
	Mapnode<T>** buckets;
	int count;
	int numBuckets;
public:
	ourmap()
	{
		count=0;
		numBuckets=5;
		buckets=new Mapnode<T>*(numBuckets);
		for(int i=0;i<numBuckets;i++)
		{
			buckets[i]=NULL;
		}
	}
	~ourmap()
	{
		for(int i=0;i<numBuckets;i++)
		{
			delete buckets[i];
		}
		delete []buckets;
	}
	int size()
	{
		return count;
	}
private:
	int getBucketIndex(string key)
	{
		int hashcode=0;
		int currCoeff=1;
		for(int i=key.length()-1;i>=0;i--)
		{
			hashcode+=key[i]*currCoeff;
			hashcode=hashcode%numBuckets;
			currCoeff=currCoeff*37;
			currCoeff=currCoeff%numBuckets;
		}
		return hashcode%numBuckets;
	} 
public:
	void insert(string key,T value)
	{
		int numbcketIndex=getBucketIndex(key);
		Mapnode<T>* head=buckets[numbcketIndex];
		while(head!=NULL)
		{
			if(head->key==key)
			{
				head->value=value;
				return;
			}
			head=head->next;
		}
		head=buckets[numbcketIndex];
		Mapnode<T>* newnode=new Mapnode<T>(key,value);
		newnode->next=head;
		head=newnode;
		count++;
		double loadFactor=(1.0*count)/numBuckets;
		if(loadFactor>0.7)
		{
			rehash();
		}
	}
private:
	void rehash()
	{
		Mapnode<T>** temp=buckets;
		buckets=new Mapnode<T>*[2*numBuckets];
		for(int i=0;i<2*numBuckets;i++)
		{
			buckets[i]=NULL;
		}
		int oldBucketsCount=numBuckets;
		numBuckets=numBuckets*2;
		count=0;
		for(int i=0;i<oldBucketsCount;i++)
		{
			Mapnode<T>* head=temp[i];
			while(head!=NULL)
			{
				string key=head->key;
				T value=head->value;
				insert(key,value);
				head=head->next;
			}
		}
		for(int i=0;i<oldBucketsCount;i++)
		{
		 	Mapnode<T>* head=temp[i];
		 	delete head;
		}
		delete [] temp;
	}
public:
	T getValue(string key)
	{
		int numbcketIndex=getBucketIndex(key);
		Mapnode<T>* head=buckets[numbcketIndex];
		while(head!=NULL)
		{
			if(head->key==key)
			{
				return head->value;
			}
			head=head->next;
		}
		return -1;
	}
	T remove(string key)
	{
		int numbcketIndex=getBucketIndex(key);
		Mapnode<T>* head=buckets[numbcketIndex];
		if(head->key==key)
		{
			int ans=head->value;
			buckets[numbcketIndex]=head->next;
			count--;
			head->next=NULL;
			delete head;
			return ans;
		}
		Mapnode<T>* temp=head;
		head=head->next;
		while(head!=NULL)
		{
			if(head->key==key)
			{
				int ans=head->value;
				temp=temp->next->next;
				head->next=NULL;
				delete head;
				return ans;
			}
			head=head->next;
			temp=temp->next;
		}
		return -1;
	}
};