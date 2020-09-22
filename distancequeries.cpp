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
int vis[200001],dist[200001];

void DFS(int src,int d)
{
	vis[src]=1;
	dist[src]=d;
	for(auto child : ar[src])	
		if(vis[child]==0)
			DFS(child,d+1);
}

int main()
{
	fastio;
	int n,q,i,a,b;
	cin>>n>>q;
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		ar[a].pb(a);
		ar[b].pb(a);
	}
	DFS(1,0);
	for(i=1;i<=n;i++)
	while(q--)
	{
		cin>>a>>b;
		cout<<abs(dist[a]-dist[b])<<"\n";
	}
	return 0;
}

