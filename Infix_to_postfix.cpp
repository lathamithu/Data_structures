
#include<iostream>
using namespace std;
class stack
{
	int top;char a[20];
	public:
		stack()
		{
			top=-1;
		}
		void push(char x)
		{
			a[++top]=x;
		}
		char pop()
		{
			return a[top--];
		}
		char stacktop()
		{
			return a[top];
		}
		bool stackempty()
		{
			if(top==-1)
			return true;
			else 
			return false;
		}
};
int priority(char x)
{
	if(x=='^')
	return 3;
	else if(x=='*'||x=='/'||x=='%')
	return 2;
	else if(x=='+'||x=='-')
	return 1;
	else 
	return 0;
}
int main()
{
	char ch,tt,tout;
	stack s;
	string infix;
	char postfix[20];
	int l=0;
	cout<<"\nEnter infix: ";
	cin>>infix;
	for(int i=0;i<infix.size();i++)
	{
		ch=infix[i];
		if(ch=='(')
		s.push(ch);
		else if(ch==')')
		{
			ch=s.pop();
			while(ch!='(')
			{
				postfix[l++]=ch;
				ch=s.pop();
			}
		}
		else if(ch=='^'||ch=='*'||ch=='/'||ch=='%'||ch=='+'||ch=='-')
		{
			tt=s.stacktop();
			while(!s.stackempty()&&priority(ch)<=priority(tt))
			{
				tout=s.pop();
				postfix[l++]=tout;
				tt=s.stacktop();
			}
			s.push(ch);
		}
		else
		postfix[l++]=ch;
	}
	while(!s.stackempty())
    {
    	postfix[l++]=s.pop();
	}
	postfix[l]='\0';
	cout<<postfix;
}
