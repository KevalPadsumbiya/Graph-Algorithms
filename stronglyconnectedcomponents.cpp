#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int vis[10001];
stack<int> s;
vector<int> ar[10001],ar1[10001];

void DFS(int src,vector<int> ar[])
{
	vis[src]=1;
	for(auto child : ar[src])
		if(vis[child]==0)
			DFS(child,ar);
	s.push(src);
}

int main()
{
	fastio;
	int n,m,a,b,i,scc=0;
	
	cin>>n>>m;
	
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);	// origional graph
		ar1[b].pb(a);	// transpose of given graph
	}
	
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			DFS(i,ar);
			
	memset(vis,0,sizeof(vis));
	
	while(!s.empty())
	{
		if(vis[s.top()]==0)
		{
			DFS(s.top(),ar1);
			scc++;
		}
		s.pop();
	}
	cout<<scc;
}
