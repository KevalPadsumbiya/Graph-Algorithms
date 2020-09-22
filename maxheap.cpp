#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int a[100001],x,sorted;

void makeHEAP(int n)
{
	int i,j;
	while(sorted<x)
	{
		sorted=0;
	
		for(i=x;i>=1;i--)
		{
			if(2*i<=n && 2*i+1<=n)
			{
				if(a[i]<a[2*i] || a[i]<a[(2*i)+1])		 // all elements are distinct
				{
					if(a[2*i]>a[(2*i)+1])
						swap(a[i],a[2*i]);
					else
						swap(a[i],a[(2*i)+1]);
				}
			}
			else if(2*i<=n && 2*i+1>n)
			{
				if(a[2*i]>a[i])
					swap(a[i],a[2*i]);
			}
		}
	
		for(i=x;i>=1;i--)
			if(a[i]>a[2*i] && a[i]>a[(2*i)+1])
				sorted++;
	}
}

int main()
{
	fastio;
	
	int n,i,j;
	cin>>n;

	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>3)
		{
			cout<<"YES\n";
			x=i/2;
			makeHEAP(i);
			cout<<"YES1 "<<i<<endl;
			for(j=1;j<=i;j++)
				cout<<a[j]<<" ";
		}
	}
	
}
