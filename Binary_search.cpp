#include<iostream>
using namespace std;

int main()
{
int n;
cout<<"Enter size:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
int t;
cout<<"Enter target:";
cin>>t;

int flag=0;
int m;
int b=0,l=n-1;
while(b<=l)
    {
    m=(b+l)/2;
    if(t>arr[m])
        b=m+1;
    else if(t==arr[m])
        {
        b=l+1;
        flag =1;       
        }
    else
        l=m-1;   
    }
if(flag == 1)
    cout<<"Location:"<<m+1;
else
    cout<<"Not found";
}
