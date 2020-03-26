#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
int t;
cin>>t;

int num=1;
while (t--)
{
int n;
cin>>n;

int c;
cin>>c;

int i;
int a[n];
for (i=0;i<n;++i)
cin>>a[i];

sort(a,a+n);

int count=0,sum=0;
for (i=0;i<n;++i)
{
sum+= a[i];    

if (sum>c)
break;

else
count++;
}

cout<<"Case #"<<num<<":"<<" "<<count<<endl;
 num++;   
}
    
    return 0;
}