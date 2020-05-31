#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node *next;
};
node *f=new node;
void fn()
{
	
	cout<<"Enter data";
	cin>>f->data;
	f->next=NULL;
}
void in()
{

	int t;
	node *n=new node;
	cout<<"Enter data";
	cin>>n->data;
	n->next=NULL;
	cout<<"enter previous data";
	cin>>t;
    node *temp=f;
    while(temp!=NULL)
    {
    	if(temp->data==t)
    	{
    		if(temp->next==NULL)
    		{
    			temp->next=n;
    			n->next=NULL;
			}
			else
			{
				n->next=temp->next;
				temp->next=n;
			}
			break;
		}
		temp=temp->next;
	}
}
void dis()
{
	node *t=f;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}
void search(int a,int b)
{
	node *t=f;
	while(t!=NULL)
	{
		if(t->data==a)
		{
			node *x=t;
			node *tt=f;
			while(tt!=NULL)
			{
				if(tt->data==b)
				{
					node *y=tt;
					 int temp=x->data;
					 x->data=y->data;
					 y->data=temp;dis();goto x;
				}tt=tt->next;
            }
		}
		
	    t=t->next;
    }
		x:{}				
}
int main()
{
	int a,b;	fn();
	for(int i=0;i<2;i++)
	in();
	dis();
	cout<<"\nSearch ele 1:";
	cin>>a;
	cout<<"\nSearch ele 2:";
	cin>>b;
	search(a,b);
	
}
