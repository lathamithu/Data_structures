#include<iostream>
using namespace std;

struct node
{

int data;
node* left;
node* right;

};

class BST
{

public:
node* largestBST(node* head)
{
if(head==NULL)
{
return head;
}
if(head->right==NULL)
{
return head;
}
else
{
head=largestBST(head->right);

return head;

}

}

node* smallestBST(node* head)
{
if(head==NULL)
{
return head;
}
else if(head->left==NULL)
{
return head;
}
else
{
head=smallestBST(head->left);

return head;

}

}


node* addBST(node* head,int datain)
{
if(head==NULL)
{
node* newnode=new node;
head=newnode;
newnode->data=datain;
newnode->left=NULL;
newnode->right=NULL;

}

else
{

if(datain<head->data)
{
head->left=addBST(head->left,datain);
}
else
{
head->right=addBST(head->right,datain);
}


}
return head;
}


node* delBST(node *root, int x)
{
    if(root==NULL)
    return NULL;
    else if(x<root->data)
    root->left=delBST(root->left,x);
    else if(x>root->data)
    root->right=delBST(root->right,x);
    else
    {
        if(root->right==NULL)
        {
            node *temp=root->left;
            delete root;   
            return temp;
        }
        else if(root->left==NULL)
        {
            node *temp=root->right;
            delete root;   
            return temp;
        }
        else
        {
            node *temp=largestBST(root->left);
            root->data=temp->data;
            root->left=delBST(root->left,temp->data);
            return root;
        }
    }
}

node* searchBST(node* head,int key)
{
if(head==NULL)
{
return head;
}
if(key<head->data)
{
return searchBST(head->left,key);
}
else if(key>head->data)
{
return searchBST(head->right,key);
}
else
{
return head;
}

}

void preOrder(node* head)
{
if(head!=NULL)
{
cout<<head->data<<" ";
preOrder(head->left);
preOrder(head->right);

}

}


void inOrder(node* head)
{
if(head!=NULL)
{

inOrder(head->left);
cout<<head->data<<" ";
inOrder(head->right);

}

}

void postOrder(node* head)
{
if(head!=NULL)
{

postOrder(head->left);
postOrder(head->right);
cout<<head->data<<" ";
}

}

};


int main()
{

node* head=NULL;
BST bst;
int choice,datain,delkey,searchkey;
bool status;
do
{
cout<<"What do you want to perform"<<endl;
cout<<"1.Insert newnode\n2.Delete node\n3.Search a node\n4.Find largest\n5.Find smallest\n6.PreOrder Traversal\n7.InOrder Traversal\n8.PostOrder Traversal\n9.Exit\n";
cin>>choice;

switch(choice)
{

case 1:cout<<"Enter Data"<<endl;
cin>>datain;
head=bst.addBST(head,datain);
break;

case 2:cout<<"Enter data"<<endl;
cin>>delkey;
node* l;
l=bst.delBST(head,delkey);
break;

case 3:cout<<"Enter Data"<<endl;
cin>>searchkey;
node* temp;
temp=bst.searchBST(head,searchkey);
if(temp!=NULL)
    cout<<"found at"<<temp;
else
    cout<<"Not found";

break;

case 4:node* tmp;
tmp=bst.largestBST(head);
cout<<"Largest is"<<tmp->data<<endl;
break;
case 5:node* t;
t=bst.smallestBST(head);
cout<<"Smallest is"<<t->data<<endl;
break;



case 6:bst.preOrder(head);
break;

case 7:bst.inOrder(head);
break;

case 8:bst.postOrder(head);
break;

case 9:
break;


}


}
while(choice!=9);



return 0;
}
