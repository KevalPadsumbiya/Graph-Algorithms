#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[10001];
int maxN,level[10001],LCA[10001][100];

void DFS(int src,int dist,int par)
{
	level[src]=dist;
	LCA[src][0]=par;
	
	for(int child : ar[src])
		if(child != par)	
			DFS(child,dist+1,src);
}

int findLca(int src,int dest)
{
	if(level[dest]<level[src])
		swap(src,dest);
	int d= level[dest]-level[src];
	
	while(d>0)
	{
		int i= log2(d);
		dest=LCA[dest][i];
		d-=1<<i;
	}
	if(src==dest)
		return src;
		
	for(int i=maxN;i>=0;i--)
		if(LCA[src][i]!=-1 && (LCA[src][i]!=LCA[dest][i]))
		{
			src=LCA[src][i] , dest=LCA[dest][i];
		}
	return LCA[src][0];
}
int main()
{
	fastio;
//	int t;
//	cin>>t;
//	while(t--)
//	{
		int n,m,q,i,j,a,b;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>m;
			while(m--)
				cin>>a , ar[i].pb(a) , ar[a].pb(i);
		}
		maxN = log2(n)+1;
		
		for(i=0;i<n;i++)
			for(j=0;j<=maxN;j++)
				LCA[i][j]=-1;
		
//		cout<<maxN<<endl;
		
		DFS(0,0,-1);
		
		cin>>q;
		while(q--)
		{
			cin>>a>>b;
			cout<<findLca(a,b)<<"\n";
		}
//	}
	return 0;
}

