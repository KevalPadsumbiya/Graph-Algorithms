#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[200001];
int vis[200001],n,m,edges,nodes;

void DFS(int src)
{
	vis[src]=1;
	nodes++;
	edges+=ar[src].size();
	for(int child : ar[src])
		if(vis[child]==0)
			DFS(child);
}
int main()
{
	fastio;
	int i,a,b,ans=0;
	cin>>n>>m;
	for(i=0;i<m;i++)
		cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			DFS(i);
			if(2*nodes-(edges/2)==nodes)
				ans++;
//			cout<<endl<<nodes<<" "<<edges/2<<endl;
			nodes=edges=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}

