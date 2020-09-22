#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli sum;
lli par[100001];

lli find(lli a)
{
	if(par[a]<0)
		return a;
	return par[a]=find(par[a]);	
}

void Union(lli a,lli b)
{
	par[a]+=par[b];
	par[b]=a;
}

int main()
{
	fastio;
	lli t;
	cin>>t;
	while(t--)
	{
		sum=0;
		memset(par,-1,sizeof(par));
		lli n,m,a,b,i,j;
		cin>>n>>m;
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			a=find(a);
			b=find(b);
			if(a!=b)
			{	
				Union(a,b);
			sum+=(par[a]+1)*abs(par[a]);
		}
		cout<<abs(sum)<<"\n";
	}
	return 0;
}

