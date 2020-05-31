#include<iostream>
using namespace std;
int count=0;
struct node
{
	int data;
	node *next;
};
node *first=new node;

void fn()
{
	cout<<"\nEnter first data:";
	cin>>first->data;
	first->next=NULL;
	count++;
}
void in()
{
	int t;
		node *n=new node;
		cout<<"\nEnter data:";
		cin>>n->data;
		n->next=NULL;
		cout<<"\n\n enter previous node data:";
		cin>>t;
			node *temp=first;
			while(temp!=NULL)
			{
				if(temp->data==t)
				{
					if(temp->next==NULL)
					{
						temp->next=n;
						n->next=NULL;
						count++;
					}
					else
					{
						n->next=temp->next;
						temp->next=n;
						count++;
					}
					break;
				}
				temp=temp->next;
			}
		

}
void dn()
{
	int t;
	cout<<"\nEnter node to be deleted:";
	cin>>t;
	if(first->data==t)
	{
		node *temp=first;
		first=first->next;
		temp->next=NULL;
		delete temp;
		
	}
	else
	{
		node *temp=first;
		while(temp!=NULL)
		{
			node *d=temp->next;
			if(d->data==t)
			{
				temp->next=d->next;
				d->next=NULL;
				delete d;
			}
			temp=temp->next;
	    }
	}count--;
}

void search()
{
	int t,i,flag=0;
	cout<<"\nEnter data to search:";
	cin>>t;
	node *temp=first;
	while(temp!=NULL)
	{
		if(temp->data==t)
		{
			cout<<"Found at "<<i;
			flag=1;
			break;
		}
		i++;
		temp=temp->next;
	}
	if(flag==0)
	cout<<"Not found";
}
void cn()
{
	cout<<"Count is "<<count;
}
void dis()
{
	if(first==NULL)
	cout<<"List empty";
	else
	{
		node *temp=first;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}
void des()
{
	node *temp=first;
	while(temp!=NULL)
	{
		node *d=temp->next;
		temp->next=NULL;
		delete temp;
		temp=d;
		d=temp->next;
	}
	cout<<"\n\nDestroyed";
}

int main()
{
	int opt;char c;fn();
	do
	{
		cout<<"\n1)Insert\n2)Delete\n3)Search\n4)Count\n5)Display\n6)Destroy";
		cin>>opt;
		switch(opt)
		{
			case 1:in();break;
			case 2:dn();break;
			case 3:search();break;
			case 4:cn();break;
			case 5:dis();break;
			case 6:des();break;
		}cout<<"Continue?";
		cin>>c;
	}while(c=='y');return 0;
}

