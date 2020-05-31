
#include<iostream>
using namespace std;
void seq(int a[],int n,int k,int i)
{
for(i=0;i<n&&k!=a[i];i++){}
if(k==a[i])
cout<<"Found at "<<i+1;
else
cout<<"Not found";
}
int main()
{
int a[10],n,i,j,k;
cout<<"\nEnter the number of elements";
cin>>n;
cout<<"\nEnter the elements";
for(i=0;i<n;i++)
cin>>a[i];
cin>>k;
seq(a,n,k,i);
}
