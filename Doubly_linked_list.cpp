#include<iostream>
using namespace std;
struct node
{
    int data;
    node* fore;
    node* back;
};
struct list
{
    int count;
    node* head;
    node* rear;
};
class dll
{
    list *h;
    public:
    dll()
    {
        h=new list;
        h->count=0;
        h->head= NULL;
        h->rear=NULL;
    }
    void createList()
    {
        h=new list;
        h->count=0;
        h->head= NULL;
        h->rear=NULL;
    }
    bool fullList()
    {
        node* temp=new node;
        if(temp!=NULL)
        {
            delete temp;
            return false;
        }
        else
            return true;
    }
    bool emptyList()
    {
        if(h->count==0)
            return true;
        else
            return false;
    }
    int dllCount()
    {
        return h->count;
    }
    void displayHead()
    {
        if(emptyList())
            cout<<"list is empty";
        node* temp=h->head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->fore;
        }
        cout<<"NULL";
    }
    void displayRear()
    {
        if(emptyList())
            cout<<"list is empty";
        node* temp=h->rear;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->back;
        }
        cout<<"NULL";
    }
    bool searchList(node* &ppre,node* &ploc,int target)
    {    bool found;
        ppre=NULL;
        ploc=h->head;
        while(ploc!=NULL && target>ploc->data)
        {
            ppre=ploc;
            ploc=ploc->fore;
        }
        if(ploc==NULL)
            found=false;
        else
        {
            if(target==ploc->data)
                found=true;
            else
                found=false;
        }
        return found;
    }
    int insert(node* ppre,node*ploc,int datain)
    {
        if(fullList())
            return 0;
        bool found;
        found=searchList(ppre,ploc,datain);
        if(!found)
        {   
            node* newnode=new node;
            newnode->data=datain;
            ++(h->count);
            if(ppre==NULL)
            {
                newnode->back=NULL;
                newnode->fore=h->head;
                h->head=newnode;   
            }
            else
            {
                newnode->fore=ploc;
                newnode->back=ppre;
                ppre->fore=newnode;
            }
            if(ploc==NULL)
                h->rear=newnode;
            else
                ploc->back=newnode;
            return 1;
        }
        return 2;
    }
           



};
int main()
{
    dll d;int n,data;
    node* ppre=NULL,*ploc=NULL;
    do
    {
        cout<<"\n1.Create list\n2.Full list\n3.empty list\n4.List count\n5.Display from Head\n6.Display from Rear\n7.Insert";
        cout<<"\n13.exit\nEnter choice";
        cin>>n;
        switch(n)
        {
            case 1:d.createList();break;
            case 2:if(d.fullList())
                    cout<<"List is full";
                else
                    cout<<"List is not full";
                break;
            case 3:if(d.emptyList())
                    cout<<"List is empty";
                else
                    cout<<"List is not empty";
            case 4:cout<<"No.of nodes is"<<d.dllCount();break;
            case 5:d.displayHead();break;
            case 6:d.displayRear();break;
            case 7:cout<<"Enter data to be inserted";cin>>data;
                if(d.insert(ppre,ploc,data))
                    cout<<"Data entry successful";
                else
                    cout<<"Data entry unsuccessful";
                break;
            case 13:break;
        }
    }while(n!=13);
}
