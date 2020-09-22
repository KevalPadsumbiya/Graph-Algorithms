#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

struct graph
{
	lli a,b,w;
};

int main()
{
	lli n,m,a,b,w,i,j;
	cin>>n>>m;
	
	vector<lli> dist(100001,mod);
	vector<graph> g(100001);
	
	for(i=0;i<m;i++)
	{
		cin>>g[i].a>>g[i].b>>g[i].w;
		g[i].a--;
		g[i].b--;
	}
		
	dist[0]=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m;j++)
		{
			if(dist[g[j].a]<mod)
			{
				if(dist[g[j].a]+g[j].w<dist[g[j].b])
					dist[g[j].b]=dist[g[j].a]+g[j].w;
			}
		}
	}
	
	bool change=false;
	for(j=0;j<m;j++)
	{
		if(dist[g[j].a]<mod)
		{
			if(dist[g[j].a]+g[j].w<dist[g[j].b])
			{
				dist[g[j].b]=dist[g[j].a]+g[j].w;
				change=true;
				break;
			}
		}
	}

	for(i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	if(change)
		cout<<1;
	else
		cout<<0;
}
