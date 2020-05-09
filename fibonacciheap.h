#ifndef fibonacciheap_h
#define fibonacciheap_h

#include<iostream>

using namespace std;

template<class T>
class Node
{
	public:
	T data;
	Node<T> *left,*right;
	Node<T>* parent,*child;
	int order;
	
		Node()
		{
			left = right = parent = child = NULL;
			order=-1;
		}
		Node(T x)
		{
			left = right = parent = child = NULL;
			order = 0;
			data = x;
		}
		
};

template<class T>
class fib_heap
{
	Node<T>* min;
	public:
	fib_heap()
	{
		min=NULL;
	}
	int insert(T x)
	{
		Node<T>* temp=new Node<T>(x);
		if(min==NULL)
		{
			min=temp;
			min->left=min;
			min->right=min;
		}
		else
		{
			temp->left=min->left;
			temp->right=min;
			min->left=temp;	
			(temp->left)->right=temp;
			if(x<min->data)min=temp;
		}
		return 0;
	}	
	
	int insert(Node<T>* temp)
	{
		
		if(min==NULL)
		{
			min=temp;
			min->left=min;
			min->right=min;
		}
		else
		{
			temp->left=min->left;
			temp->right=min;
			min->left=temp;	
			(temp->left)->right=temp;
			if(temp->data<min->data)min=temp;
		}
		return 0;
	}	
	int display()
	{
		Node<T>* temp=min;
		if(min==NULL)return -1;
		cout<<" "<<min->data<<endl;
		temp=min->left;
		while(temp!=min&& temp!=NULL)
		{
			cout<<" "<<temp->data<<endl;
			temp=temp->left;
		}
		return 0;
	}
	Node<T>* link(Node<T>* x)
	{
		Node<T>* c=x->child;
		if(c==NULL)
		{
			cout<<" NULL Child \n\n"<<endl;
			return NULL;
		}
		else
		{	
			Node<T>* p=c->right;
			insert(c);
			while(p!=c&& p!=NULL)
			{
				insert(p);
				p=p->right;
			}
		}
		
	}
	int update_min()
	{
		Node<T>* p=min;
		Node<T>* q=p;
		p=min->right;
		while(p!=NULL && p!=q )
		{
			if(p->data<min->data)
			{
				min=p;
			}
			p=p->right;
		}
	}
	int del(Node<T>* temp)
	{
		Node<T>* x=temp;
		(temp->left)->right=x->right;
		(temp->right)->left=x->left;
		delete temp;
	}
	T extract_min()
	{
		T temp=min->data;
		Node<T>* t=min;
		cout<<" "<<temp<<"\n\n";
		if(min->child==NULL)cout<<" No Child \n\n";
		link(min);
		min->data = 99;
		update_min();
		del(t);
		return temp; 
	}
};

#endif