
#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
int count=0;
node *f=NULL,*r=NULL;
void enq(int x)
{
	node *newnode=new node;
	newnode->data=x;
	newnode->next=NULL;
	if(f==NULL)
	{
	
	f=r=newnode;
	r->next=NULL;
    }
    else
    {
    	r->next=newnode;
    	r=newnode;
    	r->next=NULL;
	}
    count++;
}
void deq()
{
	if(f==NULL)
	cout<<"Queue empty";
	else
	{
		node *p=f;
		int a=p->data;
		f=f->next;
		delete p;
		count--;
	}
}
void dis()
{
	node *t=f;
	while(t!=NULL)
	{
		cout<<f->data<<" ";
		f=f->next;
	}
}
void qf()
{
	cout<<f->data;
}
void cq()
{
	cout<<count;
}
void sq(int x)
{
	node *t=f;int i=1;
	while(t!=NULL)
	{
		if(t->data==x)
		{
			cout<<"Found "<<x<<"at "<<i;goto x;
		}i++;
		t=t->next;
		
	}
	
	cout<<"NOt found";
	x:{}
	
	
}
int main()
{
	
	
	int a,b;
	for(int i=0;i<5;i++)
	{
		cin>>a;enq(a);
	}
	dis();
	cout<<"Enter element to search";
	cin>>b;
	sq(b);
	cout<<"Queue front:";qf();
	cout<<"\nCount:";cq();
}

