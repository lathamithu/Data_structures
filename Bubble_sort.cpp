#include<iostream>
using namespace std;
void bub(int n,int a[],int i)
{
int flag=0,j;
for(i=0;i<=n&&flag==0;i++)
{
flag=1;
for(j=n;j>=i;--j)
{
if(a[j-1]>a[j])
{
flag=0;
int t=a[j];
a[j]=a[j-1];
a[j-1]=t;
}}}
for(i=0;i<=n;i++)
cout<<a[i]<<" ";
}

int main()
{
int n,a[10],i,flag=0;
cout<<"\nEnter the number of elements";
cin>>n;
cout<<"\nEnter the elements";
for(i=0;i<n;i++)
cin>>a[i];
bub(n,a,i);
}
