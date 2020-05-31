#include<iostream>
using namespace std;
void in(int n,int a[])
{
int i,j,k;
for(i=1;i<n;i++)
{
k=a[i];
for(j=i-1;j>=0&&k<a[j];j--)
{
a[j+1]=a[j];

}
a[j+1]=k;
}
for(i=0;i<n;i++)
cout<<a[i]<<" ";
}
int main()
{
int n,a[10],i;
cout<<"\nEnter the number of elements";
cin>>n;
cout<<"\nEnter the elements";
for(i=0;i<n;i++)
cin>>a[i];
in(n,a);
}
