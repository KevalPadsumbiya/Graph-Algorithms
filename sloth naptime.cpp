#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[300001];
int lca[300001][23],dist[300001],maxN;

void DFS(int src,int par,int d)
{
	dist[src]=d;
	lca[src][0]=par;
	for(auto child : ar[src])
		if(child!=par)
			DFS(child,src,d+1);
}

int findLCA(int src,int dest)
{
	if(dist[src]>dist[dest])	
		swap(src,dest);
	int i,d=dist[dest]-dist[src];
	while(d)
	{
		i=log2(d);
		dest=lca[dest][i];
		d-=(1<<i);
	}
	if(src==dest)
		return src;
	for(i=maxN;i>=0;i--)
	{
		if(lca[src][i]!=-1 && (lca[src][i]!=lca[dest][i]))
		{
			src=lca[src][i];
			dest=lca[dest][i];
		}
	}
	return lca[src][0];
}

int findNthParent(int src,int n)
{
	int i;
	while(n)
	{
		i=log2(n);
		src=lca[src][i];
		n-=(1<<i);
	}
	return src;
}

int main()
{
	fastio;
	int n,q,a,b,i,j,c,distance,LCA,dist_LCA;

	cin>>n;

	maxN=log2(n)+1;

	for(i=0;i<n-1;i++)
		cin>>a>>b , ar[a].pb(b), ar[b].pb(a);
	
	for(j=0;j<=maxN;j++)
		for(i=1;i<=n;i++)
			lca[i][j]=-1;
					
	DFS(1,-1,0);
	
	for(j=1;j<=maxN;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(lca[i][j-1]!=-1)
			{
				LCA=lca[i][j-1];
				lca[i][j]=lca[LCA][j-1];
			}
		}
	}
	
	cin>>q;
	while(q--)
	{
		cin>>a>>b>>c;
		
		LCA=findLCA(a,b);
		distance=dist[a]+dist[b]-2*dist[LCA];
		
		if(distance<=c)
			cout<<b<<"\n";
		else if(c<=(dist[a]-dist[LCA]))
			cout<<findNthParent(a,c)<<"\n";	
		else
			cout<<findNthParent(b,distance-c)<<"\n";
	}	
	return 0;
}
